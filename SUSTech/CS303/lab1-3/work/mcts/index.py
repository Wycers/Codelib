
from collections import deque
import tensorflow as tf
import numpy as np
import binascii
import random
import time
import copy

COLOR_BLACK = -1
COLOR_WHITE = 1
COLOR_NONE = 0

class AI(object):
    def __init__(self, chessboard_size, color, time_out, c_puct=5, n_playout=400):
        self.chessboard_size = chessboard_size
        self.color = color
        self.time_out = time_out
        self.candidate_list = []

        self.policy = PolicyValueNet(board_width=chessboard_size,board_height=chessboard_size,block=19,cuda=True)
        self.mcts = MCTS(self.policy.policy_value_fn, c_puct=c_puct, n_playout=n_playout)
        self.mcts.update_with_move(-1)

        self.board = Board()
        self.board.init_board()

    def go(self, chessboard):
        now = list(chessboard.ravel())
        black = []
        white = []

        for i in range(len(now)):
            if now[i] == COLOR_BLACK and i in self.board.availables:
                black.append(i)

            if now[i] == COLOR_WHITE and i in self.board.availables:
                white.append(i)

        print(black, white)

        if len(white) == len(black) + 1:
            for i in range(0, len(black)):
                self.board.do_move(white[i])
                self.mcts.update_with_move(white[i])
                self.board.do_move(black[i])
                self.mcts.update_with_move(black[i])
            self.board.do_move(white[-1])
        elif len(black) == len(white) + 1:
            for i in range(0, len(white)):
                self.board.do_move(black[i])
                self.mcts.update_with_move(black[i])
                self.board.do_move(white[i])
                self.mcts.update_with_move(white[i])
            self.board.do_move(black[-1])
        elif len(black) == len(white):
            if len(black) != 0:
                for i in range(0, len(white) - 1):
                    self.board.do_move(black[i])
                    self.mcts.update_with_move(black[i])
                    self.board.do_move(white[i])
                    self.mcts.update_with_move(white[i])
                self.board.do_move(black[-1])
                self.mcts.update_with_move(black[-1])

                self.board.do_move(white[-1])
        else:
            raise Exception("Wrong chessboard!!")

        move, prob = self.get_action()
        self.board.do_move(move)
        # print(prob.reshape(15, 15))
        self.candidate_list.append((move // self.chessboard_size, move % self.chessboard_size))

    def get_action(self):
        '''
        get an action by mcts
        '''
        sensible_moves = self.board.availables
        # the pi vector returned by MCTS as in the alphaGo Zero paper
        move_probs = np.zeros(self.chessboard_size * self.chessboard_size)
        if len(sensible_moves) > 0:
            # update the tree with opponent's move and then do mcts from the new node
            self.mcts.update_with_move(self.board.last_move)
            acts, visits = self.mcts.get_move_visits(self.board)
            temp = 1e-3
            # always choose the most visited move
            probs = softmax(1.0 / temp * np.log(np.array(visits) + 1e-10))
            move = np.random.choice(acts, p=probs)

            self.mcts.update_with_move(move)
            # update the tree with self move

            p = softmax(1.0 / 1.0 * np.log(np.array(visits) + 1e-10))
            move_probs[list(acts)] = p

            return move, move_probs
        else:
            print("WARNING: the board is full")

    def __str__(self):
        return "Alpha {}".format(self.player)


class Board(object):
    '''
    hold states of the game, include board and current_player
    '''

    def __init__(self, chessboard_size=15, n_in_row=5):
        self.size = chessboard_size
        self.states = {}
        # board states stored as a dict,
        # key: move as location on the board,
        # value: player as pieces type
        self.n_in_row = n_in_row
        # need how many pieces in a row to win
        self.players = [1, 2]
        # player1 and player2

        self.feature_planes = 8
        # how many binary feature planes we use,
        # in alphago zero is 17 and the input to the neural network is 19x19x17
        # here is a (self.feature_planes+1) x self.width x self.height binary feature planes,
        # the self.feature_planes is the number of history features
        # the additional plane is the color feature that indicate the current player
        # for example, in 11x11 board, is 11x11x9,8 for history features and 1 for current player
        self.states_sequence = deque(maxlen=self.feature_planes)
        self.states_sequence.extendleft([[-1, -1]] * self.feature_planes)
        #use the deque to store last 8 moves
        # fill in with [-1,-1] when one game start to indicate no move

    def init_board(self, states={}, start_player=0):
        '''
        init the board and set some variables
        '''
        if self.size < self.n_in_row:
            raise Exception('Size can not be less than {}'.format(self.n_in_row))
        self.current_player = self.players[start_player]  # start player
        self.availables = list(range(self.size * self.size))
        # keep available moves in a list
        # once a move has been played, remove it right away
        self.states = states
        self.last_move = -1

        self.states_sequence = deque(maxlen=self.feature_planes)
        self.states_sequence.extendleft([[-1, -1]] * self.feature_planes)


    def current_state(self):
        '''
        return the board state from the perspective of the current player.
        state shape: (self.feature_planes+1) x width x height
        '''
        square_state = np.zeros((self.feature_planes+1, self.size, self.size))
        if self.states:
            moves, players = np.array(list(zip(*self.states.items())))
            move_curr = moves[players == self.current_player]
            move_oppo = moves[players != self.current_player]
            # to construct the binary feature planes as alphazero did
            for i in range(self.feature_planes):
                # put all moves on planes
                if i % 2 == 0:
                    square_state[i][move_oppo // self.size,
                                    move_oppo % self.size] = 1.0
                else:
                    square_state[i][move_curr // self.size,
                                    move_curr % self.size] = 1.0
            # delete some moves to construct the planes with history features
            for i in range(0, len(self.states_sequence)-2, 2):
                for j in range(i+2, len(self.states_sequence), 2):
                    if self.states_sequence[i][1] != -1:
                        assert square_state[j][self.states_sequence[i][0] // self.size,
                                               self.states_sequence[i][0] % self.size] == 1.0, 'wrong oppo number'
                        square_state[j][self.states_sequence[i][0] // self.size,
                                        self.states_sequence[i][0] % self.size] = 0.
            for i in range(1, len(self.states_sequence)-2, 2):
                for j in range(i+2, len(self.states_sequence), 2):
                    if self.states_sequence[i][1] != -1:
                        assert square_state[j][self.states_sequence[i][0] // self.size,
                                               self.states_sequence[i][0] % self.size] == 1.0, 'wrong player number'
                        square_state[j][self.states_sequence[i][0] // self.size,
                                        self.states_sequence[i][0] % self.size] = 0.

        if len(self.states) % 2 == 0:
            # if %2==0，it's player1's turn to player,then we assign 1 to the the whole plane,otherwise all 0
            # indicate the colour to play
            square_state[self.feature_planes][:, :] = 1.0

        return square_state[:, ::-1, :]

    def do_move(self, move):
        '''
        update the board
        '''
        # print(self.states,move,self.current_player,self.players)
        self.states[move] = self.current_player
        # save the move in states
        self.states_sequence.appendleft([move, self.current_player])
        # save the last some moves in deque，so as to construct the binary feature planes
        self.availables.remove(move)
        #remove the played move from self.availables
        self.current_player = (
            self.players[0] if self.current_player == self.players[1]
            else self.players[1]
        )
        # change the current player
        self.last_move = move

    def has_a_winner(self):
        '''
        judge if there's a 5-in-a-row, and which player if so
        '''
        width = self.size
        height = self.size
        states = self.states
        n = self.n_in_row

        moved = list(set(range(width * height)) - set(self.availables))
        # moves have been played
        if len(moved) < self.n_in_row + 2:
            # too few moves to get 5-in-a-row
            return False, -1

        for m in moved:
            h = m // width
            w = m % width
            player = states[m]

            if (w in range(width - n + 1) and
                    len(set(states.get(i, -1) for i in range(m, m + n))) == 1):
                # for each move in moved moves,judge if there's a 5-in-a-row in a line
                return True, player

            if (h in range(height - n + 1) and
                    len(set(states.get(i, -1) for i in range(m, m + n * width, width))) == 1):
                # for each move in moved moves,judge if there's a 5-in-a-row in a column
                return True, player

            if (w in range(width - n + 1) and h in range(height - n + 1) and
                    len(set(states.get(i, -1) for i in range(m, m + n * (width + 1), width + 1))) == 1):
                # for each move in moved moves,judge if there's a 5-in-a-row in a top right diagonal
                return True, player

            if (w in range(n - 1, width) and h in range(height - n + 1) and
                    len(set(states.get(i, -1) for i in range(m, m + n * (width - 1), width - 1))) == 1):
                # for each move in moved moves,judge if there's a 5-in-a-row in a top left diagonal
                return True, player

        return False, -1

    def game_end(self):
        '''
        Check whether the game is end
        '''
        end, winner = self.has_a_winner()
        if end:
            # if one win,return the winner
            return True, winner
        elif not len(self.availables):
            # if the board has been filled and no one win ,then return -1
            return True, -1
        return False, -1

    def get_current_player(self):
        '''
        return current player
        '''
        return self.current_player


def softmax(x):
    probs = np.exp(x - np.max(x))
    # https://mp.weixin.qq.com/s/2xYgaeLlmmUfxiHCbCa8dQ
    # awesome function avoid float overflow and underflow
    probs /= np.sum(probs)
    return probs


class TreeNode(object):
    '''
    A node in the MCTS tree.
    Each node keeps track of its own value Q, prior probability P, and
    its visit-count-adjusted prior score u.
    '''

    def __init__(self, parent, prior_p):
        self._parent = parent
        self._children = {}  # a map from action to TreeNode
        self._n_visits = 0
        self._Q = 0
        self._u = 0
        self._P = prior_p  # its the prior probability that action's taken to get this node

    def expand(self, action_priors, add_noise):
        '''
        Expand tree by creating new children.
        action_priors: a list of tuples of actions and their prior probability
            according to the policy function.
        '''
        # when train by self-play, add dirichlet noises in each node

        # should note it's different from paper that only add noises in root node
        # i guess alphago zero discard the whole tree after each move and rebuild a new tree, so it's no conflict
        # while here i contained the Node under the chosen action, it's a little different.
        # there's no idea which is better
        # in addition, the parameters should be tried
        # for 11x11 board,
        # dirichlet parameter :0.3 is ok, should be smaller with a bigger board,such as 20x20 with 0.03
        # weights between priors and noise: 0.75 and 0.25 in paper and i don't change it here,
        # but i think maybe 0.8/0.2 or even 0.9/0.1 is better because i add noise in every node
        # rich people can try some other parameters
        if add_noise:
            action_priors = list(action_priors)
            length = len(action_priors)
            dirichlet_noise = np.random.dirichlet(0.3 * np.ones(length))
            for i in range(length):
                if action_priors[i][0] not in self._children:
                    self._children[action_priors[i][0]] = TreeNode(
                        self, 0.75*action_priors[i][1]+0.25*dirichlet_noise[i])
        else:
            for action, prob in action_priors:
                if action not in self._children:
                    self._children[action] = TreeNode(self, prob)

    def select(self, c_puct):
        '''
        Select action among children that gives maximum action value Q plus bonus u(P).
        Return: A tuple of (action, next_node)
        '''
        return max(self._children.items(),
                   key=lambda act_node: act_node[1].get_value(c_puct))

    def update(self, leaf_value):
        '''
        Update node values from leaf evaluation.
        leaf_value: the value of subtree evaluation from the current player's
            perspective.
        '''
        self._n_visits += 1
        # update visit count
        self._Q += 1.0*(leaf_value - self._Q) / self._n_visits
        # Update Q, a running average of values for all visits.
        # there is just: (v-Q)/(n+1)+Q = (v-Q+(n+1)*Q)/(n+1)=(v+n*Q)/(n+1)

    def update_recursive(self, leaf_value):
        '''
        Like a call to update(), but applied recursively for all ancestors.
        '''
        # If it is not root, this node's parent should be updated first.
        if self._parent:
            self._parent.update_recursive(-leaf_value)
            # every step for revursive update,
            # we should change the perspective by the way of taking the negative
        self.update(leaf_value)

    def get_value(self, c_puct):
        '''
        Calculate and return the value for this node.
        It is a combination of leaf evaluations Q, and this node's prior
        adjusted for its visit count, u.
        c_puct: a number in (0, inf) controlling the relative impact of
            value Q, and prior probability P, on this node's score.
        '''
        self._u = (c_puct * self._P *
                   np.sqrt(self._parent._n_visits) / (1 + self._n_visits))
        return self._Q + self._u

    def is_leaf(self):
        '''
        check if leaf node (i.e. no nodes below this have been expanded).
        '''
        return self._children == {}

    def is_root(self):
        '''
        check if it's root node
        '''
        return self._parent is None


class MCTS(object):
    '''
    An implementation of Monte Carlo Tree Search.
    '''

    def __init__(self, policy_value_fn, c_puct=5, n_playout=400):
        '''
        policy_value_fn: a function that takes in a board state and outputs
            a list of (action, probability) tuples and also a score in [-1, 1]
            (i.e. the expected value of the end game score from the current
            player's perspective) for the current player.
        c_puct: a number in (0, inf) that controls how quickly exploration
            converges to the maximum-value policy. A higher value means
            relying on the prior more.
        '''
        self._root = TreeNode(None, 1.0)
        # root node do not have parent ,and sure with prior probability 1
        self._policy_value_fn = policy_value_fn
        self._c_puct = c_puct
        # it's 5 in paper and don't change here,but maybe a better number exists in gomoku domain
        self._n_playout = n_playout  # times of tree search

    def _playout(self, state):
        '''
        Run a single playout from the root to the leaf, getting a value at
        the leaf and propagating it back through its parents.
        State is modified in-place, so a copy must be provided.
        '''
        node = self._root
        # print('============node visits:',node._n_visits)
        # deep = 0
        while(1):
            if node.is_leaf():
                break
            # Greedily select next move.
            action, node = node.select(self._c_puct)
            # print('move in tree...',action)
            state.do_move(action)
            # deep+=1
        # print('-------------deep is :',deep)

        # Evaluate the leaf using a network which outputs a list of
        # (action, probability) tuples p and also a score v in [-1, 1]
        # for the current player.
        action_probs, leaf_value = self._policy_value_fn(state)
        # Check for end of game.
        end, winner = state.game_end()
        if not end:
            # print('expand move:',state.width*state.height-len(state.availables),node._n_visits)
            node.expand(action_probs, add_noise=False)
        else:
            # for end state，return the "true" leaf_value
            # print('end!!!',node._n_visits)
            if winner == -1:  # tie
                leaf_value = 0.0
            else:
                leaf_value = (
                    1.0 if winner == state.get_current_player() else -1.0
                )

        # Update value and visit count of nodes in this traversal.
        node.update_recursive(-leaf_value)
        # no rollout here

    def get_move_visits(self, state):
        '''
        Run all playouts sequentially and return the available actions and
        their corresponding visiting times.
        state: the current game state
        '''
        for n in range(self._n_playout):
            # print('playout:',n)
            state_copy = copy.deepcopy(state)
            self._playout(state_copy)

        # calc the visit counts at the root node
        act_visits = [(act, node._n_visits)
                      for act, node in self._root._children.items()]
        acts, visits = zip(*act_visits)

        return acts, visits

    def update_with_move(self, last_move):
        '''
        Step forward in the tree, keeping everything we already know
        about the subtree.
        '''
        if last_move in self._root._children:
            self._root = self._root._children[last_move]
            self._root._parent = None
        else:
            self._root = TreeNode(None, 1.0)


class PolicyValueNet():
    def __init__(self, board_width, board_height, block):
        self.planes_num = 9  # feature planes
        self.nb_block = block  # resnet blocks

        self.board_width = board_width
        self.board_height = board_height


    def calculate(self, state_batch):
        with tf.Graph().as_default():
            out, b = self.sess.run([self.action_fc, self.evaluation_fc2], feed_dict={
                                   self._input: state_batch})
            return out, b

    def policy_value(self, state_batch):
        '''
        input: a batch of states,actin_fc,evaluation_fc
        output: a batch of action probabilities and state values
        '''
        log_act_probs, value = self.calculate(state_batch)
        act_probs = np.exp(log_act_probs)
        return act_probs, value

    def policy_value_fn(self, board):
        '''
        input: board,actin_fc,evaluation_fc
        output: a list of (action, probability) tuples for each available
        action and the score of the board state
        '''
        # the accurate policy value fn,
        # i prefer to use one that has some randomness even when test,
        # so that each game can play some different moves, all are ok here
        legal_positions = board.availables
        current_state = np.ascontiguousarray(board.current_state().reshape(
            -1, self.planes_num, self.board_width, self.board_height))
        act_probs, value = self.policy_value(current_state)
        act_probs = zip(legal_positions, act_probs[0][legal_positions])
        return act_probs, value

    def policy_value_fn_random(self, board, actin_fc, evaluation_fc):
        '''
        input: board,actin_fc,evaluation_fc
        output: a list of (action, probability) tuples for each available
        action and the score of the board state
        '''
        # like paper said,
        # The leaf node sL is added to a queue for neural network
        # evaluation, (di(p), v) = fθ(di(sL)),
        # where di is a dihedral reflection or rotation
        # selected uniformly at random from i in [1..8]

        legal_positions = board.availables
        current_state = np.ascontiguousarray(board.current_state().reshape(
            -1, self.planes_num, self.board_width, self.board_height))

        # print('current state shape',current_state.shape)

        #add dihedral reflection or rotation
        rotate_angle = np.random.randint(1, 5)
        flip = np.random.randint(0, 2)
        equi_state = np.array([np.rot90(s, rotate_angle)
                               for s in current_state[0]])
        if flip:
            equi_state = np.array([np.fliplr(s) for s in equi_state])
        # print(equi_state.shape)

        # put equi_state to network
        act_probs, value = self.policy_value(
            np.array([equi_state]), actin_fc, evaluation_fc)

        # get dihedral reflection or rotation back
        equi_mcts_prob = np.flipud(act_probs[0].reshape(
            self.board_height, self.board_width))
        if flip:
            equi_mcts_prob = np.fliplr(equi_mcts_prob)
        equi_mcts_prob = np.rot90(equi_mcts_prob, 4 - rotate_angle)
        act_probs = np.flipud(equi_mcts_prob).flatten()

        act_probs = zip(legal_positions, act_probs[legal_positions])
        return act_probs, value


if __name__ == "__main__":
    SB = AI(15, -1, 5)
    chessboard = np.zeros(
        (15, 15), dtype=np.int)
    chessboard[2, 2:4] = 1
    chessboard[4, 1:3] = 1
    chessboard[1, 10:12] = -1
    chessboard[2, 10] = -1
    chessboard[4, 12] = -1
    print(chessboard)
    SB.go(chessboard)
    print(SB.candidate_list)
