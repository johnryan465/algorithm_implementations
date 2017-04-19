#include <bits/stdc++.h>
using namespace std;
int table[100000000];
int get(int l,int r){
  return table[r] - table[l-1];
}
int main(){
  int n;
  for(int i = 0; i < n; i++){
    cin >> table[i];
  }
  for(int i = 1 ; i < n; i++){
    table[i] += table[i-1];
  }
  get(3,7);
}