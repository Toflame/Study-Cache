import unittest
from ElevenOnecityandcountry import citycountry


class ccTest(unittest.TestCase):
    def test_Test(self):
        i = citycountry('beijing','china')
        self.assertEqual(i,'Beijing,China')
    def test_Testpopulation(self):
        i = citycountry("beijing",'china',20000000)
        self.assertEqual(i,'Beijing,China - Population 20000000')
if __name__ == '__main__':
    unittest.main()

