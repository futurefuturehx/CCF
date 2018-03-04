#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
    map<int,string> mapStudent;//建立一个映射表
    mapStudent.insert(pair<int,string>(1,"student_one"));
    mapStudent.insert(pair<int,string>(2,"student_two"));
    mapStudent.insert(pair<int,string>(3,"student_three"));
    //.insert()来进行插入
    map<int,string>::iterator iter;//::iterator iter类似于*p map<int,string>类似于int
    for(iter=mapStudent.begin();iter!=mapStudent.end();iter++)
        cout<<iter->first<<' '<<iter->second<<endl;
}