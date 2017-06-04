#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <limits>
#include <numeric>

#include "../graph_classes/io_directed_graph.h"

typedef std::pair<int, int> Activity;
#define index first
#define duration second
#define INF std::numeric_limits<int>::max()

template<typename T>
std::vector<T> TopoSort(io_directed_graph<T>& G) {
	std::map<T, int> degree;
	std::queue<T> Q;
	std::vector<T> res;

	for(auto it: G.getVertices()) {
		degree[ it ] = G.inDegree(it);
		if(degree[ it ] == 0) {
			Q.push(it);
		}
	}

	while(!Q.empty()) {
		T node = Q.front();
		Q.pop();
		res.push_back( node );

		for(auto it: G.getOutNeighbours( node )) {
			degree[ it ]--;
			if(degree[ it ] == 0) {
				Q.push(it);
			}
		}
	}

	return res;
}

std::pair< std::pair< std::vector<int>, std::vector<int> >, std::pair< std::vector<int>, std::vector<int> > > compute_times(io_directed_graph<Activity>& G, std::vector<Activity>& topSort) {
	std::vector<int> earliest_time_starts(topSort.size());
	std::vector<int> earliest_time_ends(topSort.size());
	std::vector<int> latest_time_starts(topSort.size(), INF);
	std::vector<int> latest_time_ends(topSort.size(), INF);

	for(auto v: topSort) {

		for(auto it: G.getInNeighbours(v)) {
			earliest_time_starts[ v.index ] = std::max( earliest_time_starts[ v.index ], earliest_time_ends[ it.index ] );  
		}

		earliest_time_ends[ v.index ] = earliest_time_starts[ v.index ] + v.duration;
	}

	latest_time_ends[ topSort[ topSort.size()-1 ].index ] = earliest_time_ends[ topSort[ topSort.size()-1 ].index ];
	latest_time_starts[ topSort[ topSort.size()-1 ].index ] = latest_time_ends[ topSort[ topSort.size()-1 ].index ] - topSort[ topSort.size()-1 ].duration;

	for(int i = topSort.size() - 2;i >= 0;i--) {
		for(auto it: G.getOutNeighbours(topSort[ i ])) {
			latest_time_ends[ topSort[ i ].index ] = std::min( latest_time_ends[ topSort[ i ].index ], latest_time_starts[ it.index ]);
		}

		latest_time_starts[ topSort[ i ].index ] = latest_time_ends[ topSort[ i ].index ] - topSort[ i ].duration;
	}

	return { {earliest_time_starts, earliest_time_ends}, {latest_time_starts, latest_time_ends} };
}

int main(int argc, char** args) {
	std::ifstream in(args[1]);

	std::vector<Activity> activities;
	int n;
	in >> n;

	for(int i = 0;i < n;i++) {
		Activity activity;

		in >> activity.duration;
		activity.index = i;

		activities.push_back( activity );
	}

	io_directed_graph<Activity> G(activities);

	for(int i = 0;i < n;i++) {
		int k;
		for(in >> k;k;k--) {
			int x;

			in >> x;
			G.addEdge(activities[ x ], activities[ i ]);
		}
	}

	std::vector<Activity> topSort = TopoSort<Activity>(G);

	std::pair< std::pair< std::vector<int>, std::vector<int> >, std::pair< std::vector<int>, std::vector<int> > > res = compute_times(G, topSort);
	std::vector<int> earliest_time_starts = res.first.first;
	std::vector<int> earliest_time_ends = res.first.second;
	std::vector<int> latest_time_starts = res.second.first;
	std::vector<int> latest_time_ends = res.second.second;

	std::cout<<"Topo. sort is ";
	for(auto it: topSort) {
		std::cout << it.index << ' ';
	}
	std::cout << '\n';

	for(auto it: activities) {

		std::cout << "Activity #" << it.index << " : Earliest time starts = " << earliest_time_starts[ it.index ] << " , Earliest time ends = " << earliest_time_ends[ it.index ] << " , Latest time starts = " << latest_time_starts[ it.index ] << " , Latest time ends = " << latest_time_ends[ it.index ] << '\n';
	}

	return 0;
}