#include<iostream>
#include<list>
using namespace std;
int main(){
    //第一种方式 通过构造函数赋值数组之类
    int myint[]={75,23,65,42,13};
    list<int>mylist1(myints,myints+5);
    list<int>mylist2(2,100);
    //第二种使用push_back或push_front
    for(int i=1;i<=5;++i) mylist1.push_back(i);
    mylist2.push_front(200);
    mylist2.push_front(300);
    //第三种 用assign
    list<int>first;
    list<int>second;
    second.assign(first.begin(),first.end());
    int myints[]={16,8,4};
    first.assign(myints,myints+3);
    return 0;
}