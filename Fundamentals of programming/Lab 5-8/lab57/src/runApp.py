'''
Created on Nov 14, 2016

@author: bogdan
'''
from repo.FileBookRepository import *
from repo.FileClientRepository import *
from repo.FileRentalRepository import *
from controller.undocontroller import *
from ui.ui import *

def addBooks(repo):
    repo.AddBook("12B","Crime and punishment","Psychological novel","Dostoievsky")
    repo.AddBook("13B","Brothers Karamazov","Psychological novel","Dostoievsky")
    repo.AddBook("14B","The idiot","Psychological novel","Dostoievsky")
    repo.AddBook("15C","Master and Margarita","Science-Fiction","Bulgakov")
    repo.AddBook("16E","War and peace","Historical novel","Tolstoy")
    repo.AddBook("16D","Anna Karenina","Psychological novel","Tolstoy")
    repo.AddBook("17A","Faust","Science-Fiction","Goethe")
    repo.AddBook("11D","Lolita","Psychological novel","Nabokov")
    repo.AddBook("11H","The last night of love, the first night of war","Psychological novel","Camil Petrescu")

def addClients(repo):
    repo.AddClient("1A","Stefan Gheorghidiu")
    repo.AddClient("1C","Andrei Pietraru")
    repo.AddClient("1F","Stefan Tipatescu")
    repo.AddClient("2D","Rodion Raskolnikov")
    repo.AddClient("3F","Lev Myshkin")
    repo.AddClient("4F","Fyodor Karamazov")
    repo.AddClient("5F","Alexey Karamazov")
    repo.AddClient("6F","Dmitry Karamazov")
    repo.AddClient("7F","Ivan Karamazov")
    repo.AddClient("9F","Dolores Haze")
    repo.AddClient("10F","Anna Karenina")
    repo.AddClient("11F","Alexey Vronski")
    repo.AddClient("12F","Piotr Bezukhov")
    repo.AddClient("13F","Katerina Ivanovna")

def addRentals(repo):
    repo.AddRental("1","12B","1A",datetime(2016,5,12),datetime(2016,5,15))
    repo.AddRental("2","15C","1C",datetime(2016,5,12),datetime(2016,5,13))
    repo.AddRental("3","17A","1F",datetime(2016,5,12),datetime(2016,5,14))
    repo.ReturnBook("2",datetime(2016,5,20))
    repo.AddRental("4","15C","6F",datetime(2016,5,21),datetime(2016,5,22))

def addData(repo):
    addBooks(repo)
    addClients(repo)
    addRentals(repo)

BookRepo=FileBookRepository()
ClientRepo=FileClientRepository()
RentalRepo=FileRentalRepository()

cont=UndoController(BookRepo,ClientRepo,RentalRepo)

#addData(cont)

ui=UI(cont)
ui.menu()