'''
Created on Dec 20, 2016

@author: bogdan
'''
import unittest
from repo.repository import *

class TestRepo(unittest.TestCase):
    def setUp(self):
        self.__driversRepo=DriverRepository()
        self.__ordersRepo=OrderRepository()
    
    def test_addDriver(self):
        self.__driversRepo.add("1","1")
        self.assertEquals(len(self.__driversRepo),1)
    
    def test_addOrder(self):
        self.__ordersRepo.add("1",2)
        self.assertEquals(len(self.__ordersRepo),1)