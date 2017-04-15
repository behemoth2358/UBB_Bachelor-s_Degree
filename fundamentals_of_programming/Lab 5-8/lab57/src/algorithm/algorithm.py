class Hash:
    def __init__(self):
        self.__mod=666013
        self.__p=101
        self.__myHash=[[]]*self.__mod
    def __code(self,x):
        val=0
        pp=self.__p
        for it in x:
            val=(val+ord(it)*pp)%self.__mod
            pp=(pp*(self.__p))%self.__mod
        return val
    
    def insert(self,x):
        val=self.__code(str(x))
        if self.__search(val,str(x))==False:
            self.__myHash[val].append(str(x))
            return True
        return False
    
    def __search(self,val,x):
        for it in self.__myHash[val]:
            if it==x:
                return True
        return False
    
    def find(self,x):
        val=self.__code(str(x))
        return self.__search(val,str(x))
    
    def delete(self,x):
        val=self.__code(x)
        for it in range(0,len(self.__myHash[val])):
            if self.__myHash[val][it]==x:
                self.__myHash[val].pop(it)
                return
        return
    
class data:
    def __init__(self,day,month,year):
        self.__day=str(day)
        self.__month=str(month)
        self.__year=str(year)
        if(len(self.__day)==1):
            self.__day="0"+str(self.__day)
        if(len(self.__month)==1):
            self.__month="0"+str(self.__month)
        while(len(self.__year)<4):
            self.__year="0"+str(self.__year)
            
    def __str__(self):
        return str(self.__year)+'/'+str(self.__month)+'/'+str(self.__day)
    
    def getDay(self):
        return int(self.__day)
    
    def getMonth(self):
        return int(self.__month)
    
    def getYear(self):
        return int(self.__year)
   
def prefix(s,p):
    k=0
    for i in range(1,len(s)):
        while(k>0 and s[k].lower()!=s[i].lower()):
            k=p[k-1]
        if(k<len(s) and s[k].lower()==s[i].lower()):
            k+=1
        p[i]=k
    return p

def kmp(s,x):
    p=[0]*(len(x)+1)
    prefix(x,p)
    k=0
    sol=[]
    for i in range(0,len(s)):
        while(k>0 and x[k].lower()!=s[i].lower()):
            k=p[k-1]
        if(k<len(x) and x[k].lower()==s[i].lower()):
            k+=1
        if(k==len(x)):
            sol.append(i-len(x)+1)
    return sol

def match(s,x):
    return ((x.lower() in s.lower()) or (s.lower() in x.lower()))
    
def number(x,a,b):
    x=str(x)
    nr=0
    for i in range(a,b):
        if x[i]<'0' or x[i]>'9':
            return "Error"
        nr=nr*10+int(x[i])-int('0')
    return nr

from datetime import datetime

def getDate(x):
    a=b=0
    while(b<len(x) and x[b]!='/'):
        b+=1
    if b==len(x):
        return "Error"
    day=number(x,a,b)
    a=b+1
    b=a
    while(b<len(x) and x[b]!='/'):
        b+=1
    if b==len(x):
        return "Error"
    month=number(x,a,b)
    year=number(x,b+1,len(x))
    if(str(day)=="Error" or str(year)=="Error" or str(month)=="Error" or day<1 or day>31 or month<1 or month>12):
        return "Error"
    return datetime(day,month,year)
    
    
    
    


    