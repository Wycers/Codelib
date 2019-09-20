import random

MAX_ROUND = 1000
AVALIABLE_CHOICES = [-5, -4, -3, -2, -1, 0, 1, 2, 3]

class Node(object):
    def __init__(self):
        self.parent = None
        self.children = []

        self.visited = 0
        self.value = 0.0

        self.state = None

class State(object):
    def __init__(self):
        self.current_value = 0.0
        self.current_round = 0
        self.cumulative_choices = []

    def is_terminal(self):
        return self.current_round == MAX_ROUND - 1

    def compute_reward(self):
        return -abs(1 - self.current_value)

    def get_next_state_with_random_choice(self):
        random_choice = random.choice([choice for choice in AVALIABLE_CHOICES])

        next_state = State()
        next_state.current_value = self.current_value + random_choice
        next_state.current_round = self.current_round + 1
        next_state.cumulative_choices = self.cumulative_choices + [random_choice]
