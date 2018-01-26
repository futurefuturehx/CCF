#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	int k;
	int flag=0;
	vector<int> list;
	vector<int>::iterator iter;
	cin >> n;
	cin >> k;
	for(int i=0;i<n;i++){
		list.at(i)=i+1;
	}
	while (list.size()>1) {
		  if (flag=1) {
			   for (int i = 0; i < list.size(); i++){
				    if (i == 0) {
					     list.at(0)=list.at(list.size()-1)+1;
           			  }else{
          			  list.at(i)=list.at(i-1)+1;
        		   }
				}
		}
    	for(iter=list.begin();iter!=list.end();){
     		 if(*iter%k==0||*iter/k==0){
      		  iter=list.erase(iter);
   	 	 	 }else{
     	 	iter++;
		  }
      flag=1;
      }
	}
  cout<<list.at(0);
  return 0;
}
list.end()只是返回最后的位置坐标
String中的erase也就是说有三种用法：
（1）erase(pos,n); 删除从pos开始的n个字符，比如erase(0,1)就是删除第一个字符
（2）erase(position);删除position处的一个字符(position是个string类型的迭代器)
（3）erase(first,last);删除从first到last之间的字符（first和last都是迭代器）
Vector中的的erase用法：(需要用到迭代器)
vector<int>::iterator iter;
for (iter = vec.begin(); iter != vec.end(); )
  {
      if (*iter == 5)
          iter = vec.erase(iter);
      else
          iter++;
  }
  iter类似于指针 需要写* 还需要iter++偏移
  用iter之后更针对vector本身 而不是控制
//直到机while()
//临点突变 传递心意 的快递员flag变量
//顺读机器思维 上一个list.at(i)不是现在的list.at(i)
