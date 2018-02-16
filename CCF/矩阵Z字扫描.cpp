//轨迹必定有规律
//轨迹就是过程
//矢量取值 矢量赋值
#include <bits/stdc++.h>
using namespace std;
int n,k=0,a[512][512];
vector<int> v[1024];//什么变量啊声明啊 都写在最前面
void help(int i,int j,int k)
{
    while(i>=0&&i<n&&j>=0&&j<n)//while就是直到的意思 直到碰壁 while的i++都要写在里面
        v[k].push_back(a[i++][j--]);//对于第0行的最后一个元素 i++并且j--就是在斜着走啊 
        //这不很类似于矢量运算吗 通过矢量赋值将任意角度斜线的元素 横向存储
}
void ser()
{
    for(int j=0;j<n;++j)
        help(0,j,k++);
    for(int i=1;i<n;++i)
        help(i,n-1,k++);//这边为啥要分两个for循环 因为到对角线之前第一个for有效 对角线之后第二个for有效
}//这是一种去分解排除分组思想 将完整的一条线分割成一段一段的线 首先排除干扰线段 然后将相似操作的线段分组到同一组
int main()
{

    cin>>n;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            cin>>a[i][j];
    }
    ser();//模块化待处理思想 先把断层隔离 这就是调用函数的好处
    for(int i=0;i<k;++i)//这边的i其实是原来的斜向 k代表总共多少斜线
    {
        if(i%2){
            for(size_t j=0;j<v[i].size();++j)//v.size()是指有多少行 v[i].size()是指这一行有多少列
                cout<<v[i][j]<<" ";
        }//如果i不是2的倍数就正向输出
        else{
            for(int j=v[i].size()-1;j>=0;--j)
                cout<<v[i][j]<<" ";
        }//如果i是2的倍数就反向输出
    }
    return 0;
}
