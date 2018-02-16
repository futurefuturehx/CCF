//掩码模板 可以暂存多次操作为一次性操作而且使得互不干扰 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[32][32],b[32][32];
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j)
            cin>>a[i][j];
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            int k=j+1;
            while(k<m&&a[i][k]==a[i][k-1])++k;
            //for侧重于定位 while侧重于移动
            if(k-j<3){
                j=k-1;
              }
            else{
                while(j<k)b[i][j++]=1;
                --j;
            }
        }
    }
    for(int j=0;j<m;++j){
        for(int i=0;i<n;++i){//定位到起始
            int k=i+1;
            while(k<n&&a[k][j]==a[k-1][j])++k;//移动到末尾
            if(k-i<3){
                i=k-1;
            }
            else{
                while(i<k)b[i++][j]=1;//追随移动变化到末尾
                --i;
            }
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(b[i][j]==0)
                cout<<a[i][j]<<" ";
            else cout<<0<<" ";
        }
        //类似于子网掩码筛选
        //利用掩码白板辅助可以避免对于原来的数据的大更改 以至影响判断
        //0代表输出原来的数 1表示得输出变动之后的数0
        cout<<endl;
    }
    return 0;
}
