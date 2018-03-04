#include<iostream>
#include<queue>;
using namespace std;
int main(){
  queue<int> q;//初始化一个队列变量
  while(!q.empty()) q.pop();//不断弹出时这么写
  q.push(1);//在末尾加入一个元素
  q.pop();//删除第一个元素
  int v=q.front();//得到队首的值
  int s=q.size();//得到队列里的元素个数
  return 0;
}
