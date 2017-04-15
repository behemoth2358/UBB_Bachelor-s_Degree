'''
Created on Dec 22, 2016

@author: bogdan
'''
from domain.rental import *
from repo.RepositoryException import *

class RentalRepository:
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
    
    def add(self,ID,bookID,clientID,rentedDate,dueDate,returnedDate="Not returned yet"):
        if(self.__isAvailable(ID)==False):
            raise RepositoryException("ID="+str(ID)+" is already used!")
        if(self.__isRented(bookID,rentedDate)==True):
            raise RepositoryException("Book is rented")
        self.__arr.append(rental(ID,bookID,clientID,rentedDate,dueDate,returnedDate))
        
    def __str__(self):
        s=""
        for it in self.__arr:
            s+=str(it)
            s+='\n'
        if(s==""):
            s="The list is empty!\n"
        return s
    
    def __isAvailable(self,ID):
        for it in self.__arr:
            if(it.getID()==ID):
                return False
        return True
    
    def __isRented(self,bookID,rentedDate):
        for it in self.__arr:
            if(bookID==it.getBookID() and it.getRentedDate()<=rentedDate and (it.getReturnedDate()=="Not returned yet" or it.getReturnedDate()>rentedDate)):                         
                return True
        return False