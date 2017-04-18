#include <bits/stdc++.h>
using namespace std;
int left_size,right_size;
vector<bool> visited;
vector<int> matching;
vector<vector<int> > graph;
int aug(int edge){
	if(visited[edge])return 0;
	visited[edge] = true;
	for(int neighbour : graph[edge]){
		if(matching[neighbour] == -1 || aug(matching[neighbour])){
			matching[neighbour] = edge;
			return 1;
		}
	}
	return 0;
}
int main(){
	cin >> left_size >> right_size;
	graph.resize(left_size+right_size);
	matching.assign(left_size+right_size,-1);
	int num_edges = 0;
	cin >> num_edges;
	for(int i = 0; i < num_edges; i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	int ans = 0;
	for(int i = 0; i < left_size; i++){
		fill(visited.begin(),visited.end(),false);
		ans+=aug(i);
	}
}