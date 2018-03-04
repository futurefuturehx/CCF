#include<iostream>
#include<map>
using namespace std;
int main(){
    map<char,int> mymap;
    map<char,int>::iterator it;
    mymap['a'] = 100;
    mymap['b'] = 200;
    mymap['c'] = 300;
    map<char,int>::iterator it;
    for(it=mymap.begin();it!=mymap.end();++it)
        cout<<it->first<<"=>"<<it->second<<"\n";
    return 0;
}
//为什么要用it遍历呢 因为如果用.find()的话 就需要不断地写.find('a')之类
//这样从头遍历比较简单