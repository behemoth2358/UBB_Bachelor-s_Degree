'''
Created on Nov 14, 2016

@author: bogdan
'''
from repo.BookRepository import *
from repo.ClientRepository import *
from repo.RentalRepository import *

from repo.FileBookRepository import *
from repo.FileClientRepository import *
from repo.FileRentalRepository import *

from repo.PickleBookRepository import *
from repo.PickleClientRepository import *
from repo.PickleRentalRepository import *

from Settings.Settings import *

from controller.undocontroller import *

from ui.ui import *


settings=Settings("/home/bogdan/Documents/lab57/src/settings.properties")
print(settings.repository())


if(settings.repository()=="inmemory"):
    BookRepo=BookRepository()
    ClientRepo=ClientRepository()
    RentalRepo=RentalRepository()

if(settings.repository()=="file"):
    BookRepo=FileBookRepository( settings.books() )
    ClientRepo=FileClientRepository( settings.clients() )
    RentalRepo=FileRentalRepository( settings.rentals() )

if(settings.repository()=="pickle"):
    BookRepo=PickleBookRepository( settings.books() )
    ClientRepo=PickleClientRepository( settings.clients() )
    RentalRepo=PickleRentalRepository( settings.rentals() )


cont=UndoController(BookRepo,ClientRepo,RentalRepo)

ui=UI(cont)
ui.menu()