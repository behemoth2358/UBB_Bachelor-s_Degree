from algorithm.algorithm import *
from domain.book import *
from domain.client import *
from domain.rental import *

class UI:
    def __init__(self,controller):
        self.__controller=controller
    
    def menu(self):
        commands="\n\nPress 0 to exit\nPress 1 to add a book/client/rental \nPress 2 to modify/remove a book/client \nPress 3 to search for clients/books\nPress 4 to return a book\nPress 5 to see all books\nPress 6 to see all clients\nPress 7 for stats\nPress 8 to see all rentals\nPress 9 to undo\nPress 10 to redo\nInsert your command:"
        while True:
            print(commands,end="")
            command=input()
            try:
                command=int(command)
            except:
                print("Invalid command!")
                continue
            
            if command==0:
                break
            
            if command==1: #Add a book/client/rental
                print("\n  Press 1 to add a book\n  Press 2 to add a client\n  Press 3 to add a rental\n  Insert your command:")
                command2=input()
                try:
                    command2=int(command2)
                except:
                    print("Invalid command!")
                    continue
                if command2==1:
                    bookID=input("  BookID:")
                    bookTitle=input("  Book title:")
                    bookDescr=input("  Book description:")
                    bookAuthor=input("  Book author:")
                    try:
                        print(self.__controller.AddBook(bookID,bookTitle,bookDescr,bookAuthor))
                    except Exception as x:
                        print(x)
                    continue
                if command2==2:
                    clientID=input("  Client ID:")
                    clientName=input("  Client name:")
                    try:
                        print(self.__controller.AddClient(clientID,clientName))
                    except Exception as x:
                        print(x)
                    continue
                if command2==3:
                    rentalID=input("  Rental ID:")
                    clientID=input("  Client ID:")
                    bookID=input("  Book ID:")
                    rentedDate=input("  Rented date(yyyy-mm-dd):")
                    dueDate=input("  Due date(yyyy-mm-dd):")
                    try:
                        rentedDate=datetime.strptime(rentedDate,"%Y-%m-%d")
                        dueDate=datetime.strptime(dueDate,"%Y-%m-%d")
                    except:
                         print("Invalid data!")
                         continue
                    if(str(rentedDate)=="Error" or str(dueDate)=="Error"):
                        print("Invalid date!")
                        continue
                    try:
                        self.__controller.AddRental(rentalID,bookID,clientID,rentedDate,dueDate)
                    except Exception as x:
                        print(x)
                        continue
                    print("Done!")
                    continue
            if command==2: #modify/remove
                command2=input("\n  Press 1 to modify a book\n  Press 2 to modify a client\n  Press 3 to remove a book\n  Press 4 to remove a client\n  Insert your command:")
                try:
                    command2=int(command2)
                except:
                    print("Invalid command!")
                    continue
                if(command2==1):
                    filter1=input("\n    Press 1 to modify by ID\n    Press 2 to modify by title\n    Press 3 to modify by author\n    Insert your command:")
                    filter2=input("\nInsert ID/title/author:")
                    filter3=input("\n      Press 1 to modify title\n      Press 2 to modify author\n      Press 3 to modify description\n      Press 4 to modify ID\n      Insert your command:")
                    try:
                        filter1=int(filter1)
                        filter3=int(filter3)
                    except:
                        print("Invalid command!")
                        continue
                    filter4=input("\n      Insert new title/author/description:")
                    x=book("","","","")
                    if(filter3==1):
                        x.setTitle(filter4)
                    if(filter3==2):
                        x.setAuthor(filter4)
                    if(filter3==3):
                        x.setDescription(filter4)
                    if(filter3==4):
                        x.setID(filter4)
                    try:
                        print(self.__controller.ModifyBook(filter1,filter2,x))
                    except Exception as x:
                        print(x)
                    continue
                if(command2==2):
                    filter1=input("\n    Press 1 to modify by ID\n    Press 2 to modify by name\n    Insert your command:")
                    filter2=input("\n    Insert ID/Name:")
                    filter3=input("\n    Press 1 to modify ID\n    Press 2 to modify name\n    Insert your command:")
                    try:
                        filter1=int(filter1)
                        filter3=int(filter3)
                    except:
                        print("Invalid command") 
                        continue
                    filter4=input("\n    Insert new ID/name:")
                    x=client("","")
                    if filter3==1:
                        x.setID(filter4)
                    if filter3==2:
                        x.setClientName(filter4)
                    try:
                        print(self.__controller.ModifyClient(filter1,filter2,x))
                    except Exception as x:
                        print(x)
                    continue
                if(command2==3):
                    filter1=input("\n    Press 1 to remove by ID\n    Press 2 to remove by title\n    Press 3 to remove by author\n    Insert your command:")
                    filter2=input("\n    Insert ID/title/author:")
                    try:
                        filter1=int(filter1)
                    except:
                        print("Invalid command!")
                        continue
                    try:
                        print(self.__controller.RemoveBook(filter1,filter2))
                    except Exception as x:
                        print(x)
                    continue
                if(command2==4):
                    filter1=input("\n    Press 1 to remove by ID\n    Press 2 to remove by name\n    Insert your command:")
                    filter2=input("\n    Insert ID/name:")
                    try:
                        filter1=int(filter1)
                    except:
                        print("Invalid command!")
                        continue
                    try:
                        print(self.__controller.RemoveClient(filter1,filter2))
                    except Exception as x:
                        print(x)
                    continue
            if command==3:
                filter1=input("    Press 1 to search for a book\n    Press 2 to search for a client\n    Insert your command:")
                if(filter1=='1'):
                    filter2=input("      Press 1 to search by ID\n      Press 2 to search by title\n      Press 3 to search by author\n      Press 4 to search by description\n      Insert your command:")
                    filter3=input("      Insert book ID/title/description/author:")
                    try:
                        print(self.__controller.SearchBooks(filter2,filter3))
                    except Exception as x:
                        print(x)
                    continue
                if(filter1=='2'):
                    filter2=input("      Press 1 to search by ID\n      Press 2 to search by name\n      Insert your command:")
                    filter3=input("      Insert client ID/name:")
                    try:
                        print(self.__controller.SearchClients(filter2,filter3))
                    except Exception as x:
                        print(x)
                    continue
                print("Invalid command!")
            if command==4:
                rentalID=input("  Rental ID:")
                returnedDate=input("  Returned date(yyyy-mm-dd):")
                try:
                    returnedDate=datetime.strptime(returnedDate,"%Y-%m-%d")
                except:
                    print("Invalid data!")
                    continue
                try:
                    print(self.__controller.ReturnBook(rentalID,returnedDate))
                except Exception as x:
                    print(x)
                continue
            if command==5:
                try:
                    print(self.__controller.ShowAllBooks())
                except Exception as x:
                    print(x)
                continue
            if command==6:
                try:
                    print(self.__controller.ShowAllClients())
                except Exception as x:
                    print(x)
                continue
            if command==8:
                print(self.__controller.ShowAllRentals())
                continue
            if(command==7):
                filter1=input("\n  Press 1 to for late rentals\n  Press 2 to for most rented books\n  Press 3 for most rented authors\n  Press 4 for most active clients\n  Insert your command:")
                if(filter1=='1'):
                    try:
                        print(self.__controller.LateRentals())
                    except Exception as x:
                        print(x)
                    continue
                if(filter1=='2'):
                    try:
                        print(self.__controller.MostRentedBooks())
                    except Exception as x:
                        print(x)
                    continue
                if(filter1=='3'):
                    try:
                        print(self.__controller.MostRentedAuthor())
                    except Exception as x:
                        print(x)
                    continue
                if(filter1=='4'):
                    try:
                        print(self.__controller.MostActiveClients())
                    except Exception as x:
                        print(x)
                    continue
                print("Invalid command!")
                continue
            if(command==9):
                print(self.__controller.Undo())
                continue
            if(command==10):
                print(self.__controller.Redo())
                continue
            print("Invalid command!")
    