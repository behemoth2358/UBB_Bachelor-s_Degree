'''
Created on Dec 20, 2016

@author: bogdan
'''
class ui:
    def __init__(self,controller):
        self.__controller=controller
        
    def runApp(self):
        while(True):
            x=input("\nEnter 0 to exit\nEnter 1 to add a taxi driver\nEnter 2 to add a order\nEnter 3 for income of a taxi driver\nEnter 4 to see all taxi drivers\nEnter 5 to see all orders\nEnter 6 for stats\nYour command:")
            if(x=='1'):
                ID=input("ID=")
                name=input("Name=")
                try:
                    self.__controller.AddDriver(ID,name)
                except:
                    print("Invalid command!")
                    continue
                print("Done!\n")
                continue
            if(x=='2'):
                ID=input("ID=")
                distance=input("Distance=")
                try:
                    distance=int(distance)
                    self.__controller.AddOrder(ID,distance)
                except:
                    print("Invalid distance or ID!")
                    continue
                print("Done!")
                continue
            if(x=='3'):
                x=input("Taxi Driver ID=")
                try:
                    income=self.__controller.GetIncome(x)
                    name=self.__controller.GetName(x)
                    print("Name:"+str(name)+" Income:"+str(income)+"\n")
                except:
                    print("Invalid ID!")
                    continue
                continue
            if(x=='4'):
                print(self.__controller.ShowAllDrivers())
                continue
            if(x=='5'):
                print(self.__controller.ShowAllOrders())
                continue
            if(x=='6'):
                print(self.__controller.Stats())
                continue
            if(x=='0'):
                break
            print("Invalid command!\n")