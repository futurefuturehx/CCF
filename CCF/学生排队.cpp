#include<bits/stdc++.h>
using namespace std;
int main(){
  int bhgs;
  cin>>bhgs;
  int list[1001];
  struct{
    int p;
    int q;
  }caozuo[1001];
  for(int i=0;i<bhgs;i++){
    list[i]=i+1;
  }
  int czcs;
  cin>>czcs;
  for(int j=0;j<czcs;j++){
    cin>>caozuo[j].p>>caozuo[j].q;
  }
  for(int i=0;i<czcs;i++){
    for(int j=0;j<bhgs;j++){
      if(caozuo[i].p==list[j]&&caozuo[i].q<0){
        for(int k=j+caozuo[i].q+1;k<j+1;k++){
          list[k]=list[k-1];
        }
        list[j+caozuo[i].q]=caozuo[i].p;
      }
      if(caozuo[i].p==list[j]&&caozuo[i].q>0){
        for(int k=j+caozuo[i].q;k>j-1;k--){
          list[k]=list[k+1];
        }
        list[j+caozuo[i].q]=caozuo[i].p;
      }
    }
  }
  for(int i=0;i<bhgs;i++){
    cout<<list[i]<<" ";
  }
}
//没有用冒泡排序的变形 复杂了
//将p q保存下来再操作 而不是先过滤再操作 没有必要
