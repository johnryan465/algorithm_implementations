#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vector<iii> edges;
struct UF{
	vector<int> parent,size;
	UF(int n){
		size.assign(n,1);
		parent.resize(n);
		for(int i = 0; i < n; i++){
			parent[i] = i;
		}
	}
	int find(int p){
		if(parent[p] != p){
			parent[p] = find(parent[p]);
		}
		return parent[p];
	}
	bool connected(int x, int y){
		return find(x) == find(y);
	}
	void merge(int x, int y){
		if(connected(x,y))return;
		x = find(x);
		y = find(y);
		if(size[x] > size[y]){
			parent[y] = x;
			size[x] += size[y];
		}
		else{
			parent[x] = y;
			size[y] += size[x];
		}
	}
};
vector<iii> krustals(int n){
	vector<iii> ans;
	sort(edges.begin(),edges.end());
	UF graph(n);
	for(int i = 0; i < n; i++){
		if(!graph.connected(edges[i].second.first,edges[i].second.second)){
			ans.push_back(edges[i]);
			graph.merge(edges[i].second.first,edges[i].second.second);
		}
	}
	return ans;
}
int main(){
	int n,m;
	cin >> n >> m;
	edges.resize(m);
	for(int i = 0; i < m; i++){
		int a,b,dist;
		cin >> a >> b >> dist;
		edges[i].first = dist;
		edges[i].second.first = a;
		edges[i].second.second = b;
	}
	vector<iii> ans = krustals(n+1);
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i].second.first << ' ' << ans[i].second.second << ' ' << ans[i].first << endl;
	}
}