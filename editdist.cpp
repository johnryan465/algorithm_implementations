#include <bits/stdc++.h>
using namespace std;
string s1,s2;
int dp[100][100];
int edit_distance(int n, int m){
	if(dp[n][m] != -1)return dp[n][m];
	if(n == 0 || m == 0)return dp[n][m] = max(n,m);
	if(s1[n-1] == s2[m-1])return dp[n][m] = edit_distance(n-1,m-1); 
	return dp[n][m] = min(min(edit_distance(n-1,m) , edit_distance(n,m-1)), edit_distance(n-1,m-1)) + 1;
}
int main(){
	cin >> s1 >> s2;
	memset(dp, -1, sizeof(dp) );
	cout << edit_distance(s1.size(),s2.size()) << endl;;
}