#include <iostream>
#include <vector>
#include <cmath> 
using namespace std;

struct segment_tree{

    int identity(){return -1000000;}
    int op(int a, int b){return max(a,b);}
    int left_child(int a){return a*2;}
    int right_child(int a){return 1+a*2;}

    vector<int> arr, tree;
    segment_tree(vector<int> input){
        arr = input;
        tree.resize(input.size()*4);
        build_tree(1, 0, input.size()-1);
    }
    void build_tree(int node, int a, int b) {
        if(a > b) return;
        if(a == b) {
            tree[node] = arr[a];
            return;
        }
        build_tree(left_child(node), a, (a+b)/2);
        build_tree(right_child(node), 1+(a+b)/2, b);
        tree[node] = op(tree[left_child(node)], tree[right_child(node)]);
    }   
    void update_tree(int node, int a, int b, int i, int j, int value) { 
        if(a > b || a > j || b < i) return;
        if(a == b) {
            tree[node] += value;
            return;
        }
        update_tree(left_child(node),  a,   (a+b)/2, i, j, value);
        update_tree(right_child(node), 1+(a+b)/2, b, i, j, value);
        tree[node] = op(tree[left_child(node)], tree[right_child(node)]);
    }
    int query_tree(int node, int a, int b, int i, int j) {
        if(a > b || a > j || b < i) return identity();
        if(a >= i && b <= j) return tree[node];
        return op(query_tree(left_child(node), a, (a+b)/2, i, j), query_tree(right_child(node), 1+(a+b)/2, b, i, j));
    }
};

int main() {
    int N = 20;
    vector<int> arr;
    for(int i = 0; i < N; i++) arr.push_back(1);
    segment_tree tree(arr);
    tree.update_tree(1, 0, N-1, 0, 6, 5);
    tree.update_tree(1, 0, N-1, 7, 10, 12);
    tree.update_tree(1, 0, N-1, 10, N-1, 100);
    cout << tree.query_tree(1, 0, N-1, 0, N-1) << endl;
}