#ifndef IO_DIRECTED_GRAPH_H
#define IO_DIRECTED_GRAPH_H

#include <stdexcept>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include "directed_graph.h"

template<typename T>
class io_directed_graph: public directed_graph<T>{
    protected:
        std::map< T, std::set< T > > inNeighbours;
    public:
        io_directed_graph(){}

        io_directed_graph(std::vector<T> vertices) {
            for(auto it: vertices) {
                this->vertices.insert(it);
            }
        }

        io_directed_graph(std::set< T > vertices) {
            this->vertices = vertices;
        }

        void removeVertex(T v) {
            directed_graph<T>::removeVertex(v);

            for(auto it: this->vertices) {
                if(inNeighbours[it].find(v) != inNeighbours[it].end()) {
                    inNeighbours[it].erase(v);
                }
            }
            inNeighbours.erase(v);
        }


        void addEdge(T v1, T v2) {//adds an edge between vertices v1 and v2 if they are valid, otherwise will throw an exception
            directed_graph<T>::addEdge(v1,v2);
            inNeighbours[v2].insert(v1);
        }

        void removeEdge(T v1, T v2) {// removes the edge between vertices v1 and v2, if they are not valid will throw an exception
            directed_graph<T>::removeEdge(v1,v2);
            inNeighbours[v2].erase(v1);
        }

        std::set<T> getOutNeighbours(T v) {//returns a set with the internal neighbours of vertex v, if v is not valid will throw an exception

            return directed_graph<T>::getNeighbours(v);
        }

        std::set<T> getInNeighbours(T v) {//returns a set with the external neighbours of vertex v, if v is not valid will throw an exception
            if(directed_graph<T>::isGoodVertex(v) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }
            return inNeighbours[v];
        }

        unsigned int outDegree(T v) {//returns the internal degree of vertex v, if v is not a valid will throw an exception

            return directed_graph<T>::degree(v);
        }

        unsigned int inDegree(T v) {//returns the external degree of vertex v, if v is not a valid will throw an exception

            if(directed_graph<T>::isGoodVertex(v) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }
            return inNeighbours[v].size();
        }

};

#endif
