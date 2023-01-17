import matplotlib.pyplot as plt
import csv
import datetime as dt


def main():

    filename = ''

    with open(filename) as f:
        file_obj = csv.reader(f)
        head = csv.next(file_obj)
        print(head)

        dates = []
        highs = []
        lows = []
        rains = []
        snows = []
        for line in file_obj:
            high



    plt.style.use("seaborn")
    fig,ax = plt.subplots()
    ax.plot(dates,highs,c = 'red')
    ax.plot(dates,lows,c = 'blue')
    




main()

