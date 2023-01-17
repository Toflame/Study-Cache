from random import randint,choice

class Die:
    def __init__(self):
        self.sides = [1,2,3,4,5,6]
    def roll_die(self):
        i = choice(self.sides)
        print('You got a {}!'.format(i))
        return i
    def defsides(self):
        self.sides = list(range(int(input('您的骰子想要有几个面？'))))

my_die6 = Die()
my_die6.roll_die()
your_die10 = Die()
your_die10.defsides()
your_die10.roll_die()
