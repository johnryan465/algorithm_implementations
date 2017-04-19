#include <bits/stdc++.h>
using namespace std;
int grid[100][100];
int visited[100][100];
typedef pair<int,int> ii;
vector<ii> directions = {{0,1},{1,0},{0,-1},{-1,0}};
void flood_fill(ii start){
	queue<ii> q;
	int colour = grid[start.first][start.second];
	q.push(start);
	while(!q.empty()){
		ii current = q.front();
		q.pop();
		for(int i = 0; i < directions.size(); i++){
			if(!visited[current.first+directions[i].first][current.second+directions[i].second] && grid[current.first+directions[i].first][current.second+directions[i].second] == 0){
				q.push({current.first+directions[i].first,current.second+directions[i].second});
				visited[current.first+directions[i].first][current.second+directions[i].second] = true;
				grid[current.first+directions[i].first][current.second+directions[i].second] = colour;	
			}
		}
	}
}
int main(){

}