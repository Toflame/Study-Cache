from msilib.schema import TextStyle
from turtle import color
import matplotlib.pyplot as plt


testx = list(range(1000))
testy = [x**2 for x in testx]
style = plt.style.available

for i in plt.colormaps():
    #plt.style.use('seaborn')
    #plt.figure(figsize=(5, 2.7), layout='constrained')
    plt.title("Graphstyle{}".format(i),color = 'blue')  # Add a title to the axes.
    #plt.scatter(testx,testy,c = testy,cmap = plt.cm.Blues,s = 10)
    plt.scatter(testx,testy,c = testx, cmap = i,s = 10)
    # plt.savefig('{}'.format(i),bbox_inches = 'tight')
    plt.show()