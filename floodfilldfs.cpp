#include <bits/stdc++.h>
using namespace std;
int grid[100][100];
int visited[100][100];
typedef pair<int,int> ii;
vector<ii> directions = {{0,1},{1,0},{0,-1},{-1,0}};
void flood_fill(ii start, int colour){
	visited[start.first][start.second] = true;
	grid[start.first][start.second] = colour;
	for(int i = 0; i < directions.size(); i++){
		if(!visited[start.first+directions[i].first][start.second+directions[i].second] && grid[start.first+directions[i].first][start.second+directions[i].second] == 0){
			flood_fill({start.first+directions[i].first,start.second+directions[i].second},colour);
		}
	}
}
int main(){

}