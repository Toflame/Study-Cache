
import unittest
from Employee import employee

class employeetest(unittest.TestCase):
    def setUp(self) :
        firstname = 'Jo'
        lastname = 'Jo'
        salary = 10000
        self.anemployee = employee(firstname,lastname,salary)
        self.costom = [1000,2000,6000]
        
        
    def test_give_default_raise(self):
        self.anemployee.giveraise('')
        self.assertEqual(self.anemployee.salary,15000)

    def test_give_custom_raise(self):
        for i in self.costom:
            self.anemployee.salary = 10000
            self.anemployee.giveraise(i)
            self.assertEqual(self.anemployee.salary,10000+i)


if __name__ == '__main__':
    unittest.main()
