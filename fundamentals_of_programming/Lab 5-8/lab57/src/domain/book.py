class book:
    def __init__(self,bookID,title,description,author):
        self._bookID=bookID
        self._title=title
        self._description=description
        self._author=author
        
    def getID(self):
        return self._bookID
    
    def getTitle(self):
        return self._title
   
    def getDescription(self):
        return self._description
    
    def getAuthor(self):
        return self._author
    
    def setID(self,ID):
        self._bookID=ID
    
    def setTitle(self,newTitle):
        self._title=newTitle
   
    def setDescription(self,newDescription):
        self._description=newDescription
    
    def setAuthor(self,newAuthor):
        self._author=newAuthor
    
    def mix(self,other):
        if other.getID()!="":
            self.setID(other.getID())
        if other.getTitle()!="":
            self.setTitle(other.getTitle())
        if other.getAuthor()!="":
            self.setAuthor(other.getAuthor())
        if other.getDescription()!="":
            self.setDescription(other.getDescription())
    
    def cStr(self):
        return self.getID()+','+self.getTitle()+','+self.getAuthor()+','+self.getDescription()
    
    def __str__(self):
        return "\nTitle: "+self.getTitle()+"\nAuthor: "+self.getAuthor()+"\nBook ID: "+str(self.getID())+"\nDescription: "+self.getDescription()+"\n"
    
            