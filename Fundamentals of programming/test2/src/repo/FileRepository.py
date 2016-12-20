'''
Created on Dec 20, 2016

@author: bogdan
'''
from repo.repository import *

class FileDriverRepository(DriverRepository):
    
    def __init__(self,file="/home/bogdan/Documents/test2/src/drivers.in"):
        super().__init__()
        self.__file=file
        self.__loadData()
    
    def __loadData(self):
        try:
            f=open(self.__file,'r')
        except:
            raise RepoError("File Error!")
        for line in f:
            if(len(line)>2):
                x=line.split(',')
                if(len(x)<=1):
                    continue
                ID=x[0]
                name=x[1]
                name=name[:(len(name)-1)]
                super().add(ID,name)
        f.close()
        
    def __saveData(self):
        try:
            f=open(self.__file,'w')
        except:
            raise RepoError("File Error!")
        for it in super().getAll():
            f.write(str(it.getID())+','+str(it.getName())+'\n')
        f.close()
    
    def add(self,ID,name):
        super().add(ID,name)
        self.__saveData()
    
class FileOrderRepository(OrderRepository):
    
    def __init__(self,file="/home/bogdan/Documents/test2/src/orders.in"):
        super().__init__()
        self.__file=file
        self.__loadData()
    
    def __loadData(self):
        try:
            f=open(self.__file,'r')
        except:
            raise RepoError("File Error!")
        for line in f:
            if(len(line)>2):
                x=line.split(',')
                if(len(x)<=1):
                    continue
                ID=x[0]
                distance=x[1]
                distance=distance[:(len(distance)-1)]
                distance=int(distance)
                super().add(ID,distance)
        f.close()
        
    def __saveData(self):
        try:
            f=open(self.__file,'w')
        except:
            raise RepoError("File Error!")
        for it in super().getAll():
            f.write(str(it.getID())+','+str(it.getDistance())+'\n')
        f.close()
    
    def add(self,ID,dist):
        super().add(ID,dist)
        self.__saveData()
    