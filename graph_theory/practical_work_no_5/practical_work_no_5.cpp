/*
	Given an undirected graph, find a vertex cover of minimum size.
*/

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <limits>
#include <numeric>

#include "../graph_classes/undirected_graph.h"

template<typename T>
bool _is_vertex_cover(undirected_graph<T>& G, std::set<T> nodes) {
	for(auto x: G.getVertices()){
		if(nodes.find(x) == nodes.end()) {
			for(auto y: G.getNeighbours(x)) {
				if(nodes.find(y) == nodes.end()) {
					return false;
				}
			}
		}
	}
	return true;
}

template<typename T>
void _compute_possible_vertex_covers(undirected_graph<T>& G, std::set<T>& res, int pos = 0, std::set<T> nodes = std::set<T>()) {
	std::vector<T> vertices;
	for(auto it: G.getVertices()) {
		vertices.push_back(it);
	}

	if(pos == vertices.size()) {
		if(_is_vertex_cover(G, nodes) && (nodes.size() < res.size() || res.size() == 0)) {
			res = nodes;
		}
	} else {
		_compute_possible_vertex_covers(G, res, vertices.size(), nodes);
		for(int i = pos;i < (int)vertices.size();i++) {
			nodes.insert(vertices[ i ]);
			_compute_possible_vertex_covers(G, res, i+1,nodes);
			nodes.erase(vertices[ i ]); 
		}
	}
}

template<typename T>
std::set<T> get_min_vertex_cover(undirected_graph<T>& G) {

	std::set<T> res;
	_compute_possible_vertex_covers(G, res);

	return res;
}

int main(int argc, char **args) {
    std::ifstream in(args[1]);

    int n, m;
    in >> n >> m;
    std::vector<int> v;
    for(int i = 0;i < n; i++) {
    	v.push_back(i);
    }
    undirected_graph<int> G(v);
    for(;m;m--) {
        int x, y;
        in >> x >> y;
        G.addEdge(x, y);
    }
    in.close();

    std::cout << "Vertex cover is ";
    for(auto it: get_min_vertex_cover<int>(G)) {
    	std::cout << it << ' ';
    }
    std::cout << '\n';

    return 0;

}
