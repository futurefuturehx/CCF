#include<iostream>
using namespace std;
void swap(int &p1,int &p2){
    int p;p=p1;p1=p2;p2=p;
}
int main(){
    int a,b;
    cin>>a>>b;
    swap(a,b);
    cout<<a<<' '<<b;
}
//看吧 用了引用之后 就不是什么形参了 在被调函数中的修改 就是对于原变量的修改