'''
Created on Dec 20, 2016

@author: bogdan
'''
from domain.entities import *

class RepoError(Exception):
    def __init__(self,msg):
        self.__msg=msg
    def __str__(self):
        return self.__msg
    
class DriverRepository:
    def __init__(self):
        self.__arr=[]
    
    def add(self,ID,name):#adds a driver to the list
        if(self.srch(ID)==True):
            raise RepoError("ID unavailable!")    
        self.__arr.append(Driver(ID,name))
        
    def srch(self,ID):#searches for a driver with a given ID
        for it in self.__arr:
            if(it.getID()==ID):
                return True
        return False
    
    def getAll(self):#returns the list of all drivers
        return self.__arr
    
    def __len__(self):#the number of drivers
        return len(self.__arr)
    
    def __str__(self):
        s=""
        for it in self.__arr:
            s+=str(it)
            s+="\n"
        return s
            
    def get(self,index):
        return self.__arr[index]
    
class OrderRepository:
    def __init__(self):
        self.__arr=[]
    
    def __str__(self):
        s=""
        for it in self.__arr:
            s+=str(it)
            s+="\n"
        return s
    
    def add(self,ID,dist):#adds an order to the list
        if(dist < 1):
            raise RepoError("Distance or ID!")
        self.__arr.append(Order(ID,dist))
        
    def getAll(self):#returns all orders
        return self.__arr
    
    def __len__(self):#the number of orders
        return len(self.__arr)
    
    def get(self,index):
        return self.__arr[index]