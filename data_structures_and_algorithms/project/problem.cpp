/*
Given a undirected graph with costs and two nodes A and B find all the edges that are on
a minimum cost path between the 2 given nodes.
*/

#include <fstream>
#include <iostream>

#include "pqueue.h"
#include "tests.h"

#include <vector>
#include <algorithm>
#include <limits>
#include <numeric>

#define INF std::numeric_limits<int>::max()

bool comp(std::pair<int, int> a, std::pair<int, int> b) {
	return a > b;
}

std::vector<int> Dijkstra(std::vector< std::vector< std::pair<int, int> > > adj, int start) {
    PQueue< std::pair<int,int> > heap(&comp);
    std::vector<int> dist(adj.size(), INF);
    dist[ start ] = 0;
    heap.push( { dist[ start ], start } );
    while(!heap.empty()) {
        int v = heap.top().second;
        heap.pop();
        for(auto it: adj[ v ])
        if (dist[ it.first ] > dist[ v ]+it.second) {
            dist[ it.first ] = dist[ v ]+it.second;
            heap.push({ dist[ it.first ], it.first });
        }
    }
    for(int i = 0;i < (int)dist.size(); i++) {
        dist[i] = (dist[i] == INF ? -1 : dist[i]);
    }
    return dist;//return the list of distances from the start node to the others, -1 if there's no path between 2 nodes
}

int main(int argc, char** args) {

	run_tests();
	std::ifstream in(args[1]);

	int n, m, start, dest;

	in >> n >> m >> start >> dest;

	std::vector< std::vector< std::pair<int, int> > > adj(n+1);
	std::vector< std::pair< std::pair<int, int>, int > > edges;

	for(;m;m--) {
		int x, y, z;
		in >> x >> y >> z;
		adj[ x ].push_back({y, z});
		adj[ y ].push_back({x, z});

		edges.push_back({{x, y} , z});
	}

	std::vector<int> startDist = Dijkstra(adj, start);
	std::vector<int> destDist = Dijkstra(adj, dest);

	for(auto it: edges) {
		if(startDist[ it.first.first ] > startDist[ it.first.second ]) {
			std::swap(it.first.first, it.first.second);
		}

		if(startDist[ it.first.first ] + it.second + destDist[ it.first.second ] == startDist[ dest ]) {
			std::cout << it.first.first << " -> " << it.first.second << " of cost " << it.second << '\n';
		}
	}

	return 0;
}
