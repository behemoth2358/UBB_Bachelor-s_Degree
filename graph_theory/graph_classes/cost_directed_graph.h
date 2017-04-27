#ifndef COST_DIRECTED_GRAPH_H
#define COST_DIRECTED_GRAPH_H

#include <vector>
#include <map>
#include <algorithm>
#include <stdexcept>
#include "directed_graph.h"

template<typename T,typename C>
class cost_directed_graph: public directed_graph<T>{
    protected:
        std::map< std::pair< T, T > , C > cost;
    public:
        cost_directed_graph(){}

        cost_directed_graph(std::set<T> vertices) {
            this->vertices = vertices;
        }

        cost_directed_graph(std::vector<T> vertices) {
            for(auto it: vertices) {
                this->vertices.insert(it);
            }
        }

        void addEdge(T v1, T v2, C c) {//adds an edge between vertices v1 and v2 with cost C if they are valid, otherwise will throw an exception
            directed_graph<T>::addEdge(v1,v2);
            cost[ std::make_pair(v1,v2) ]=c;
        }

        void removeEdge(T v1, T v2){// removes the edge between vertices v1 and v2, if they are not valid will throw an exception
            directed_graph<T>::removeEdge(v1,v2);
            cost.erase( std::make_pair(v1,v2) );
        }

        void setCost(T v1, T v2, C c) {//sets cost of edge between v1 and v2 to c, if they are not valid vertices will throw an exception

            if(directed_graph<T>::isGoodVertex(v1) == false || directed_graph<T>::isGoodVertex(v2) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }
            if(directed_graph<T>::isEdge(v1,v2) == false) {
                throw std::invalid_argument("Invalid edge!");
            }
            cost[ std::make_pair(v1,v2) ] = c;
        }

        C getCost(T v1, T v2) {//returns the cost between vertices v1 and v2, if they are not valid will throw an exception

            if(directed_graph<T>::isGoodVertex(v1) == false || directed_graph<T>::isGoodVertex(v2) == false){
                throw std::invalid_argument("Invalid vertex!");
            }
            if(directed_graph<T>::isEdge(v1,v2) == false) {
                throw std::invalid_argument("Invalid edge!");
            }
            return cost[ std::make_pair(v1,v2) ];
        }
};

#endif
