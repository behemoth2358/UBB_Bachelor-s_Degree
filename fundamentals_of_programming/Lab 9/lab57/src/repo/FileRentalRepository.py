'''
Created on Dec 22, 2016

@author: bogdan
'''
from repo.RentalRepository import *
from repo.RepositoryException import *
    
class FileRentalRepository(RentalRepository):
    
    def __init__(self,file="/home/bogdan/Documents/lab57/src/rentals.txt"):
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
                bookID=params[1]
                clientID=params[2]
                rentedDate=params[3]
                dueDate=params[4]
                returnedDate=params[5]
                rentedDate=datetime.strptime(rentedDate,"%Y-%m-%d")
                dueDate=datetime.strptime(dueDate,"%Y-%m-%d")
                returnedDate=returnedDate[:(len(returnedDate)-1)]
                if(str(returnedDate)!="Not returned yet"):
                    returnedDate=datetime.strptime(returnedDate,"%Y-%m-%d")
                super().add(ID,bookID,clientID,rentedDate,dueDate,returnedDate)
        f.close()
        
    def save(self):
        try:
            f=open(self.__file,'w')
        except:
            raise RepositoryException("File error!")
        for it in super().getAll():
            x="Not returned yet"
            if(str(it.getReturnedDate())!="Not returned yet"):
                x=it.getReturnedDate().strftime('%Y-%m-%d')
            f.write(str(it.getID())+','+str(it.getBookID())+','+str(it.getClientID())+','+str(it.getRentedDate().strftime('%Y-%m-%d'))+','+str(it.getDueDate().strftime('%Y-%m-%d'))+','+str(x)+'\n')
        f.close()
    
    def add(self,ID,bookID,clientID,rentedDate,dueDate,returnedDate="Not returned yet"):
        super().add(ID,bookID,clientID,rentedDate,dueDate,returnedDate)
        self.save()
    
    def delete(self,ind):
        super().delete(ind)
        self.save()