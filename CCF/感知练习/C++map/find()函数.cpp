#include<iostream>
#include<map>
using namespace std;
int main(){
    map<char,int>mymap;
    map<char,int>::iterator it;
    mymap['a']=50;
    mymap['b']=100;
    mymap['c']=150;
    mymap['d']=200;
    //键值赋值
    cout<<mymap.find('b')->second<<endl;//first表示键 second表示值
    cout<<mymap.find('a')->first<<' '<<mymap.find('a')->second<<endl;
    if(mymap.find('a')->first=='a')
    cout<<' '<<mymap.find('a')->second<<endl;
    return 0;
}