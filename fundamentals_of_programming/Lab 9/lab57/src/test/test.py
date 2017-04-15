'''
Created on Nov 22, 2016

@author: bogdan
'''
from domain.book import *
from domain.client import *
from domain.rental import *
from datetime import datetime
from controller.controller import *
from repo.Repository import *
import unittest

class TestController(unittest.TestCase):
    def setUp(self):
        self.br=BookRepository()
        self.cr=ClientRepository()
        self.rr=RentalRepository()
        self.test=controller(self.br,self.cr,self.rr)

    def test_AddBook(self):
        self.test.AddBook("1","1","1","1")
        self.assertEqual(self.test.ShowAllBooks(),"\nTitle: 1\nAuthor: 1\nBook ID: 1\nDescription: 1\n\n")
        self.assertRaises(RepositoryException,self.test.AddBook,"1","2","2","2")
        self.assertRaises(RepositoryException,self.test.AddBook,"1","1","1","1")
        self.test.RemoveBook(1,"1")
    
    def test_AddClient(self):
        self.test.AddClient("1","1")
        self.assertEqual(self.test.ShowAllClients(),"\nClient name:1\nClient ID: 1\n\n")
        self.assertRaises(RepositoryException,self.test.AddClient,"1","2")
        self.assertRaises(RepositoryException,self.test.AddClient,"1","3")
        self.test.RemoveClient(1,"1")
        
    def test_RemoveBook(self):
        self.test.AddBook("1","1","1","1")
        self.test.RemoveBook(1,"1")
        self.assertEqual(self.test.ShowAllBooks(),"The list is empty!\n")
    
    def test_ModifyBook(self):
        self.test.AddBook("1","1","1","1")
        self.test.ShowAllBooks()
        self.test.ModifyBook(1,"1",book("","2","",""))
        self.test.ShowAllBooks()
        self.assertEqual(self.test.ShowAllBooks(),"\nTitle: 2\nAuthor: 1\nBook ID: 1\nDescription: 1\n\n")
        self.test.RemoveBook(1,"1")
    
    def test_RemoveClient(self):
        self.test.AddClient("1","1")
        self.test.RemoveClient(1,"1")
        self.assertEqual(self.test.ShowAllClients(),"The list is empty!\n")
    
    def test_ModifyClient(self):
        self.test.AddClient("1","1")
        self.test.ModifyClient(1,"1",client("","2"))
        self.assertEqual(self.test.ShowAllClients(),"\nClient name:2\nClient ID: 1\n\n")
        self.test.RemoveClient(1,"1")
    
    def test_ShowAllClients(self):
        self.test.AddClient("2","1")
        self.assertEqual(self.test.ShowAllClients(),"\nClient name:1\nClient ID: 2\n\n")
        self.test.RemoveClient(1,"2")
    
    def test_ShowAllBooks(self):
        self.test.AddBook("1","1","1","1")
        #print(self.test.ShowAllBooks())
        self.assertEqual(self.test.ShowAllBooks(),"\nTitle: 1\nAuthor: 1\nBook ID: 1\nDescription: 1\n\n")
        self.test.RemoveBook(1,"1")
    
    def test_SearchBooks(self):
        self.test.AddBook("1","1","1","1")
        self.assertEqual(self.test.SearchBooks('1','1'),"\nTitle: 1\nAuthor: 1\nBook ID: 1\nDescription: 1\n")
        self.assertEqual(self.test.SearchBooks('1','2'),"No books with ID=2")
        self.test.RemoveBook(1,"1")
    
    def test_MostRentedBooks(self):
        self.test.AddBook("1","1","1","1")
        self.test.AddClient("1","1")
        self.test.AddRental("1","1","1",datetime(2016,10,19),datetime(2016,10,20))
        self.assertEqual(self.test.MostRentedBooks(),"\nTitle: 1\nAuthor: 1\nBook ID: 1\nDescription: 1\nTimes rented:1\n")
    
    def test_LateRentals(self):
        self.assertEqual(self.test.LateRentals(),"")
    
    def testMostRentedAuthor(self):
        self.assertEqual(self.test.MostRentedAuthor(),"")
    
    def test_MostActiveClients(self):
        self.assertEqual(self.test.MostActiveClients(),"")
    '''
    def RunAllTests(self):
        self.testAddBook()
        self.testAddClient()
        self.testRemoveBook()
        self.testRemoveClient()
        self.testModifyBook()
        self.testModifyClient()
        self.testShowAllBooks()
        self.testShowAllClients()
        self.testMostRentedBooks()
        self.testLateRentals()
        self.testMostRentedAuthor()
        self.testMostActiveClients()
'''

if __name__ == "__main__":
    unittest.main()