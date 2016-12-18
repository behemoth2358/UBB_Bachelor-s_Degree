from functions.functions import *
from data.data import *
import datetime
from copy import *

def read_commands():
    cmd=input("Insert a command:")
    print(cmd)
    pos=cmd.find(" ")
    if pos==-1:
        return (cmd,"")
    command=cmd[:pos]
    args=cmd[(pos+1):]
    args=args.split(' ')
    return (command,args)
    
def run_app():
    history=[]
    undoStack=[]
    runTests()
    insertData(history)
    while True:
        print("Type 'help' to see available commands.")
        (command,args)=read_commands()
        if command=="exit":
            break
        if command=="help":
            helpp()
            continue
        if command=="add":
            print(ui_add_transaction(history,args))
            update_undo(undoStack,history)
            continue
        if command=="insert":
            print(ui_insert_transaction(history,args))
            update_undo(undoStack,history)
            continue
        if command=="list":
            print(ui_list(history,args))
            continue
        if command=="remove":
            print(ui_remove(history,args))
            update_undo(undoStack,history)
            continue
        if command=="replace":
            print(ui_replace(history,args))
            update_undo(undoStack,history)
            continue
        if command=="sum":
            print(ui_sum(history,args))
            continue
        if command=="max":
            print(ui_max(history,args))
            continue
        if command=="filter":
            print(ui_filter(history,args))
            update_undo(undoStack,history)
            continue
        if command=="undo":
            print(ui_undo(history,undoStack))
            continue
        print("Invalid command")

def ui_add_transaction(history,args):
    try:
        if args[1]!="in" and args[1]!="out":
            return "Invalid command"
        insert_transaction(history,datetime.datetime.now().day,int(args[0]),args[1],args[2])
    except:
        return "Invalid command"
    return "Done!"
        
def ui_insert_transaction(history,args):
    try:
        if int(args[0]) > 31 or int(args[0]) < 1:
            return "Invalid day"
        try:
            if args[2]!="in" and args[2]!="out":
                return "Invalid command"
            insert_transaction(history,int(args[0]),int(args[1]),args[2],args[3])
        except:
            return "Invalid command"
    except:
        return "Invalid command"
    return "Done!"

def ui_list(history,args):
    if len(args)==0:
        return show(history,args,noCondition)
    if args[0]=="in" or args[0]=="out":
        return show(history,args,typeCondition)
    if args[0]=="=" or args[0]==">" or args[0]=="<":
        try:
            int(args[1])
        except:
            return "Invalid command"
        return show(history,args,comparasionCondition)
    if args[0]=="balance":
        try:
            return ("The balance for day "+args[1]+" is "+str(balance(history,int(args[1]))))
        except:
            return "Invalid command"
    return "Invalid command"

def ui_remove(history,args):
    if len(args)==1:
        if args[0]=="in" or args[0]=="out":
            type_remove(history,args[0])
            return "Done!"
        else:
            try:
                day_remove(history,int(args[0]),int(args[0]))
                return "Done!"
            except:
                return "Invalid command"
        return
    if len(args)==3:
        try:
            day_remove(history,int(args[0]),int(args[2]))
            return "Done!"
        except:
            return "Invalid command"
    return "Invalid command"

def ui_replace(history,args):
    try:
        replace(history,int(args[0]),args[1],args[2],int(args[4]))
    except:
        return "Invalid command"
    return "Done!"

def ui_sum(history,args):
    if len(args)==0:
        return "Invalid command"
    if args[0]=="in" or args[0]=="out":
        return "Sum is "+str(ssum(history,args[0]))
    return "Invalid command"

def ui_max(history,args):
    if len(args)!=2:
        return "Invalid command"
    try:
        m=mmax(history,args[0],int(args[1]))
        if m==-999999999999:
            return ("There's no transaction on day"+args[1])
        return "Max is "+str(m)
    except:
        return "Invalid command"
    
def ui_filter(history,args):
    if len(args)==0:
        return "Invalid command"
    type_filter(history,args[0])
    if len(args)==2:
        try:
            value_filter(history,int(args[1]))
        except:
            return "Invalid command"
    return "Done!"
####################UNDO##########################
'''
Undo the last operation made
'''
def ui_undo(history,undoStack):
    if len(undoStack)==0:
        return "Impossible"
    undoStack.pop()
    while(len(history)>0):
        history.pop()
    if len(undoStack)>0:
        for it in undoStack[ len(undoStack)-1 ]:
            history.append(deepcopy(Transaction(deepcopy(it.get_day()),deepcopy(it.get_value()),deepcopy(it.get_typ()),deepcopy(it.get_description()))))
    return "Done!"

def helpp():
    print("Enter: 'add <value> <type> <description>' to add a value")
    print("Enter: 'insert <day> <value> <type> <description>' to insert a value")
    print("Enter: 'remove <day>' to remove all transactions made in a day")
    print("Enter: 'remove <start day> to <end day>' to remove all transactions made between 2 days")
    print("Enter: 'remove <type>' to remove all in/out transactions made this month")
    print("Enter: 'replace <day> <type> <description> with <value>' to replace the value of a transaction")
    print("Enter: 'list' to see all the transactions")
    print("Enter: 'list [ < | = | > ] <value>' to see all transactions greater/equal/lower than a given value")
    print("Enter: 'list balance <day>' to see the balance until a day")
    print("Enter: 'sum <type>' to see the sum of all in/out transactions")
    print("Enter: 'max <type> <day>' to see the transaction with the maximum sum on a given day")
    print("Enter: 'filter <type>' to keep only in/out transaction")
    print("Enter: 'filter <type> <value>' to keep only in/out transaction with value lower than a given value")
    print("Enter: 'undo' to undo a operation")
    print("Enter: 'exit' the exit")
def insertData(history):
    ui_insert_transaction(history,[1,300,"out","food"])
    ui_insert_transaction(history,[3,40,"out","beer"])
    ui_insert_transaction(history,[6,800,"out","clothes"])
    ui_insert_transaction(history,[8,500,"out","gas"])
    ui_insert_transaction(history,[11,30,"out","internet"])
    ui_insert_transaction(history,[11,20,"out","tv"])
    ui_insert_transaction(history,[14,4500,"in","salary"])
    ui_insert_transaction(history,[16,1000,"in","bonus"])
    ui_insert_transaction(history,[19,400,"out","food"])
    ui_insert_transaction(history,[22,200,"out","beer"])
    ui_insert_transaction(history,[29,200,"out","dentist"])
    
def runTests():
    test_insert_transaction()
    test_list()
    test_remove()
    test_replace()
    test_sum()
    test_max()
    test_filter()
    test_balance()
    
def test_insert_transaction():
    test=[]
    insert_transaction(test,1,1,"in","test")
    assert Transaction(1,1,"in","test") in test
    
def test_list():
    test=[]
    assert show(test,"",noCondition) == "The list is empty."
    insert_transaction(test,1,1,"in","test1")
    assert show(test,["in"],typeCondition) == "Day:1 Value:1 Type:in Description:test1\n"
    insert_transaction(test,3,10,"out","test2")
    assert show(test,[">","3"],comparasionCondition) == "Day:3 Value:10 Type:out Description:test2\n"
    
def test_remove():
    test=[]
    insert_transaction(test,1,1,"in","test1")
    insert_transaction(test,2,2,"out","test2")
    insert_transaction(test,3,3,"out","test3")
    insert_transaction(test,4,4,"out","test4")
    type_remove(test,"out")
    assert not(Transaction(2,2,"out","test2") in test)
    insert_transaction(test,2,2,"out","test2")
    insert_transaction(test,3,3,"out","test3")
    insert_transaction(test,4,4,"out","test4")
    day_remove(test,2,4)
    for T in test:
        assert not(T.day >= 2 and T.day <= 4)
        
def test_replace():
    test=[]
    insert_transaction(test,1,1,"in","test1")
    replace(test,1,"in","test1",2)
    assert ((Transaction(1,2,"in","test1") in test) and not(Transaction(1,1,"in","test1") in test))
    
def test_balance():
    test=[]
    insert_transaction(test,1,1,"in","test1")
    assert balance(test,1)==1
    insert_transaction(test,2,1,"out","test2")
    assert balance(test,2)==0
    insert_transaction(test,3,10,"in","test3")
    assert balance(test,3)==10
    
def test_sum():
    test=[]
    insert_transaction(test,1,1,"in","test1")
    insert_transaction(test,2,2,"out","test2")
    assert (ssum(test,"in")==1 and ssum(test,"out")==2)
    
def test_max():
    test=[]
    insert_transaction(test,1,1,"in","test1")
    insert_transaction(test,1,2,"in","test2")
    assert mmax(test,"in",1)==2
    
def test_filter():
    test=[]
    insert_transaction(test,1,1,"in","test1")
    insert_transaction(test,1,2,"out","test2")
    type_filter(test,"out")
    for T in test:
        assert T.typ=="out"
    insert_transaction(test,1,1,"in","test1")
    value_filter(test,2)
    for T in test:
        assert T.value<2