#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int n;
  int temp;
  int a=0;
  int b=0;
  int temp1;
  vector<int> list;
  vector<int> list1;
  cin >>n;
  for(int i=0;i<n;i++){
    cin >>temp;
    list.push_back(temp);
  }
  for(int j=0;j<list.size();j++){
    for(int k=0;k<list.size();k++){
      if(j!=k){
        if(list[k]>list[j]){
          a++;
        }
        if(list[k]<list[j]){
          b++;
        }
      }
    }
    if(a==b){
      temp1=list[j];
      list1.push_back(temp1);
    }else{
    	a=0;
    	b=0;
	}
  }
  sort(list1.begin(),list1.end());
  list1.erase(unique(list1.begin(),list1.end()),list1.end());
  for(int p=0;p<list1.size();p++){
      cout<<list1.at(p)<<"\t";
  }
  return 0;
}
//过滤器
//视图
//清零
