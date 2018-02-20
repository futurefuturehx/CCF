#include<iostream>
#include <map>  
#include <vector>  
#include <algorithm>  
  
using namespace std;   
  
typedef struct node{  
    int x1,y1,x2,y2;  
    int id;       //记录窗口的原始序号   
} Node;  
  
Node node[11];  
vector<int> v;  //保存每个点击的输出结果，用于最后输出，不可用multimap来保存点用于遍历！！   
  
int main(int argc, char** argv) {  
    int n,m;  
    cin >> n >>m;  
      
    for(int i=1; i<=n; i++)  
    {  
      int a,b,c,d;  
      cin >> a >> b >>c >>d;  
      node[i].x1 = a;  node[i].y1 = b;  node[i].x2 =c ;  node[i].y2=d;  
      node[i].id=i;   
    }  
       
     for(int i=0; i<m; i++)  //遍历每一个点   
     {  
        int x,y;  
        cin >> x >> y;  
          
        int flag =0;   
          
        for(int j=n; j>=1; j--)  //</span><span style="color:#cc0000;">从最上面的窗口开始遍历 </span><span style="font-family: 宋体;">  
         {   
            if(x>=node[j].x1 && x<=node[j].x2 && y>=node[j].y1 && y<=node[j].y2)  
            {  
               flag = 1;                  //如果在窗口范围flag置1        
               v.push_back(node[j].id);              
                 
               Node temp = node[j];      //标号大于j的窗口向下移动，j放在最上面   
               for(int z=j; z<n; z++)  
               {  
                  node[z] = node[z+1];  
               }  
                node[n] = temp;                
//              for(int i=1; i<=n; i++)  
//                cout << node[i].id << endl;  
                break;  
            }  
         }   
         if(flag == 0)    //如果点不在窗口内，存入0   
         {  
            v.push_back(0);  
         }  
     }  
       
    for(vector<int>::iterator it=v.begin(); it!=v.end(); it++)  
    {  
        if(*it == 0)  
           cout << "IGNORED" << endl;  
        else           
           cout << *it << endl;  
    }  
              
    return 0;  
}