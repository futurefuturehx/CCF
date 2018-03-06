#include<iostream>
#include<map>
using namespace std;
int main(){
    //一个是值类型 一个是类变量类型 值更高层一些
    map<char,int> mymap;
    map<char,int>anothermap;
    mymap.insert(pair<char,int>('z',200));
    //插入有别于赋值
    pair<map<char,int>::iterator,bool>ret;
    ret = mymap.insert(pair<char,int>('z',500));
    if(ret.second==false){
        cout<<"element"<<ret.first->first<<"'already existed";
        cout<<"with a value of"<<ret.first->second<<'\n';
    }
    else{
        cout<<"element"<<ret.first->first<<"'creat successfully";
        cout<<"with a value of"<<ret.first->second<<'\n';
    }
    //第二种插入方式 插入到特定位置 加入指针it可以不局限于只插入到首部或者末尾
    map<char,int>::iterator it=mymap.begin();//通过it=.begin()之类 it就是一个位置索引了
    mymap.insert(it,pair<char,int>('b',300));
    mymap.insert(it,pair<char,int>('c',400));
    //第三种插入方式 通过一个准备好的map某个范围插入到另一个
    anothermap.insert(mymap.begin(),mymap.find('c'));//.find()本质上类似于.begin()
    //第四种插入方式 插入单个值
    mymap.insert(map<char,int>::value_type('x',20000000));
    //第五种插入方式
    cout<<"mymap contains:\n";
    for(it=mymap.begin();it!=mymap.end();++it)
        cout<<it->first<<"=>"<<it->second<<'\n';
    cout<<"another contains:\n";
    for(it=anothermap.begin();it!=anothermap.end();++it)
        cout<<it->first<<"=>"<<it->second<<"\n";
    return 0;
}
