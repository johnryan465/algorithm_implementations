#include <iostream>
#include <vector>
using namespace std;
struct BIT{
    inline int LSOne(int S){return S &(-S);}
    vector<int> data;
    BIT(int size){
        data.resize(size+1);
    }
    void insert(int idx, int value){
        while(idx < data.size()){
            data[idx] += value;
            idx += LSOne(idx);
        }
    }
    int rsq(int from, int to){
        return getSum(to) - getSum(from-1);
    }
    int getSum(int element){
        int value = 0;
        while(element != 0){
            value += data[element];
            element -= LSOne(element);
        }
        return value;
    }
};
int main(){
    BIT tree(6);
    tree.insert(1,10);
    tree.insert(1,4);
    cout << tree.rsq(1,4) << endl;
}