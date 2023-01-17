from msilib.schema import TextStyle
from turtle import color
import matplotlib.pyplot as plt

testy = [1,4,9,16,25,36]
testx = [1,2,3,4,5,6]

style = plt.style.available

for i in style:
    plt.style.use('{}'.format(i))
    plt.figure(figsize=(5, 2.7), layout='constrained')
    s0 = plt.plot(testx, testy,label = 'test') 
    plt.title("Graphstyle{}".format(i),color = 'blue')  # Add a title to the axes.
    plt.legend();  # Add a legend.
    plt.show()