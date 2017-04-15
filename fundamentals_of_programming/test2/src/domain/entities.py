'''
Created on Dec 20, 2016

@author: bogdan
'''
class Driver:
    def __init__(self,ID,name):
        self.__ID=ID
        self.__name=name
    
    def getID(self):
        return self.__ID
    
    def getName(self):
        return self.__name
    
    def setName(self,name):
        self.__name=name
    
    def __str__(self):
        return "ID="+str(self.__ID)+" Name:"+str(self.__name)
        
class Order:
    def __init__(self,ID,distance):
        self.__ID=ID
        self.__distance=distance
    
    def getID(self):
        return self.__ID
    
    def getDistance(self):
        return self.__distance
    
    def __str__(self):
        return "ID="+str(self.__ID)+" Name:"+str(self.__distance)