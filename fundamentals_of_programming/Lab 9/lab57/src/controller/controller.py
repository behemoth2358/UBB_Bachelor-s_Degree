from datetime import datetime
from domain.book import *
from domain.client import *
from domain.rental import *
from algorithm.algorithm import *

class controller:
    
    def __init__(self,BookRepo,ClientRepo,RentalRepo):
        self.__Books=BookRepo
        self.__Clients=ClientRepo
        self.__Rentals=RentalRepo
    
    def AddBook(self,ID,title,description,author):#add a book
        self.__Books.add(ID,title,description,author)
        v=[]
        v.append(self.__inverse([1,ID,title,description,author]))
        return v
    
    def AddClient(self,ID,name):#add a client
        self.__Clients.add(ID,name)
        v=[]
        v.append(self.__inverse([2,ID,name]))
        return v
        
    def AddRental(self,rentalID,bookID,clientID,rentedDate,dueDate):#add a rental
        self.__Rentals.add(rentalID,bookID,clientID,rentedDate,dueDate)
        v=[]
        v.append(self.__inverse([3,rentalID,bookID,clientID,rentedDate,dueDate]))
        return v
    
    def RemoveBook(self,Filter,param):
        if Filter==1:
            return self.__removeBookByID(param)
        if Filter==2:
            return self.__removeBookByTitle(param)
        if Filter==3:
            return self.__removeBookByAuthor(param)
        return [[]]
    
    def __removeBookByID(self,ID):#remove the book with a given ID
        v=[]
        for i in range(0,len(self.__Books)):
            if(self.__Books.get(i).getID()==ID):
                v.append(self.__inverse([4,self.__Books.get(i).getID(),self.__Books.get(i).getTitle(),self.__Books.get(i).getDescription(),self.__Books.get(i).getAuthor()]))
                for k in self.__removeRentalsWithBook(self.__Books.get(i).getID()):
                    v.append(k)
                self.__Books.delete(i)
                break
        return v
    
    def __removeRentalsWithBook(self,ID):
        v=[]
        for i in range(len(self.__Rentals)-1,-1,-1):
            if(self.__Rentals.get(i).getBookID()==ID):
                v.append(self.__inverse([6,self.__Rentals.get(i).getID(),self.__Rentals.get(i).getBookID(),self.__Rentals.get(i).getClientID(),self.__Rentals.get(i).getRentedDate(),self.__Rentals.get(i).getDueDate(),self.__Rentals.get(i).getReturnedDate()]))
                self.__Rentals.delete(i);
        return v
    
    def __removeBookByTitle(self,title):#remove the books with a given title
        v=[]
        for i in range(len(self.__Books)-1,-1,-1):
            if(self.__Books.get(i).getTitle()==title):
                v.append(self.__inverse([1,self.__Books.get(i).getID(),self.__Books.get(i).getTitle(),self.__Books.get(i).getDescription(),self.__Books.get(i).getAuthor()]))
                v+=self.__removeRentalsWithBook(self.__Books.get(i).getID())
                self.__Books.delete(i)
        return v
    
    def __removeBookByAuthor(self,author,v):#remove the books with a given author 
        v=[]
        for i in range(len(self.__Books)-1,-1,-1):
            if(self.__Books.get(i).getAuthor()==author):
                v.append(self.__inverse([1,self.__Books.get(i).getID(),self.__Books.get(i).getTitle(),self.__Books.get(i).getDescription(),self.__Books.get(i).getAuthor()]))
                v+=self.__removeRentalsWithBook(self.__Books.get(i).getID())
                self.__Books.delete(i)
        return v
                   
    def RemoveClient(self,Filter,param):
        if Filter==1:
            return self.__removeClientByID(param)
        if Filter==2:
            return self.__removeClientByName(param)
        return ("Invalid command!")
    
    def __removeRentalsWithClient(self,ID):
        v=[]
        for i in range(len(self.__Rentals)-1,-1,-1):
            if(self.__Rentals.get(i).getClientID()==ID):
                v.append(self.__inverse([6,self.__Rentals.get(i).getID(),self.__Rentals.get(i).getBookID(),self.__Rentals.get(i).getClientID(),self.__Rentals.get(i).getRentedDate(),self.__Rentals.get(i).getDueDate(),self.__Rentals.get(i).getReturnedDate()]))            
                self.__Rentals.delete(i);
        return v
    def __removeClientByID(self,ID):#remove the client with a given ID
        v=[]
        for i in range(0,len(self.__Clients)):
            if(self.__Clients.get(i).getID()==ID):
                v.append(self.__inverse([5,self.__Clients.get(i).getID(),self.__Clients.get(i).getClientName()]))
                v+=self.__removeRentalsWithClient(self.__Clients.get(i).getID())
                self.__Clients.delete(i)
                return v
        return v
    
    def __removeClientByName(self,name):#remove the client with a given name
        v=[]
        for i in range(len(self.__Clients)-1,-1,-1):
            if(self.__Clients.get(i).getClientName()==name):
                v.append(self.__inverse([5,self.__Clients.get(i).getID(),self.__Clients.get(i).getName()]))
                v+=self.__removeRentalsWithClient(self.__Clients.get(i).getID())
                self.__Clients.delete(i)
        return v
    
    def ModifyBook(self,Filter,param1,param2):
        if Filter==1:
            return self.__modifyBookByID(param1,param2)
        if Filter==2:
            return self.__modifyBookByTitle(param1,param2)
        if Filter==3:
            return self.__modifyBookByAuthor(param1,param2)
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
    undoReturnBook 10
    '''
    def __inverse(self,params):
        inv=[0,4,5,6,1,2,3,7,8,9]
        params[0]=inv[ params[0] ]
        return params
    
    def __getInv(self,a,b):
        c=book("","","","")
        if(b.getTitle()!=""):
            c.setTitle(a.getTitle())
            return c
        if(b.getAuthor()!=""):
            c.setAuthor(a.getAuthor())
            return c
        if(b.getDescription()!=""):
            c.setDescription(a.getDescription())
        return c
    
    def __modifyBookByID(self,ID,param):#modifies the book with a given ID
        v=[]
        for i in range(0,len(self.__Books)):
            if(self.__Books.get(i).getID()==ID):
                v.append([7,1,self.__Books.get(i).getID(),self.__getInv(self.__Books.get(i),param),param])                            
                self.__Books.get(i).mix(param)
                self.__Books.save()
                break
        return v
    
    def __modifyBookByTitle(self,title,param):#modifies the book with a given title
        v=[]
        for i in range(len(self.__Books)-1,-1,-1):
            if(self.__Books.get(i).getTitle()==title):
                v.append([7,1,self.__Books.get(i).getID(),self.__getInv(self.__Books.get(i),param),param])  
                self.__Books.get(i).mix(param)
                self.__Books.save()
        return v
    
    def __modifyBookByAuthor(self,author,param):#modifies the book with a given author
        v=[]
        for i in range(len(self.__Books)-1,-1,-1):
            if(self.__Books.get(i).getAuthor()==author):
                v.append([7,1,self.__Books.get(i).getID(),self.__getInv(self.__Books.get(i),param),param])  
                self.__Books.get(i).mix(param)
                self.__Books.save()
        return v
    
    def ModifyClient(self,Filter,param1,param2):
        if Filter==1:
            return self.__modifyClientByID(param1,param2)
        if Filter==2:
            return self.__modifyClientByName(param1,param2)
        return ("Invalid command!")
    
    def __getInvC(self,a,b):
        return client("",a.getClientName())
    
    def __modifyClientByID(self,ID,param):#modifies the client with a given id
        v=[]
        for i in range(0,len(self.__Clients)):
            if(self.__Clients.get(i).getID()==ID):
                v.append([8,1,self.__Clients.get(i).getID(),self.__getInvC(self.__Clients.get(i),param),param])
                self.__Clients.get(i).mix(param)
                self.__Clients.save()
                break
        return v
    
    def __modifyClientByName(self,name,param):#modifies the client with a given name
        v=[]
        for i in range(len(self.__Clients)-1,-1,-1):
            if(self.__Clients.get(i).getName()==name):
                v.append([8,1,self.__Clients.get(i).getID(),self.__getInvC(self.__Clients.get(i),param),param])
                self.__Clients.get(i).mix(param)
                self.__Clients.save()
        return v
    
    
    def ShowAllBooks(self):#prints all books
        heapSort(self.__Books.getAll(),bookCompare)
        return str(self.__Books)
    
    def ShowAllClients(self):#prints all clients
        heapSort(self.__Clients.getAll(),clientCompare)
        return str(self.__Clients)
    
    def ReturnBook(self,ID,returnedDate):#returns a book
        v=[]
        for i in range(0,len(self.__Rentals)):
            if(self.__Rentals.get(i).getID()==ID):
                v.append([9,ID,returnedDate])
                self.__Rentals.get(i).setReturnedDate(returnedDate)
                self.__Rentals.save()
                break
        return v
    
    def undoReturnBook(self,ID):
        for i in range(0,len(self.__Rentals)):
            if(self.__Rentals.get(i).getID()==ID):
                self.__Rentals.get(i).setReturnedDate("Not returned yet")
                return
            
    def SearchBooks(self,filter1,filter2):
        if(filter1=='1'):
            return self.__searchBooksByID(filter2)
        if(filter1=='2'):
            return self.__searchBooksByTitle(filter2)
        if(filter1=='3'):
            return self.__searchBooksByAuthor(filter2)
        if(filter1=='4'):
            return self.__searchBooksByDescription(filter2)
        return ("Invalid command!")
    
    def SearchClients(self,filter1,filter2):
        if(filter1=='1'):
            return self.__searchClientsByID(filter2)
        if(filter1=='2'):
            return self.__searchClientsByName(filter2)
        return ("Invalid command!")
    
    def __searchBooksByID(self,ID):#returns the books with a given ID
        res=filterBy( self.__Books.getAll(), lambda x:(x.getID()==ID) )
        if(res==[]):
            return ("No books with ID="+str(ID))
        return str(res[0])
    
    def __searchBooksByTitle(self,title):#returns all books with a given title
        s=""
        res=filterBy( self.__Books.getAll(), lambda x:((x.getTitle().lower() in title.lower() ) or (title.lower() in x.getTitle().lower())) )
        for it in res:
            s+=str(it)
            s+="\n"
        if(s==""):
            s="No books with this title\n"
        return s
    
    def __searchBooksByAuthor(self,author):#returns all books with a given author
        s=""
        res=filterBy( self.__Books.getAll(), lambda x:((x.getAuthor().lower() in author.lower() ) or (author.lower() in x.getAuthor().lower())) )
        for it in res:
            s+=str(it)
            s+="\n"
        if(s==""):
            s="No books with this author\n"
        return s
    
    def __searchBooksByDescription(self,description):#returns all books with a given description
        s=""
        res=filterBy( self.__Books.getAll(), lambda x:((x.getDescription().lower() in description.lower() ) or (description.lower() in x.getDescription().lower())) )
        for it in res:
            s+=str(it)
            s+="\n"
        if(s==""):
            s="No books with this description"
        return s
    
    def __searchClientsByID(self,ID):#returns client with a given ID
        res=filterBy( self.__Clients.getAll(), lambda x:(x.getID()==ID) )
        if(res==[]):
            return ("No client with ID="+str(ID))
        return str(res[0])
    
    def __searchClientsByName(self,name):#returns all clients with a given name
        s=""
        res=filterBy( self.__Clients.getAll(), lambda x:((x.getClientName().lower() in name.lower() ) or (name.lower() in x.getClientName().lower())) )
        for it in res:
            s+=str(it)
            s+="\n"
        if(s==""):
            s="No clients with this name\n"
        return s
    
    def MostActiveClients(self):#returns the list of clients sorted by the number of days they had books rented
        arr={}
        s=""
        for i in range(0,len(self.__Rentals)):
            arr[self.__Rentals.get(i).getClientID()]=0
        for i in range(0,len(self.__Rentals)):
            x=0
            if(str(self.__Rentals.get(i).getReturnedDate())=="Not returned yet"):
                x=(datetime.now()-self.__Rentals.get(i).getRentedDate()).days
            else:
                x=(self.__Rentals.get(i).getReturnedDate()-self.__Rentals.get(i).getRentedDate()).days
            arr[self.__Rentals.get(i).getClientID()]+=x
        ss = [(k, arr[k]) for k in sorted(arr, key=arr.get, reverse=True)]
        for k, v in ss:
            s+=(str(self.__searchClientsByID(k))+"Days rented:"+str(v)+"\n")
        return s
    
    def MostRentedBooks(self):#returns the list of books sorted by the number of days they were rented
        arr={}
        s=""
        for i in range(0,len(self.__Rentals)):
            arr[self.__Rentals.get(i).getBookID()]=0
        for i in range(0,len(self.__Rentals)):
            arr[self.__Rentals.get(i).getBookID()]+=1
        ss = [(k, arr[k]) for k in sorted(arr, key=arr.get, reverse=True)]
        for k, v in ss:
            s+=str(str(self.__searchBooksByID(k))+"Times rented:"+str(v)+"\n")
        return s
    
    def LateRentals(self):#returns all late rentals
        currentDate=datetime.now()
        arr={}
        for i in range(0,len(self.__Rentals)):
            arr[self.__Rentals.get(i).getBookID()]=0
        s=""
        for i in range(0,len(self.__Rentals)):
            if(str(self.__Rentals.get(i).getReturnedDate())=="Not returned yet" and self.__Rentals.get(i).getDueDate()<currentDate):
                    arr[self.__Rentals.get(i).getBookID()]+=(currentDate-self.__Rentals.get(i).getDueDate()).days
        ss = [(k, arr[k]) for k in sorted(arr, key=arr.get, reverse=True)]
        for k, v in ss:
            s+=str(str(self.__searchBooksByID(k))+"Days of delay:"+str(v)+"\n")
        return s
    
    def __getBookByID(self,ID):
        for i in range(0,len(self.__Books)):
            if(self.__Books.get(i).getID()==ID):
                return self.__Books.get(i)
    
    def MostRentedAuthor(self):#returns the list of authors sorted by the number of times their books were rented
        arr={}
        s=""
        for i in range(0,len(self.__Books)):
            arr[self.__Books.get(i).getAuthor()]=0
        for i in range(0,len(self.__Rentals)):
            arr[self.__getBookByID(self.__Rentals.get(i).getBookID()).getAuthor()]+=1
        ss = [(k, arr[k]) for k in sorted(arr, key=arr.get, reverse=True)]
        for k, v in ss:
            s+=(str(k)+" rented "+str(v)+" times\n")
        return s
    
    def RemoveRental(self,ID):
        for i in range(0,len(self.__Rentals)):
            if(self.__Rentals.get(i).getID()==ID):
                self.__Rentals.delete(i)
                return ("Done!")
        return ("Done!")
    
    def ShowAllRentals(self):
        heapSort(self.__Rentals.getAll(),rentalCompare)
        return str(self.__Rentals)

class ControllerException(Exception):
    def __init__(self,error):
        self.__error=error
    
    def __str__(self):
        return self.__error
    

def bookCompare(a,b):
    return a.getTitle() > b.getTitle()

def clientCompare(a,b):
    return a.getClientName() > b.getClientName()

def rentalCompare(a,b):
    return a.getRentedDate() > b.getRentedDate()

    