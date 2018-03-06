#include<iostream>
#include<list>
using namespace std;
int main(){
    //通过数组进行赋值
    int myints[]={75,23,65,42,13};
    list<int>mylist (myints,myints+5);
    cout<<"mylist contains:";
    //使用it正序遍历
    for(list<int>::iterator it=mylist.begin();it!=mylist.end();++it){
        cout<<' '<<*it;
    cout<<'\n';
    mylist.clear();
    //通过push_back进行赋值
    for(int i=1;i<=5;++i) mylist.push_back(i);
    cout<<"mylist backwards:";
    //使用rit反序遍历
    for(list<int>::reverse_iterator rit=mylist.rbegin();rit!=mylist.rend();++rit)
        cout<<' '<<*rit;
    cout<<'\n';
    return 0;
    }
}