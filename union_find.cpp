#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UF{
	int cnt;
	vector<int> id,sz;
    UF(int N)   {
        cnt = N;
		id.resize(N);
		sz.resize(N);
        for(int i=0; i<N; i++)	{
            id[i] = i;
	    	sz[i] = 1;
		}
    }
    int find(int p)	{
        int root = p;
        while (root != id[root]){root = id[root];}
        while (p != root) {
            int newp = id[p];
            id[p] = root;
            p = newp;
        }
        return root;
    }
    void merge(int x, int y)	{
        int i = find(x);
        int j = find(y);
        if (i == j) return;
        if (sz[i] < sz[j]){ 
			id[i] = j; 
			sz[j] += sz[i]; 
		} else	{ 
			id[j] = i; 
			sz[i] += sz[j]; 
		}
        cnt--;
    }
    bool connected(int x, int y){return find(x) == find(y);}
    int count() {return cnt;}
};
int main(){

}