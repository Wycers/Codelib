from collections import deque
import numpy as np


class Board(object):
    """
    board for the game
    """

    def __init__(self, **kwargs):
        self.width = int(kwargs.get('width', 11))
        self.height = int(kwargs.get('height', 11))
        self.states = {}
        # board states stored as a dict,
        # key: move as location on the board,
        # value: player as pieces type
        self.n_in_row = int(kwargs.get('n_in_row', 5))
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
        # use the deque to store last 8 moves
        # fill in with [-1,-1] when one game start to indicate no move

    def init_board(self, start_player=0):
        """
        init the board and set some variables
        """
        if self.width < self.n_in_row or self.height < self.n_in_row:
            raise Exception('board width and height can not be '
                            'less than {}'.format(self.n_in_row))
        self.current_player = self.players[start_player]  # start player
        self.availables = list(range(self.width * self.height))
        # keep available moves in a list
        # once a move has been played, remove it right away
        self.states = {}
        self.last_move = -1

        self.states_sequence = deque(maxlen=self.feature_planes)
        self.states_sequence.extendleft([[-1, -1]] * self.feature_planes)

    def move_to_location(self, move):
        """
        transfer move number to coordinate

        3*3 board's moves like:
        6 7 8
        3 4 5
        0 1 2
        and move 5's location is (1,2)
        """
        h = move // self.width
        w = move % self.width
        return [h, w]

    def location_to_move(self, location):
        """
        transfer coordinate to move number
        """
        if len(location) != 2:
            return -1
        h = location[0]
        w = location[1]
        move = h * self.width + w
        if move not in range(self.width * self.height):
            return -1
        return move

    def current_state(self):
        """
        return the board state from the perspective of the current player.
        state shape: (self.feature_planes+1) x width x height
        """
        square_state = np.zeros((self.feature_planes + 1, self.width, self.height))
        if self.states:
            moves, players = np.array(list(zip(*self.states.items())))
            # states contain the (key,value) indicate (move,player)
            # for example
            # self.states.items() get dict_items([(1, 1), (2, 1), (3, 2)])
            # zip(*) get [(1, 2, 3), (1, 1, 2)]
            # then np.array and get
            # moves = np.array([1, 2, 3])
            # players = np.array([1, 1, 2])
            move_curr = moves[players == self.current_player]
            move_oppo = moves[players != self.current_player]

            # to construct the binary feature planes as alphazero did
            for i in range(self.feature_planes):
                # put all moves on planes
                if i % 2 == 0:
                    square_state[i][move_oppo // self.width, move_oppo % self.height] = 1.0
                else:
                    square_state[i][move_curr // self.width, move_curr % self.height] = 1.0
            # delete some moves to construct the planes with history features
            for i in range(0, len(self.states_sequence) - 2, 2):
                for j in range(i + 2, len(self.states_sequence), 2):
                    if self.states_sequence[i][1] != -1:
                        assert square_state[j][self.states_sequence[i][0] // self.width, self.states_sequence[i][
                            0] % self.height] == 1.0, 'wrong oppo number'
                        square_state[j][
                            self.states_sequence[i][0] // self.width, self.states_sequence[i][0] % self.height] = 0.
            for i in range(1, len(self.states_sequence) - 2, 2):
                for j in range(i + 2, len(self.states_sequence), 2):
                    if self.states_sequence[i][1] != -1:
                        assert square_state[j][self.states_sequence[i][0] // self.width, self.states_sequence[i][
                            0] % self.height] == 1.0, 'wrong player number'
                        square_state[j][
                            self.states_sequence[i][0] // self.width, self.states_sequence[i][0] % self.height] = 0.

        if len(self.states) % 2 == 0:
            # if %2==0，it's player1's turn to player,then we assign 1 to the the whole plane,otherwise all 0
            square_state[self.feature_planes][:, :] = 1.0  # indicate the colour to play

        # we should reverse it before return,for example the board is like
        # 0,1,2,
        # 3,4,5,
        # 6,7,8,
        # we will change it like
        # 6 7 8
        # 3 4 5
        # 0 1 2
        return square_state[:, ::-1, :]

    def do_move(self, move):
        """
        update the board
        """
        # print(self.states,move,self.current_player,self.players)
        self.states[move] = self.current_player
        # save the move in states
        self.states_sequence.appendleft([move, self.current_player])
        # save the last some moves in deque，so as to construct the binary feature planes
        self.availables.remove(move)
        # remove the played move from self.availables
        self.current_player = (
            self.players[0] if self.current_player == self.players[1]
            else self.players[1]
        )
        # change the current player
        self.last_move = move

    def has_a_winner(self):
        """
        judge if there's a 5-in-a-row, and which player if so
        """
        width = self.width
        height = self.height
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
        """
        Check whether the game is end
        """
        end, winner = self.has_a_winner()
        if end:
            # if one win,return the winner
            return True, winner
        elif not len(self.availables):
            # if the board has been filled and no one win ,then return -1
            return True, -1
        return False, -1

    def get_current_player(self):
        """
        return current player
        """
        return self.current_player
