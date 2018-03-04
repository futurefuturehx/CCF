#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> stk;
    for(int i=0;i<50;i++){
        stk.push(i);
    }
    cout<<"栈的大小:"<<stk.size()<<endl;
    while(!stk.empty()){
        cout<<stk.top()<<endl;
        stk.pop();//重要操作 每当不空就输出一个 每输出一个就弹出一个
    }
    cout<<"栈的大小"<<stk.size()<<endl;
    return 0;
}