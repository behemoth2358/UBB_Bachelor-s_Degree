from copy import *

class Transaction:
    '''
    Initialize a variable of type Transaction
    Parameters: day - integer, value - integer, typ - string, description - string
    '''
    def __init__(self,day,value,typ,description):
        self.day=day
        self.value=value
        self.typ=typ
        self.description=description

    def __eq__(self,other):
        return (self.day==other.day and self.value==other.value and self.typ==other.typ and self.description==other.description)
    
    def get_day(self):
        return deepcopy(self.day)

    def get_value(self):
        return deepcopy(self.value)

    def get_typ(self):
        return deepcopy(self.typ)

    def get_description(self):
        return deepcopy(self.description)
        
    def modify_value(self,value):
        self.value=value
        
    def __str__(self):
        return "Day:"+str(self.day)+' '+"Value:"+str(self.value)+' '+"Type:"+self.typ+' '+"Description:"+self.description