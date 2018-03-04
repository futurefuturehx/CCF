#include<iostream>
#include<map>
using namespace std;
int main(){
    map<char,int> mymap;
    mymap['x']=100;
    mymap['y']=200;
    mymap['z']=300;
    mymap.clear();
    cout<<mymap.size()<<endl;
    return 0;
}//清空了 当然大小为0