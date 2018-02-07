//类似于页式存储 页内偏移 只是将页表项换成了每组座位长度
//担心数组没有标志变量 一个bool类型的函数就能解决
//输出的顺序不一定要按照存储顺序 可以通过控制输出
#include<iostream>
using namespace std;
int main(){
    int n;
    int a[20];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
}