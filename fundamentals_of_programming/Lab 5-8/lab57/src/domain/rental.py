from datetime import *
from time import *
class rental:
    def __init__(self,rentalID,bookID,clientID,rentedDate,dueDate,returnedDate="Not returned yet"):
        self.__rentalID=rentalID
        self.__bookID=bookID
        self.__clientID=clientID
        self.__rentedDate=rentedDate
        self.__dueDate=dueDate
        self.__returnedDate=returnedDate
    
    def __str__(self):
        sol="\nRental ID: "+str(self.__rentalID)
        sol+="\nBook ID: "+str(self.__bookID)
        sol+="\nClient ID: "+str(self.__clientID)
        sol+="\nRented date: "+str(self.__rentedDate.strftime('%Y-%m-%d'))
        sol+="\nDue date: "+str(self.__dueDate.strftime('%Y-%m-%d'))
        if(str(self.__returnedDate)=="Not returned yet"):
            sol+="\nReturned date: Not returned yet\n"
        else:
            sol+="\nReturned date: "+str(self.__returnedDate.strftime('%Y-%m-%d')+"\n")
        return sol
    
    def getID(self):
        return self.__rentalID
    
    def getBookID(self):
        return self.__bookID
   
    def getClientID(self):
        return self.__clientID
    
    def getRentedDate(self):
        return self.__rentedDate
    
    def getDueDate(self):
        return self.__dueDate
    
    def getReturnedDate(self):
        return self.__returnedDate
    
    def setReturnedDate(self,x):
        self.__returnedDate=x   