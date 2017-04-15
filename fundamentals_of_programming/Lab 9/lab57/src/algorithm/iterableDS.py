'''
Created on Jan 6, 2017

@author: bogdan
'''
class IterableDS:
    
    
    def __init__(self):
        self.__arr=[]
        self.__current=0
    
    def append(self,value):
        self.__arr.append(value)
    
    def __getitem__(self,index):
        if(index < 0 or index >= len(self.__arr)):
            raise TypeError("Invalid index!")
        return self.__arr[index]
    
    def __setitem__(self,index,value):
        if(index < 0 or index >= len(self.__arr)):
            raise TypeError("Invalid index!")
        self.__arr[index]=value
    
    def __delitem__(self,index):
        if(index < 0 or index >= len(self.__arr)):
            raise TypeError("Invalid index!")
        del self.__arr[index]
        return
    
    def __next__(self):
        if( self.__current >= len(self.__arr) ):
            raise StopIteration
        self.__current+=1
        return self.__arr[ self.__current - 1 ]
    
    def __iter__(self):
        self.__current=0
        return self
    
    def __len__(self):
        return len(self.__arr)
    
    def pop(self,index=None):
        if(index==None):
            index=len(self.__arr)-1
        if(index < 0 or index >= len(self.__arr)):
            raise TypeError("Invalid index!")
        return self.__arr.pop(index)