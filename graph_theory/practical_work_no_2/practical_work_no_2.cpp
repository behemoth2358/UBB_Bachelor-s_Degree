#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <queue>
#include <map>

#include "undirected_graph.h"


template<typename T>
std::set<T> accesible_nodes(undirected_graph<T> G, T start_node) {
	/*
	Returns an set with the nodes reached using breath-first search algorithm
	Parameters: an undirected_graph and a start node
	*/
	std::set<T> nodes;
	nodes.insert( start_node );
	std::queue<T> Q;
	Q.push( start_node );
	while(!Q.empty()) {
		T v = Q.front();
		Q.pop();
		for(auto it: G.getNeighbours(v)) {
			if(nodes.find(it) == nodes.end()) {
				nodes.insert(it);
				Q.push(it);
			}
		}
	}
	return nodes;
}



template<typename T>
std::vector< std::set<T> > connected_components(undirected_graph<T> G) {
	/*
	Returns a vector with sets who contain the components
	Parameters: An undirected graph
	*/
	std::vector< std::set<T> > components;
	std::set<T> vertices = G.getVertices();
	std::map<T, bool> isChecked;
	for(auto v: vertices)
	if(isChecked[v] == false) {
		std::set<T> aux = accesible_nodes(G, v);
		components.push_back( aux );
		for(auto it: aux) {
			isChecked[it] = true;
		}
	}
	return components;
}

int main(int argc, char **args) {
    std::ifstream in(args[1]);

    int n,m;
    in>>n>>m;
    std::vector<int> v;
    for(int i = 0;i < n; i++) {
    	v.push_back(i);
    }
    undirected_graph<int> G(v);
    for(;m;m--) {
        int x,y,z;
        in>>x>>y>>z;
        G.addEdge(x,y);
    }
    in.close();

    std::vector< std::set<int> > components = connected_components<int>( G );

    std::cout<<"Number of components: "<<components.size()<<'\n';
    for(size_t i = 0; i < components.size(); i++) {
    	std::cout<<"\nComponent #"<<i + 1<<"\n\n";

    	std::cout<<"Nodes:";
    	for(auto v: components[ i ])
    		std::cout<<' '<<v;
    	std::cout<<"\n\n";

    	for(auto v: components[ i ]) {
    		for(auto it: G.getNeighbours(v)) {
    			std::cout<<v<<' '<<it<<'\n';
    		}
    	}
    }
	return 0;
}
