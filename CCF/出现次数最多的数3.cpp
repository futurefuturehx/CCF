#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<int> list1;
	int sum[1000],count[1000];
	int number;
	int i,j=0,temp,m=0;
	int n,total=0,counter=1;
	cin >> n;
	for(i=0;i<n;i++){
		cin >> temp;
		list1.push_back(temp);
	}
	sort(list1.begin(),list1.end());
	for(i=0;i<n;i++){
		total = list1[i];
		for(j=i+1;j<n;j++){
			if(list1[i]==list1[j]){
				total+=list1[i];
				counter++;
			}
			else
				break;
		}
		sum[m]=total;
		count[m]=counter;
		i=j-1;
		counter=1;
		m++;
	}
	for(i=1;i<m;i++){
		if (count[0]<count[i]){
			count[0]=count[i];
			sum[0]=sum[i];
		}
		else if (count[0]==count[i]){
			if (sum[0]>sum[i]){
				sum[0]=sum[i];
				count[0]=count[i];
			}
		}
	}
	number = sum[0]/count[0];
	cout << sum[0]/count[0];
	return 0;
}
//类指针跳转 i=j-1;原来for循环可以控制跳转
//规整思维 可以通过sort来排序简化
//记录思维 一个数组就是一个记录 通过唯一不变的索引进行唯一对应
