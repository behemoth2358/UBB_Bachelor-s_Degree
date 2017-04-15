'''
Created on Dec 19, 2016

@author: bogdan
'''
from repo.BookRepository import *
from repo.RepositoryException import *
    
class FileBookRepository(BookRepository):
    
    def __init__(self,file="/home/bogdan/Documents/lab57/src/books.txt"):
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
                title=params[1]
                description=params[2]
                author=params[3]
                author=author[:(len(author)-1)]
                super().add(ID,title,description,author)
        f.close()     
        
    def save(self):
        try:
            f=open(self.__file,'w')
        except:
            raise RepositoryException("File error!")
        for it in super().getAll():
            f.write( str(it.getID())+','+str(it.getTitle())+','+str(it.getDescription())+','+str(it.getAuthor())+'\n')
        f.close() 
    
    def add(self,ID,title,description,author):
        super().add(ID,title,description,author)
        self.save()
    
    def delete(self,ind):
        super().delete(ind)
        self.save()