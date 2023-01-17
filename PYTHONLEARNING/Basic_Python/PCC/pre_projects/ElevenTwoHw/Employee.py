class employee:
    def __init__(self,first,last,salary):
        self.firstname = first
        self.lastname = last
        self.salary = salary
    def giveraise(self,araise):
        if araise != '':
            self.salary += araise
        else :
            self.salary += 5000
        return self.salary
        
