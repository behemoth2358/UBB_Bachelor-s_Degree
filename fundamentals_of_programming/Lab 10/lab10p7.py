from copy import deepcopy

def backtracking(step,n,arr):
        if(step==2*n):
                if( abs(arr[2*n] - arr[2*n-1]) ):
                        print(arr)
                return
        for it in [-1,0,1]:
                if( abs(it-arr[step-1]) ):
                        arr[step]=it
                        backtracking(step+1,n,arr)



def backtracking_it(n):
        arr=[0]*(2*n+1)
        stack=[]
        stack.append( [1,deepcopy(arr)] )
        while( len(stack) ):
                x=stack[ len(stack)-1 ]
                stack.pop()
                step=x[0]
                arr=x[1]
                if(step==2*n):
                        if( abs(arr[2*n] - arr[2*n-1]) ):
                                print(arr)
                        continue
                for it in [-1,0,1]:
                        if( abs(it-arr[step-1]) ):
                                arr[step]=it
                                stack.append( [step+1,deepcopy(arr)] )

n=2
arr=[0]*(2*n+1)
print("Recursiv:")
backtracking(1,n,arr)
print("Iterativ:")
backtracking_it(n)
