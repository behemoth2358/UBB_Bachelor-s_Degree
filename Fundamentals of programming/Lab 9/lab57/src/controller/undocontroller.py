from controller.controller import *

class UndoController(controller):
    def __init__(self,BookRepo,ClientRepo,RentalRepo):
        controller.__init__(self,BookRepo,ClientRepo,RentalRepo)
        self.__undoStack=[]
        self.__undoStack.append([])
        self.__cnt=0
        self.__redoCnt=0
    '''
    addBook 1
    addClient 2
    addRental 3
    removeBook 4
    removeClient 5
    removeRental 6
    modifyBook 7
    modifyClient 8
    returnBook 9
    '''
    def AddBook(self,ID,title,description,author):#add a book
        self.__undoStack.append([])
        self.__cnt+=1;
        self.__redoCnt=0
        self.__undoStack[self.__cnt]+=controller.AddBook(self,ID,title,description,author)
        return ("Done!")
    
    def AddClient(self,ID,name):#add a client
        self.__undoStack.append([])
        self.__cnt+=1
        self.__redoCnt=0
        self.__undoStack[self.__cnt]+=controller.AddClient(self,ID,name)
        return ("Done!")
        
    def AddRental(self,rentalID,bookID,clientID,rentedDate,dueDate):#add a rental
        self.__undoStack.append([])
        self.__cnt+=1
        self.__redoCnt=0
        self.__undoStack[self.__cnt]+=controller.AddRental(self,rentalID,bookID,clientID,rentedDate,dueDate)
    
    def RemoveClient(self,filter1,param):
        self.__undoStack.append([])
        self.__cnt+=1
        self.__redoCnt=0
        self.__undoStack[self.__cnt]+=(controller.RemoveClient(self,filter1,param))
    
    def RemoveBook(self,filter1,param):
        self.__cnt+=1
        self.__undoStack.append([])
        self.__redoCnt=0
        self.__undoStack[self.__cnt]+=(controller.RemoveBook(self,filter1,param))
        return ("Done!")
        
    def ModifyBook(self,filter1,param1,param2):
        self.__cnt+=1
        self.__redoCnt=0
        self.__undoStack.append([])
        self.__undoStack[self.__cnt]+=(controller.ModifyBook(self,filter1,param1,param2))
        return ("Done!")
    
    def ModifyClient(self,filter1,param1,param2):
        self.__cnt+=1
        self.__redoCnt=0
        self.__undoStack.append([])
        self.__undoStack[self.__cnt]+=(controller.ModifyClient(self,filter1,param1,param2))
        return ("Done!")
        
    def ReturnBook(self,ID,returnedDate):
        self.__cnt+=1
        self.__redoCnt=0
        self.__undoStack.append([])
        self.__undoStack[self.__cnt]+=(controller.ReturnBook(self,ID,returnedDate))
        return ("Done!")
    
    def Undo(self):
        if(self.__cnt==-1):
            return ("You can't undo anymore!")
        v=self.__undoStack[self.__cnt]
        self.__cnt-=1;
        self.__redoCnt+=1
        print(v)
        for i in v:
            self.__applyCommand(i)
        return ("Done!")
    
    def Redo(self):
        self.__redoCnt-=1
        self.__cnt+=1
        if(self.__redoCnt<0):
            return ("You can't redo anymore!")
        v=self.__undoStack[self.__cnt]
        for i in v:
            self.__applyCommand(self.__inverse(i))
        return ("Done!")
    
    def __inverse(self,params):
        inv=[0,4,5,6,1,2,3,7,8,10,9]
        v=params
        v[0]=inv[ v[0] ]
        if(v[0]==8 or v[0]==7):
            x=v[3]
            v[3]=v[4]
            v[4]=x
        return v
    
    def __applyCommand(self,params):
        #print(params)
        if(params[0]==1):
            controller.AddBook(self,params[1],params[2],params[3],params[4])
        if(params[0]==2):
            controller.AddClient(self,params[1],params[2])
        if(params[0]==3):
            controller.AddRental(self,params[1],params[2],params[3],params[4],params[5])
        if(params[0]==4):
            controller.RemoveBook(self,1,params[1])
        if(params[0]==5):
            controller.RemoveClient(self,1,params[1])
        if(params[0]==6):
            controller.RemoveRental(self,params[1])
        if(params[0]==7):
            #print(params[1])
            #print(params[2])
            #print(params[3])
            controller.ModifyBook(self,params[1],params[2],params[3])
        if(params[0]==8):
            controller.ModifyClient(self,params[1],params[2],params[3])
        if(params[0]==9):
            controller.undoReturnBook(self,params[1])
        if(params[0]==10):
            controller.ReturnBook(self,params[1],params[2])
        
    
    