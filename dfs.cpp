#include <iostream>
#include <vector>
using namespace std;
vector<vector<int> > graph;
vector<bool> visited;
void dfs(int start){
	visited[start] = true;
	for(int i = 0; i < graph[start].size(); i++){
		if(!visited[graph[start][i]]){
			dfs(graph[start][i]);
		}
	}
	cout << start << endl;
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
	dfs(0);
}