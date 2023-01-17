import matplotlib.pyplot as plt
from random import choice 

class RandomWalk:
    def __init__(self,walknumber):
        self.xvalue = [0]
        self.yvalue = [0]
        self.walknumber = walknumber
    
    def walking(self):
        while(len(self.xvalue) < self.walknumber):
            distance = [0,1,2,3,4,5]
            direction = [-1,1]
            x_distance = choice(distance)
            y_distance = choice(distance)

            x_direction = choice(direction)
            y_direction = choice(direction)

            x_step = x_direction * x_distance
            y_step = y_direction * y_distance
            
            if x_step == 0 and y_step == 0:
                continue

            x = self.xvalue[-1] + x_step
            y = self.yvalue[-1] + y_step
            
            self.xvalue.append(x)
            self.yvalue.append(y)


def main():
    number = 50000
    rw = RandomWalk(number)
    rw.walking()

    plt.style.use("seaborn")
    fig,ax = plt.subplots(figsize = (15,9),dpi = 128)#设置分辨率和屏幕大小
    ax.scatter(rw.xvalue[0],rw.yvalue[0],s =2,color = 'green')
    ax.scatter(rw.xvalue[1:-1],rw.yvalue[1:-1],s =1,c = list(range(number-2)) , cmap = 'jet',edgecolors = 'black')
    ax.scatter(rw.xvalue[-1],rw.yvalue[-1],s =2,color = 'red')
    plt.show()

main()