#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
vector<vector<int> > transpose;
vector<vector<int> > components;
vector<bool> visited;
stack<int> s;
int n;
void dfs_stack(int current){
	visited[current] = true;
	for(int child : graph[current]){
		if(!visited[child])dfs_stack(child);
	}
	s.push(current);
}
vector<int> current_comp;
void dfs_transpose(int current){
	visited[current] = true;
	current_comp.push_back(current);
	for(int children : transpose[current]){
		if(!visited[children])dfs_transpose(children);
	}
}
void scc(){
	fill(visited.begin(),visited.end(),false);
	for(int i = 0; i < n; i++){
		if(!visited[i]){dfs_stack(i);}
	}
	fill(visited.begin(),visited.end(),false);
	while(!s.empty()){
		int current = s.top();
		s.pop();
		if(!visited[current]){
			current_comp.resize(0);
			dfs_transpose(current);
			components.push_back(current_comp);
		}
	}
}

int main(){
	int m;
	cin >> n >> m;
	graph.resize(n);
	transpose.resize(n);
	visited.resize(n);
	for(int i = 0; i < m; i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		transpose[b].push_back(a);
	}
	scc();
	for(int i = 0; i < components.size(); i++){
		for(int j = 0; j < components[i].size(); j++){
			cout << components[i][j] << ' ';
		}
		cout << endl;
	}
}