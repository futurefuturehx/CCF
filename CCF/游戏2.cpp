#include<iostream>
#include<queue>
using namespace std;
int main(){
  queue<int> que;//类似于容器 只要把vector换成queue就行了
  int n,k;
  int fron;
  int num=1;
  cin>>n>>k;
  for(int i=0;i<n;i++){
    que.push(i+1);
  }
  while(que.size()>1){
    fron=que.front();
    que.pop();
    if(num%k!=0&&(num%10)!=k)
       que.push(fron);
    num++;
  }//备份第一个元素再弹出 满足条件再压入
  //三角形力场
  cout<<que.front();
  return 0;
}
//14到17段类似与一个待定三角形 先将最前面的放到待定区进行判断 合格就再次放到队列末尾
//对比一下思维 可以添加一个辅助变量来进行测试定量是否合格 而不是改变定量 要被输出的数值不要变 编号不用变 要有辅助定量思维
