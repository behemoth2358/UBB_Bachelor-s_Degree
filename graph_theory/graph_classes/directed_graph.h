#ifndef DIRECTED_GRAPH_H
#define DIRECTED_GRAPH_H

#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <stdexcept>

template<typename T>
class directed_graph {

    protected:

        std::map< T, std::set< T > > outNeighbours;
        std::set< T > vertices;

    public:

        directed_graph(std::vector< T > vertices) {
            for(auto it: vertices)
                this->vertices.insert(it);
        }

        directed_graph(std::set< T > vertices) {
            this->vertices = vertices;
        }

        std::set<T> getVertices() {
            return vertices;
        }

        directed_graph(){}

        ~directed_graph(){}

        void addVertex(T v) {
            vertices.insert(v);
        }

        bool isGoodVertex(T v) {
            return vertices.find(v) != vertices.end();
        }

        void removeVertex(T v) {
            if(isGoodVertex(v) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }
            vertices.erase(v);
            for(auto it: vertices) {
                if(outNeighbours[it].find(v) != outNeighbours[it].end()) {
                    outNeighbours[it].erase(v);
                }
            }
            outNeighbours.erase(v);
        }

        void addEdge(T v1, T v2) {//adds an edge between vertices v1 and v2 if they are valid, otherwise will throw an exception
            if(isGoodVertex(v1) == false || isGoodVertex(v2) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }

            outNeighbours[v1].insert(v2);
        }

        bool isEdge(T v1, T v2) { // returns true if it's a edge between vertices v1 and v2, if they are not valid will throw an exception
            if(isGoodVertex(v1) == false || isGoodVertex(v2) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }
            return (outNeighbours[v1].find(v2) != outNeighbours[v1].end());
        }

        void removeEdge(T v1, T v2) {// removes the edge between vertices v1 and v2, if they are not valid will throw an exception
            if(isGoodVertex(v1) == false || isGoodVertex(v2) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }
            outNeighbours[v1].erase(v2);
        }

        unsigned int size() {//returns the number of vertices
            return vertices.size();
        }

        unsigned int degree(T v) {//returns the internal degree of vertex v, if v is not a valid will throw an exception
            if(isGoodVertex(v) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }
            return outNeighbours[v].size();
        }

        std::set<T> getNeighbours(T v) {//returns a set with the neighbours of vertex v, if v is not valid will throw an exception
            if(isGoodVertex(v) == false) {
                throw std::invalid_argument("Invalid vertex!");
            }
            return outNeighbours[v];
        }
};

#endif
