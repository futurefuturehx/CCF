//一定要抽象 抽象到本质更容易理解 抽象结构能减少转化层次
//题意要先转化 在本质不变的基础上 越抽象越容易理解
//简化的转化层次越多越好 依据越接近输入本身越好
#include<iostream>
using namespace std;
int seat[21]={0};
void put(int p){
   for(int i=0;i<20;i++){
       while(seat[i]<5){
           cout<<i*5+1+seat[i]++<<" ";
           if(--p==0){
               cout<<endl;
               return;
           }
       }
   }
}
bool check(int p){
   for(int i=0;i<20;i++){
       if(p+seat[i]<6){//如果找到能合并的一组
         //拿一个样品不断去试验机试
           for(int j=0;j<p;j++)
               cout<<i*5+j+seat[i]+1<<" ";//找到后附加输出
               //输出并不一定要靠预先存储 可以通过运算+控制输出 可以减少中间至少两步中间层次
               //这边并没有存储20个数组 而是一个数组存储20个长度 通过长度和位置控制输出的内容
           cout<<endl;
           seat[i]+=p;//合并之后 这一组的长度就变了
           return true;//ture代表找到空位 能够合并
       }
   }
   return false;//false表示没有找到能够合并的位置 所以准备单独输出 开辟空间
}
int main(){
   int n,p;
   cin>>n;
   while(n--){
       cin>>p;
       if(p>5||!check(p)){
           put(p);
       }//对于输进去的长度并不是每个都取
       //无法合并的输出合并之后的结果 能够合并的合并进去
       //一定要以抽象的逻辑结构为依据单位 不要以现实映像为依据单位
   }
}
//模块化思想
//先调用抽象函数 再具体实现
