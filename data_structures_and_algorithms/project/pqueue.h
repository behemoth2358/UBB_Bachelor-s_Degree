#ifndef PQUEUE_H
#define PQUEUE_H

#include <vector>

template<typename DataType>
class PQueue{
private:
    std::vector< DataType > heap;

    void swap(DataType& x, DataType& y) {
        DataType z = y;
        y = x;
        x = z;
    }

    bool(*comp)(DataType, DataType);

public:

    PQueue(bool(*c)(DataType, DataType)){
        this->comp = c; 
    }

    void push(DataType value) {//push a element in heap
        heap.push_back(value);
        for(int v = heap.size()-1 ; v != 0; v = (v-1)/2) {
            if (this->comp(heap[ v ], heap[ (v-1)/2 ]))
                swap(heap[ v ],heap[ (v-1)/2 ]);
            else
                break;
        }
    }

    unsigned int size() {//number of elements in heap
        return heap.size();
    }

    DataType top() {//return the top of the heap
        return heap[ 0 ];
    }


    bool empty() {
        return heap.size() == 0;
    }

    void pop() {//delete the top of the heap
        swap(heap[ 0 ],heap[ heap.size()-1 ]);
        heap.pop_back();
        int v = 0;
        while(true) {
            if ((2*v+1 < (int)heap.size() && this->comp(heap[ 2*v+1 ], heap[ v ])) && (2*v+2 >= (int)heap.size() || !this->comp(heap[ 2*v+2 ], heap[ 2*v+1 ]))) {
                swap(heap[ v ], heap[ 2*v+1 ]);
                v = 2*v+1;
                continue;
            }
            if ((2*v+2 < (int)heap.size() && this->comp(heap[ 2*v+2 ], heap[ v ]) && this->comp(heap[ 2*v+2 ], heap[ 2*v+1 ]))) {
                swap(heap[ v ], heap[ 2*v+2 ]);
                v = 2*v+2;
                continue;
            }
            break;
        }
    }
};

#endif
