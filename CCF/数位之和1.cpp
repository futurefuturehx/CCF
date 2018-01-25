#include<iostream>
using namespace std;
int main(){
  long long int a;
  cin>>a;
  int temp;
  int total=0;
  while(a){
    temp=a%10;
    total+=temp;
    a=a/10;
  }
  cout<<total;
}
//有时候while比for条件灵活
