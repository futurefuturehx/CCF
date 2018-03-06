#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int>first;
    list<int>second;
    first.assign(7,100);//给first添加7个值为100的元素
    second.assign(first.begin(),first.end());//复制first给second
    int myints[]={16,8,4};
    first.assign(myints,myints+3);//将数组myints的内容添加给first
    cout<<"Size of first:"<<int(first.size())<<'\n';
    cout<<"Size of second:"<<int(second.size())<<'\n';
    return 0;
}