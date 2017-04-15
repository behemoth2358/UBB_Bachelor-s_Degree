'''
Created on Dec 22, 2016

@author: bogdan
'''
from repo.ClientRepository import *
from repo.RepositoryException import *
    
class FileClientRepository(ClientRepository):
    
    def __init__(self,file="/home/bogdan/Documents/lab57/src/clients.txt"):
        super().__init__()
        self.__file=file
        self.__loadData()
    
    def __loadData(self):
        try:
            f=open(self.__file,'r')
        except:
            raise RepositoryException("File error!")
        for line in f:
            if(len(line)>2):
                params=line.split(',')
                if(len(params)<=1):
                    continue
                ID=params[0]
                name=params[1]
                name=name[:(len(name)-1)]
                super().add(ID,name)
        f.close()
        
    def save(self):
        try:
            f=open(self.__file,'w')
        except:
            raise RepositoryException("File error!")
        for it in super().getAll():
            f.write(str(it.getID())+','+str(it.getClientName())+'\n')
        f.close()
    
    def add(self,ID,name):
        super().add(ID,name)
        self.save()
    
    def delete(self,ind):
        super().delete(ind)
        self.save()