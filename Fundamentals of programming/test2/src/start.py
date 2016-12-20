'''
Created on Dec 20, 2016

@author: bogdan
'''
from domain.entities import *
from repo.FileRepository import *
from ui.ui import *
from controller.Controller import *

Dr=FileDriverRepository()
Or=FileOrderRepository()
cont=Controller(Dr,Or)
UI=ui(cont)
UI.runApp() 