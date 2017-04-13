#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int> > graph;
void bfs(int start){
	queue<int> q;
	vector<bool> visited(graph.size(),false);
	visited[start] = true;
	q.push(start);
	while(!q.empty()){
		int current = q.front();
		cout << current << endl;
		q.pop();
		for(int i = 0; i < graph[current].size(); i++){
			if(!visited[graph[current][i]]){
				q.push(graph[current][i]);
				visited[graph[current][i]] = true;
			}
		}
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	graph.resize(n);
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	bfs(0);
}