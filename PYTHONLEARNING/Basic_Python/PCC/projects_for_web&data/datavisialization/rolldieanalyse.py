from random import randint 
from plotly.graph_objs import Bar,Layout
from plotly import offline
class Die :
    def __init__(self,num_sides = 6):
        self.num_sides = num_sides
    
    def roll(self):
        return randint(1,self.num_sides)


def main():
    die = Die(6)
    die2 = Die(6)
    roll_number = 1000
    results = []
    for rolltimes in range(roll_number):
        result = die.roll()+die2.roll()
        results.append(result)

    # print(results)
    frequencys = {}
    for value in range(1+1,die.num_sides+die2.num_sides+1):
        frequency = results.count(value)
        frequencys[value] = frequency
    print(frequencys)

    data = [Bar(x = list(frequencys.keys()), y = list(frequencys.values()))]
    xis_config = {'title':'Results','dtick' : 1}#如果没有dict = 1那么就是只会显示2，4，6，8，10，12，dtick就是每个都会显示
    yis_config = {'title':'Frequencys'}

    my_layout = Layout(title = "1000 times's roll for 2 dies",xaxis= xis_config,yaxis=yis_config)
    offline.plot({'data':data , 'layout' : my_layout},filename = 'rooooolldie.html')


main()
