#exe9.1.1+9.2.4
class taste:
    def __init__(self):
        self.tas = ['甜','不辣','微辣','中辣','特辣']
    def chooseyourtaste(self):
        print(self.tas)         
    def add_tas(self):
        i = input('add your taste in to the list')
        self.tas.append(i)
        self.chooseyourtaste()
class Restaurant:
    def __init__ (self,name,cuisinetype,cirtificate):
        self.name = name
        self.cuisinetype = cuisinetype
        self.eatingnum = 0
        self.cirtificate = cirtificate
    def describe_res(self):
        print("This is a restaurant named "f'{self.name}'+"and has a cuisnetype of " f"{self.cuisinetype}")
    def open_res(self):
        print("Welcome,"f"{self.name}" "is open!")

    def number_served(self,eatingnum):
        self.eatingnum = eatingnum
        print(f'{self.eatingnum}' " eating!")

    def incr_number(self,incre):
        self.eatingnum += incre
        print(f'{self.eatingnum}' " eating!")
    
    def prcirtificate(self):
        print('we ' f"{self.cirtificate}" "cirtificate")


class xiaochi(Restaurant):#继承一个类
    def __init__(self,name,cuisinetype,cirtificate):
        super().__init__(name,cuisinetype,cirtificate)
        self.menu = ['肉夹馍','驴肉火烧','炸鸡柳','咖喱饭']
        self.tas = taste()

    def prcirtificate(self):
        print("are you joking?")
    
    def prmenu(self):
        print(self.menu)
        
chinese_res =Restaurant ("Delicious dumplings ","Traditional chinese food ",'GOT')
chinese_res.open_res()
chinese_res.describe_res() 
chinese_res.number_served(5)
chinese_res.incr_number(3)

britain_res =Restaurant ("Fish&Chips ","Classic england food ",'GOT')
britain_res.open_res()
britain_res.describe_res() 

franch_res =Restaurant ("Paris night ","Upscale french food ",'GOT')
franch_res.open_res()
franch_res.describe_res() 

shaxian_xc = xiaochi('shaxianxiaochi','snacks','no')
shaxian_xc.prcirtificate()
shaxian_xc.prmenu()
shaxian_xc.tas.add_tas()
