from copy import deepcopy
def backtracking(sum,coins,sol):
    if( sum < 0 ):
        return
    if(sum==0):
        print(sol)
        return
    for it in coins:
        sol.append(it)
        backtracking(sum-it,coins,sol)
        sol.pop()
        
def backtracking_it(sum,coins):
	stack=[]
	stack.append( [sum,[] ] ) # bag initial in stiva suma si un vector gol in care voi genera solutiile
	while( len(stack)>0 ): # cat timp am elemente in stiva
		x=stack[ len(stack)-1 ] # iau ultimul element
		stack.pop() # il sterg din stiva
		sum=x[0] 
		sol=x[1]
		if(sum<0): # daca suma e mai mica decat 0 nu ma mai intereseaza
			continue
		if(sum==0): # daca e 0 afisez solutia
			print(sol)
			continue
		for it in coins: # parcurg toate monezile
			sol.append(it) # adaug la solutie
			stack.append( [sum-it,deepcopy(sol)] ) # bag in stiva
			sol.pop() # si refac vectorul sol 

backtracking_it(14,[3,7,10])
