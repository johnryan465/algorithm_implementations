#include <iostream>
#include <vector>
using namespace std;
struct seg_tree{
  vector<int> data,tree,lazy_prop;
  seg_tree(vector<int> n){
    data = n;
    tree.resize(data.size() * 4);
    lazy_prop.resize(data.size() * 4);
    build(0,data.size()-1,1);
  }

  inline int indentiy(){return 0;}
  inline int op(int a,int b){return a*b;}
  inline int left_child(int n){return 2*n;}
  inline int right_child(int n){return (2*n)+1;}

  void lazy_next(int node,bool leaf){
    if(lazy_prop[node] != 0){
      tree[node] += lazy_prop[node];
      if(leaf){
        lazy_prop[left_child(node)] += lazy_prop[node];
        lazy_prop[right_child(node)] += lazy_prop[node];
      }
      lazy_prop[node] = 0;
    }
  }

  int build(int left,int right, int node){
    if(left == right)return tree[node] = data[left];
    return tree[node] = op(build(left,( (right+left)/2), left_child(node)) ,build((right+left)/2 + 1, right,right_child(node)));
  }

  int query(int node, int left_bound, int right_bound, int current_left, int current_right){
    if(current_left > current_right || current_left > right_bound || current_right < left_bound)return indentiy();
    lazy_next(node,current_left==current_right);
    if(current_left >= left_bound && current_right <= right_bound)return tree[node];
    int l_ans = query(left_child(node),left_bound,right_bound,current_left,(current_right+current_left)/2);
    int r_ans = query(right_child(node),left_bound,right_bound,(current_right+current_left)/2 + 1,current_right);
    return op(l_ans,r_ans);
  }

  void update(int node, int update_data, int left_bound, int right_bound, int current_left, int current_right){
    lazy_next(node,current_left==current_right);
    if(current_left > current_right || current_left > right_bound || current_right < left_bound){
      tree[node] = indentiy();
    }
    if(current_left >= left_bound && current_right <= right_bound){
      tree[node] += update_data;
      if(current_left != current_right){
        lazy_prop[left_child(node)] += update_data;
        lazy_prop[right_child(node)] += update_data;
      }
    }

    if(current_left == current_right){
      data[current_left]+=update_data;
      tree[node] = data[current_left];
      return;
    }
    update(left_child(node),update_data,left_bound,right_bound,current_left,(current_right+current_left)/2);
    update(right_child(node),update_data,left_bound,right_bound,(current_right+current_left)/2 + 1,current_right);
    tree[node] = op(tree[left_child(node)],tree[right_child(node)]);
  }
};

int main(){
  vector<int> nums = {1,2,3,4};
  seg_tree seg(nums);
  seg.update(1,2,0,nums.size()-1,0,nums.size()-1);
  cout << seg.query(1,0,3,0,nums.size()-1) << endl;
}
