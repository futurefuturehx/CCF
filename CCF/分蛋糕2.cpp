#include<iostream>
using namespace std;
int main(int argc, char const *argv[]) {
  int n,k,total=0,a[1004],fin=0;
  cin >>n>>k;
  for(int i=0;i<n;i++){
    cin>>a[i];
    total+=a[i];
    if(total>=k){
      fin++;
      total=0;
    }
  }
  if(total>0){
  	fin++;
  }
  cout << fin;
  return 0;
}
