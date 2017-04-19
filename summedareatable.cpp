#include <bits/stdc++.h>
using namespace std;
int summed_area_table[100000][100000];
int get_summed(int x1, int y1, int x2, int y2){
  int tmp = summed_area_table[x2][y2];
  if(x1 > 0)tmp-=summed_area_table[x1-1][y2];
  if(y1 > 0)tmp-=summed_area_table[x2][y1-1];
  if(x1 > 0 && y1 > 0)tmp+=summed_area_table[x1-1][y1-1];
  return tmp;
}
int main(){
  int n,m;
  cin >> n >> m;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cin >> summed_area_tables[i][j];
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(i > 0)summed_area_table[i][j] += summed_area_table[i-1][j];
      if(j > 0)summed_area_table[i][j] += summed_area_table[i][j-1];
      if(i > 0 && j > 0)summed_area_table[i][j] -= summed_area_table[i-1][j-1];
    }
  }
}