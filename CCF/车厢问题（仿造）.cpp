//类似于页式存储 页内偏移 只是将页表项换成了每组座位长度
//担心数组没有标志变量 一个bool类型的函数就能解决
//输出的顺序不一定要按照存储顺序 可以通过控制输出
//check()函数判断的同时 也进行了操作运算
//可以在输入的时候就进行控制 越早控制越好
//for循环本身也是可以控制的(i++之前加上i--就是对于下一个位置的控制)
//这段代码好像只能实现座位的显示 不能做到一条指令显示一次
#include<iostream>
using namespace std;
int main(){
  int seats[20]={0};
  int n;
  int p;
  cin>>n;
  cin>>seats[0];
  for(int i=1;i<n;i++){
    cin>>p;
    for(int j=0;j<i;j++){
      if(p+seats[j]<6){
        seats[j]+=p;
        i--;
        n--;
      }
      else{
        seats[i]=p;
      }
    }
  }
  for(int i=0;i<n;i++){
    if(seats[i]!=0){
      for(int j=0;j<seats[i];j++){
        cout<<i*5+j+1<<" ";
      }
    }
    cout<<endl;
  }
}
