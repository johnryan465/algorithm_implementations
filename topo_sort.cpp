#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
vvi graph;
vi topo_sort(){
    vi in_degree(graph.size(),0);
    for(auto item = graph.begin(); item != graph.end(); ++item){
        for(auto it = (*item).begin(); it != (*item).end(); ++it){
            in_degree[(*it)]++;
        }
    }
    queue<int> zeros;
    vi ans;
    for(int i = 0; i < in_degree.size(); i++){
        if(in_degree[i] == 0){
            zeros.push(i);
        }
    }
    while(!zeros.empty()){
        int current = zeros.front();
        zeros.pop();
        ans.push_back(current);
        for(auto it = graph[current].begin(); it != graph[current].end(); it++){
            in_degree[(*it)]--;
            if(in_degree[(*it)] == 0){
                zeros.push((*it));
            }
        }
    }
    return ans;
}
int main(){
    int n,m;
    cin >> n >> m;
    graph.resize(n);
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    return 0;
}