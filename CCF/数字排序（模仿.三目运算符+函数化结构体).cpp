#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
    int idx,cnt;
    node(int a,int b):idx(a),cnt(b){}
};
bool cmp(const node &a,const node &b){
    return a.cnt==b.cnt?a.idx<b.idx:a.cnt>b.cnt;
}
//结构体和被调用函数都写在main函数上面
int main(){
	int n; 
    cin>>n;
    int x;
    vector<node> list;
    int count[1024]={0};
    for(int i=0;i<n;i++){
        cin>>x;
        count[x]++;
    }
    for(int i=0;i<n;i++){
        if(count[i]){
            list.push_back(node(i,count[i]));//实参形参 参数映射 对应位置 对应映射
        }
    }
    sort(list.begin(),list.end(),cmp);
    for(int i=0;i<list.size();i++){
        cout<<list.at(i).idx<<" "<<list.at(i).cnt<<endl;
    }
    return 0;
}