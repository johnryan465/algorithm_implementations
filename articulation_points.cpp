#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > graph;
vector<int> parent,lowest_reachable,dfs_num;
vector<bool> visited;
set<int> art;
set<pair<int,int> > bridges;
int root;
int root_children;
int dfs_iterations=0;
void dfs(int current){
  dfs_num[current] = dfs_iterations;
  lowest_reachable[current] = dfs_iterations;
  visited[current] = true;
  dfs_iterations++;
  for(int children : graph[current]){
    //if(children == parent[current])continue;
    if(!visited[children]){
      parent[children] = current;
      if(current == root)root_children++;
      dfs(children);
      if(root != current && lowest_reachable[children] >= dfs_num[current]){
        art.insert(current);
      }
      if(lowest_reachable[children] > dfs_num[current]){
        bridges.insert({current,children});
      }
      lowest_reachable[current] = min(lowest_reachable[current],lowest_reachable[children]);
    }
    else if(children != parent[current]){
      lowest_reachable[current] = min(lowest_reachable[current],dfs_num[children]);
    }
  }
}
int main(){
  int n=0,m=0;
  cin >> n >> m;
  graph.resize(n);
  visited.resize(n);
  parent.resize(n);
  dfs_num.resize(n);
  parent.resize(n);
  lowest_reachable.resize(n);
  for(int i = 0 ; i < m ; i++){
    int a,b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  for(int i = 0 ; i < n; i++){
    if(!visited[i]){
      root = i;
      root_children = 0;
      dfs(root);
    }
  }
  for(int a : art){
  	cout << a << ' ';
  }
  cout << endl;
  for(pair<int,int> edge : bridges){
    cout << edge.first << ' ' << edge.second << endl;
  }
}