//掩码模板 可以暂存多次操作为一次性操作而且使得互不干扰 
//完全正确 运用了掩码的精髓
#include<iostream>
using namespace std;
int main(){
	int m,n;
    int gezi[32][32];
    int yanma[32][32]={0};
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>gezi[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=1;j<n-1;j++){
            if(gezi[i][j]==gezi[i][j-1]&&gezi[i][j]==gezi[i][j+1]){
                yanma[i][j]=yanma[i][j+1]=yanma[i][j-1]=1;
            }
        }
    }
    for(int j=0;j<n;j++){
        for(int i=1;i<m-1;i++){
            if(gezi[i][j]==gezi[i-1][j]&&gezi[i][j]==gezi[i+1][j]){
                yanma[i][j]=yanma[i+1][j]=yanma[i-1][j]=1;
            }
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(yanma[i][j]==1){
                cout<<0<<" ";
            }
            else{
                cout<<gezi[i][j]<<" ";
            }
        }
        cout<<endl;
    }
}