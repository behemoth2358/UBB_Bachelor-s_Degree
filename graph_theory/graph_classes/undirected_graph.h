#ifndef UNDIRECTED_GRAPH_H
#define UNDIRECTED_GRAPH_H

#include "directed_graph.h"
#include <set>
#include <map>
#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
class undirected_graph: public directed_graph<T>{
    public:
        undirected_graph(){}

        ~undirected_graph(){}

        undirected_graph(std::vector<T> vertices)
        {
            for(auto it: vertices)
                this->vertices.insert(it);
        }

        undirected_graph(std::set<T> vertices)
        {
            this->vertices=vertices;
        }

        void addEdge(T v1, T v2)//adds an edge between vertices v1 and v2 if they are valid, otherwise will throw an exception
        {
            directed_graph<T>::addEdge(v1,v2);
            directed_graph<T>::addEdge(v2,v1);
        }

        void removeEdge(T v1, T v2)// removes the edge between vertices v1 and v2, if they are not valid will throw an exception
        {
            directed_graph<T>::removeEdge(v1,v2);
            directed_graph<T>::removeEdge(v2,v1);
        }
};


#endif
