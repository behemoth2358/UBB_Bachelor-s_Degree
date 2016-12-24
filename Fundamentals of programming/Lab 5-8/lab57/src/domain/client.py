class client:
    def __init__(self,clientID,name):
        self._clientID=clientID
        self._name=name
    
    def __str__(self):
        return "\nClient name:"+self._name+"\nClient ID: "+str(self._clientID)+"\n"
    
    def getClientName(self):
        return self._name
    
    def getID(self):
        return self._clientID
    
    def setClientName(self,newName):
        self._name=newName
        
    def setID(self,ID):
        self._clientID=ID
        
    def cStr(self):
        return self.getID()+','+self.getClientName()
    
    def mix(self,other):
        if other.getID()!="":
            self.setID(other.getID())
        if other.getClientName()!="":
            self.setClientName(other.getClientName())