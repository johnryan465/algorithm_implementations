#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<vector<int> > graph;
vector<bool> visited;
stack<int> topo;
void topo_sort(int start){
	visited[start] = true;
	for(auto neighbour : graph[start]){
		if(!visited[neighbour])topo_sort(neighbour);
	}
	topo.push(start);
}
int main(){
	int n,m;
	cin >> n >> m;
	graph.resize(n);
	visited.assign(n,false);
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for(int i = 0; i < n; i++){
		if(!visited[i])topo_sort(i);
	}
	while(!topo.empty()){
		cout << topo.top() << ' ';
		topo.pop();
	}
	cout << endl;
}