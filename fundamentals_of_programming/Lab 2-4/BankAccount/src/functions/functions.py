from data.data import *
import datetime
from copy import *

def insert_transaction(history,day,value,typ,description):
    history.append(Transaction(day,value,typ,description))
#################LIST###############################
'''
Prints all the transactions which match the condition
Parameters: history - the list of all transactions, args - arguments for comparasion, cond - comparasion method
'''
def show(history,args,cond):
    if len(history)==0:
        return "The list is empty."
    screen=""
    for T in history:
        if(cond(T,args)):
            screen+=str(T)
            screen+="\n"
    return screen
            
def noCondition(x,args):
    return True

def typeCondition(x,args):
    return x.typ==args[0]

def comparasionCondition(x,args):
    if args[0]=="=":
        return x.value==int(args[1])
    if args[0]==">":
        return x.value > int(args[1])
    return x.value < int(args[1])
'''
Prints the balance on day "day"
Parameters: history - the list of all transactions, day - the day until the balance will be calculated
'''
def balance(history,day):
    s=0
    for it in history:
        if it.day<=day:
            if it.typ=="in":
                s+=it.value
            else:
                s-=it.value
    return s
'''
Removes elements with type typ
Parameters: history - the list of all transactions, typ - type of the transtractions who will be removed
'''
def type_remove(history,typ):
    for it in range(len(history)-1,-1,-1):
        if history[it].typ==typ:
            del history[it]
'''
Removes all the transactions from day start_day to day end_day
Parameters: history - the list of all transactions, start_day and end_day the days between all the transactions will be removed
'''
def day_remove(history,start_day,end_day):
    for it in range(len(history)-1,-1,-1):
        if start_day <= history[it].day and history[it].day <= end_day:
            del history[it]
###############REPLACE############################
'''
Replace the value of transactions from day "day" with type "typ" and description "description" with value "value"
Parameters: day - the day of the transactions that will be modified, typ - the type of the transactions that will be modified, description - the description of the transaction that will be modified, value - the value that will be assigned to the modified transactions
'''
def replace(history,day,typ,description,value):
    for it in range(0,len(history)):
        if history[it].day==day and history[it].typ==typ and history[it].description:
            history[it].modify_value(value)
#############SUM################################
'''
Print the sum of all in or out transactions
Parameters: history - the list of all transactions, typ - the type of transactions that will be considered for the sum
'''
def ssum(history,typ):
    s=0
    for it in history:
        if it.typ==typ:
            s+=it.value
    return s
##################MAX#############################
'''
Print the transaction from day "day" with the maximum value
Parameters: history - the list of all transactions, typ - the type of the transactions that will be considered, day - the day of the transactions that will be considered
'''
def mmax(history,typ,day):
    mx=-99999999999
    for it in history:
        if it.typ==typ and it.day==day and it.value > mx:
            mx=it.value
    return mx
###################FILTER#########################
'''
Keeps only transactions with type "typ"
Parameters: history- the list of all transactions, typ - the type of the transactions that will be kept
'''
def type_filter(history,typ):
    if typ=="in":
        return type_remove(history,"out")
    if typ=="out":
        return type_remove(history,"in")
    return "Invalid command"
'''
Keeps only transactions with value smaller than "value"
Parameters: history - the list of all transactions, value - integer
'''
def value_filter(history,value):
    for it in range(len(history)-1,-1,-1):
        if history[it].value >= value:
            del history[it]
###############undo##################
def update_undo(undoStack,history):
    undoStack.append([])
    for it in history:
        undoStack[ len(undoStack)-1 ].append(deepcopy(Transaction(deepcopy(it.get_day()),deepcopy(it.get_value()),deepcopy(it.get_typ()),deepcopy(it.get_description()))))