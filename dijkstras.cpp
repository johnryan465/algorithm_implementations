#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> ii;

vector<vector<pair<ll,ll> > > graph;
vector<ll> dij(ll s, ll t){
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	vector<bool> visited(graph.size(),false);
	vector<ll> distances(graph.size(),10000000000000);
	vector<ll> parent(graph.size(),-1);
	distances[s] = 0;
	pq.push({0,s});
	while(!pq.empty()){
		ll current = (pq.top()).second;
		pq.pop();
		if(visited[current])continue;
		for(ll i = 0; i < graph[current].size(); i++){
			ll edge_weight = graph[current][i].second;
			ll to_vertex = graph[current][i].first;
			if(visited[to_vertex])continue;
			if(distances[current] + edge_weight < distances[to_vertex]){
				distances[to_vertex] = distances[current] + edge_weight;
				parent[to_vertex]=current;
				pq.push({distances[to_vertex], to_vertex});
			}
		}
		visited[current] = true;
	}
	vector<ll> ans;
	if(!visited[t]){return {-1};}

	while(t!=-1){
		ans.push_back(t+1);
		t = parent[t];
	}

	return ans;
}
int main(){
	ll n,m;
	cin >> n >> m;
	graph.resize(n);
	for(ll i = 0; i < m; i++){
		ll a,b,dist;
		cin >> a >> b >> dist;
		a--;
		b--;
		graph[a].push_back({b,dist});
		graph[b].push_back({a,dist});
	}
	vector<ll> ans =  dij(0,n-1) ;
	for(ll i = ans.size()-1 ; i >= 0; i--){
		cout << ans[i] << ' ';
	}
	cout << endl;
}