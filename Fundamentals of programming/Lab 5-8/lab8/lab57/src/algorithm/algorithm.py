def swap(a,b):
    a,b=b,a

def MaxHeapCompare(a,b):
    return a < b

def MinHeapCompare(a,b):
    return a > b

class Heap:
    def __init__(self,comp=MinHeapCompare):
        self.__heap=[]
        self.__cmp=comp

    def push(self,value):
        self.__heap.append(value)
        v=len(self.__heap)-1
        while(v!=0):
            if(self.__cmp(self.__heap[(v-1)//2],self.__heap[v])):
                self.__heap[v],self.__heap[(v-1)//2]=self.__heap[(v-1)//2],self.__heap[v]
                v=(v-1)//2
            else:
                break

    def __len__(self):
        return len(self.__heap)

    def top(self):
        if(len(self.__heap)==0):
            return "Heap is empty!"
        return self.__heap[0]

    def pop(self):
        self.__heap[0],self.__heap[ len(self.__heap)-1 ]=self.__heap[ len(self.__heap)-1 ],self.__heap[0]
        self.__heap.pop()
        v=0
        while(True):
            if(2*v+1 >= len(self.__heap)):
                return
            
            if(2*v+2 >= len(self.__heap)):
                if(self.__cmp(self.__heap[v],self.__heap[2*v+1])):
                    self.__heap[v],self.__heap[2*v+1]=self.__heap[2*v+1],self.__heap[v]
                    v=2*v+1
                    continue
                return
            
            if(self.__cmp(self.__heap[v],self.__heap[2*v+1]) and self.__cmp(self.__heap[2*v+2],self.__heap[2*v+1])):
                self.__heap[v],self.__heap[2*v+1]=self.__heap[2*v+1],self.__heap[v]
                v=2*v+1
                continue
            
            if(self.__cmp(self.__heap[v],self.__heap[2*v+2])):
                self.__heap[v],self.__heap[2*v+2]=self.__heap[2*v+2],self.__heap[v]
                v=2*v+2
                continue
            return


def heapSort(v,comp=MinHeapCompare):
    H=Heap(comp)
    while(len(v)!=0):
        H.push(v[ len(v)-1 ])
        v.pop()
    while(len(H)!=0):
        v.append(H.top())
        H.pop()