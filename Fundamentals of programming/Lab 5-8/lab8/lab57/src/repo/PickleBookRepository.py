from repo.BookRepository import *
from repo.RepositoryException import *
import pickle
    
class PickleBookRepository(BookRepository):
    
    def __init__(self,file="/home/bogdan/Documents/lab57/src/pickle_books.txt"):
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
                title=params[1]
                description=params[2]
                author=params[3]
                super().add(ID,title,description,author)
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
    
    def add(self,ID,title,description,author):
        super().add(ID,title,description,author)
        self.save()
    
    def delete(self,ind):
        super().delete(ind)
        self.save()