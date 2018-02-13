#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//充分利用坐标表示
//到什么为止和略过不一样
//if就是针对各种特殊情况进行补丁的
//struct就是个类型 看作int和栈一起用 
//一个是横向的 一个是竖向的 正好合在一起用
//快表原理 列举所有可能的情况 存储对应位置
//一一进行比对 如果匹配 直接找到位置 进行操作
//互相赋值的时候 类型一定要一致
typedef struct{
    int num;
    int count;
}tj;
bool cmp(tj a,tj b){
    if(a.count==b.count){
        return a.num<b.num;
    }
    return a.count>b.count;
}//实现多条件排序
int main(){
    int n;
    int temp;
    tj temp1;
    vector<tj> list;
    vector<tj> list1;
    vector<tj> list2;
    for(int i=0;i<1001;i++){
        list1.at(i).num=i;
        list1.at(i).count=0;
    }
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp;
        list.at(i).num=temp;;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<1001;j++){
            if(list.at(i).num==j){
                list1.at(j).count++;
            }
        }
    }
    for(int i=0;i<1001;i++){
        if(list.at(i).count!=0){
            temp1=list.at(i);
            list2.push_back(temp1);
        }
    }
    sort(list2.begin,list2.end(),cmp);
    for(int i=0;i<list2.size();i++){
        cout<<list2.at(i).num<<" "<<list2.at(i).count<<endl;
    }
}