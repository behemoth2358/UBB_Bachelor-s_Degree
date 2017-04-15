'''
Created on Dec 22, 2016

@author: bogdan
'''
from domain.client import *
from repo.RepositoryException import *

class ClientRepository:
    def __init__(self):
        self.__arr=[]
        
    def __len__(self):
        return len(self.__arr)
    
    def get(self,ind):
        return self.__arr[ind]
    
    def getAll(self):
        return self.__arr
    
    def delete(self,ind):
        self.__arr.pop(ind)
    
    def add(self,ID,name):
        if(self.isAvailable(ID)==False):
            raise RepositoryException("ID="+str(ID)+" is already used!")
        self.__arr.append(client(ID,name))
        
    def __str__(self):
        s=""
        for it in self.__arr:
            s+=str(it)
            s+='\n'
        if(s==""):
            s="The list is empty!\n"
        return s
    
    def isAvailable(self,ID):
        for it in self.__arr:
            if(it.getID()==ID):
                return False
        return True