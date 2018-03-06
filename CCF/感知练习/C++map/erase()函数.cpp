#include<iostream>
#include<map>
using namespace std;
int main(){
    map<char,int> mymap;
    map<char,int>::iterator it;
    mymap['a']=10;
    mymap['b']=20;
    mymap['c']=30;
    mymap['d']=40;
    mymap['e']=50;
    mymap['f']=60;
    it =mymap.find('b');
    mymap.erase(it);
    //通过索引进行erase删除
    it=mymap.find('c');
    it=mymap.find('e');
    mymap.erase(it,mymap.end());
    for(it=mymap.begin();it!=mymap.end();++it)
        cout<<it->first<<"=>"<<it->second<<'\n';
        //对于结构体 普通有. 特殊有->
    cout<<mymap.size();
    return 0;
}
//erase()函数实现范围删除
//或者配合find()得到索引 实现特定删除