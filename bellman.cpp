#include <bits/stdc++.h>
using namespace std;
struct edge{
	int from;
	int to;
	int weight;
};
vector<edge> edges;
vector<int> dist;
bool bellman(int s){
	dist[s] = 0;
	for(int i = 0; i < dist.size()-1; i++){
		for(edge e : edges){
			if(dist[e.to] > dist[e.from] + e.weight){
				dist[e.to] = dist[e.from] + e.weight;
			}
		}
	}
	for(edge e : edges){
		if(dist[e.to] > dist[e.from] + e.weight)return false;
	}
	return true;
}
int main(){
	int n,m;
	cin >> n >> m;
	dist.assign(n,1000000000);
	edges.resize(2*m);
	for(int i = 0; i < 2*m ; i =i+2){
		cin >> edges[i].from >> edges[i].to >> edges[i].weight;
		edges[i].from--;
		edges[i].to--;
		edges[i+1] = edges[i];
		edges[i+1].to = edges[i].from;
		edges[i+1].from = edges[i].to;
	}
	bellman(0);
	for(int i = 1; i < n; i++){
		cout <<  dist[i] << ' ' ;
	}
}