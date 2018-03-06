#include<iostream>
#include<string>
using namespace std;
//inline表示这是一个内联函数 
//第一个const说明这个函数的返回值是一个不能那个被改变的数 而那个&是这个数的引用
//最后两个const表示参数 是const的两个引用
//用引用可以减少数值传递过程中的实践 而cosnt则保证这个传过来的值在使用的时候不被改变
template<typename T>
inline T const& Max(T const&a,T const&b){
    return a<b?b:a;
}
int main(){
    int i=39;
    int j=20;
    cout<<"Max(i,j):"<<Max(i,j)<<endl;
    double f1=13.5;
    double f2=20.7;
    cout<<"Max(f1,f2)"<<Max(i,j)<<endl;
    string s1="Hello";
    string s2="World";
    cout<<"Max(s1,s2):"<<Max(s1,s2)<<endl;
    return 0;
}