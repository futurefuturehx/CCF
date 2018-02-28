//这就是分层架构啊
//存储层用结构体 预备输出层用vector 
//存储层负责有效存储 预备输出层负责方便输出 
//这两层各司其职 清晰明了 设置一个中间变量 互相联系
//flag类似于pv操作啊
//有些东西不需要存储 只需要走个过场 在for循环中设置为快餐变量就行了 入即是出
#include<iostream>
#include <vector>  
#include <algorithm>  
using namespace std;   
typedef struct node{  
    int x1,y1,x2,y2;  
    int id;       //记录窗口的原始序号   
} Node; //将一个实体定义为一个类
  
Node node[11];  
vector<int> v;  //保存每个点击的输出结果，用于最后输出，不可用multimap来保存点用于遍历！！   
  
int main(int argc, char** argv) {  //arg是外部命令的个数 arg[]存放各参数的内容
    int n,m;  
    cin >> n >>m;  
      
    for(int i=1; i<=n; i++)  //编号都是从1开始的
    {  
      int a,b,c,d;  
      cin >> a >> b >>c >>d;  
      node[i].x1 = a;  node[i].y1 = b;  node[i].x2 =c ;  node[i].y2=d;  //结构体成员需要中间变量来传值
      node[i].id=i;   
    } //录入各对角坐标
       
     for(int i=0; i<m; i++)  //遍历每一个点   
     {  
        int x,y;  
        cin >> x >> y;  
          
        int flag =0;   
          
        for(int j=n; j>=1; j--)  //这边是为了从最顶端进行遍历
         {   
            if(x>=node[j].x1 && x<=node[j].x2 && y>=node[j].y1 && y<=node[j].y2)  
            {  
               flag = 1;                  //如果在窗口范围flag置1    //不用考虑什么与上一层重复 因为逻辑上：在上一层找到 就不可能到下一层   
               v.push_back(node[j].id);              
                 
               Node temp = node[j];      //标号大于j的窗口向下移动，j放在最上面 //只有结构体类型的才能接收结构体类型
               for(int z=j; z<n; z++)  
               {  
                  node[z] = node[z+1];  
               } //将其余页往前移动
                node[n] = temp;//将被点击的那一页置顶           
//              for(int i=1; i<=n; i++)  
//                cout << node[i].id << endl;  
                break;  
            }  
         }   
         if(flag == 0)    //如果点不在窗口内，存入0   
         {  
            v.push_back(0);  
         }//都没找到 标为0 表示处于空白位置
     }//类似于pv操作  
       
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)  
    {  //迭代器就好比是动态数组的指针
        if(*it == 0)  
           cout << "IGNORED" << endl;  
        else           
           cout << *it << endl;  
    }  
              
    return 0;  
}