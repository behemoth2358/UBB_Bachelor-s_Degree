
from repo.RentalRepository import *
from repo.RepositoryException import *
import pickle
    
class PickleRentalRepository(RentalRepository):
    
    def __init__(self,file="/home/bogdan/Documents/lab57/src/pickle_rentals.txt"):
        super().__init__()
        self.__file=file
        self.__loadData()
    
    def __loadData(self):
        try:
            f=open(self.__file,"rb")
        except:
            raise RepositoryException("File error!")
        try:
            entities=pickle.load(f)
        except EOFError:
            return
        for line in entities:
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
                if(str(returnedDate)!="Not returned yet"):
                    returnedDate=datetime.strptime(returnedDate,"%Y-%m-%d")
                super().add(ID,bookID,clientID,rentedDate,dueDate,returnedDate)
        f.close()     
        
    def save(self):
        try:
            f=open(self.__file,"wb")
        except:
            raise RepositoryException("File error!")
        lst=[]
        for it in self.getAll():
            lst.append(it.cStr())
        pickle.dump(list(lst),f)
        f.close() 
    
    def add(self,ID,bookID,clientID,rentedDate,dueDate,returnedDate="Not returned yet"):
        super().add(ID,bookID,clientID,rentedDate,dueDate,returnedDate)
        self.save()
    
    def delete(self,ind):
        super().delete(ind)
        self.save()