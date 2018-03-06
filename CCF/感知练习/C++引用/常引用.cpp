#include<iostream>
using namespace std;
int main(){
    int a;
    const int &ra=a;
    ra=1;//引用不可改
    a=1;//原变量可以改
}