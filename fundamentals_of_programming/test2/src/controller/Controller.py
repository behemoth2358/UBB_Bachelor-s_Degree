'''
Created on Dec 20, 2016

@author: bogdan
'''
class ControllerError(Exception):
    def __init__(self,msg):
        self.__msg=msg
    def __str__(self):
        return self.__msg
    
class Controller:
    def __init__(self,DriverRepo,OrderRepo):
        self.__drivers=DriverRepo
        self.__orders=OrderRepo
    
    def AddDriver(self,ID,name):
        self.__drivers.add(ID,name)
    
    def AddOrder(self,ID,distance):
        if(self.__drivers.srch(ID)==False):
            raise ControllerError("No driver with this ID!")
        self.__orders.add(ID,distance)
    
    def ShowAllOrders(self):
        return str(self.__orders)
    
    def ShowAllDrivers(self):
        return str(self.__drivers)
        
    def GetDistance(self,ID):
        s=0
        for it in self.__orders.getAll():
            if(it.getID()==ID):
                s+=it.getDistance()
        return s
    
    def Stats(self):
        myMap={}
        for it in self.__drivers.getAll():
            myMap[it.getID()]=0 
        for it in self.__orders.getAll():
            myMap[it.getID()]+=it.getDistance()
        a=[]
        for it in self.__drivers.getAll():
            a.append([myMap[it.getID()],it.getID()])
        s=""
        a=sorted(a)
        for i in range(len(a)-1,-1,-1):
            s+=(str(self.GetName(a[i][1]))+" Income:"+str(a[i][0]*0.5)+"\n")
        return s
            
    
    def GetIncome(self,ID):
        if(self.__drivers.srch(ID)==False):
            raise ControllerError("ID invalid!")
        return 0.5*self.GetDistance(ID)
    
    def GetName(self,ID):
        for it in self.__drivers.getAll():
            if(it.getID()==ID):
                return it.getName()
        return ("No taxi driver with this ID!")
    
    