class Settings:
    
    def __init__(self,file):
        self.__file=file
        self.__repo=None
        self.__BookFile=None
        self.__ClientFile=None
        self.__RentalFile=None
        self.__loadSettings()
    
    def __loadSettings(self):
        try:
            f=open(self.__file,'r')
        except EOFError:
            print ("settings.properties Error!")
        
        for line in f:
            if(len(line)>2):
                line=line[:(len(line)-1)]
                line=line.split('=')
                if(line[0]=="repository"):
                    self.__repo=line[1]
                if(line[0]=="books"):
                    self.__BookFile=line[1]
                if(line[0]=="clients"):
                    self.__ClientFile=line[1]
                if(line[0]=="rentals"):
                    self.__RentalFile=line[1]
                
        f.close()
        
    def repository(self):
        return self.__repo
    
    def books(self):
        return self.__BookFile
    
    def clients(self):
        return self.__ClientFile
    
    def rentals(self):
        return self.__RentalFile
        
        