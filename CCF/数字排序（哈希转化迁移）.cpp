//利用哈希转化 正转化与逆转化 
//相当于加密与解密 
//可以使得一个角度能够携带更多角度的信息
//k是中间中间桥梁 这次循环的处理结果 留到下次循环使用
//可以用一种信息去表示另外一种信息 例如用排序好之后的相对位置来表示个数
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(int a, int b) {
	return a < b;
}
int main() {
	int n;
	int temp;
	int k = -1;
	cin >> n;
	vector<long int> list;
	vector<long int>list2;
	while (n--) {
		cin >> temp;
		list.push_back(temp);
	}
	sort(list.begin(), list.end(), cmp);//注意begin和end都要加上() 
	for (int i = 0; i<list.size()-1; i++) {//注意list.at(list.size()-1)是最后一位 而list.at(list.size()-2)是倒数第二位
		if (list.at(i) != list.at(i + 1) ) {
			list.at(i) = 1000 * list.at(i) + i - k;
			k = i;
			list2.push_back(list.at(i));
		}
	}
	list.at(list.size()-1)=1000*list.at(list.size()-1)+list.size()-1-k;
	list2.push_back(list.at(list.size()-1));
	for (int i = 0; i<list2.size() - 1; i++) {
		for (int j = i + 1; j<list2.size(); j++) {
			if (list2.at(j) % 1000 >= list2.at(i) % 1000) {
				temp = list2.at(i);
				list2.at(i) = list2.at(j);//一定要先备份 后赋值 最后交换 
				list2.at(j) = temp;
			}
		}
	}
	for (int i = 0; i<list2.size() - 1; i++) {
		for (int j = i + 1; j<list2.size(); j++) {
			if ((list2.at(j) % 1000 == list2.at(i) % 1000)&& (list2.at(j) / 1000<list2.at(i) / 1000)) {
				temp = list2.at(i);
				list2.at(i) = list2.at(j);//先备份 后赋值 最后交换 
				list2.at(j) = temp;
			}
		}
	}
	for (int i = 0; i<list2.size(); i++) {
		cout << list2.at(i) / 1000 <<" "<< list2.at(i) % 1000 << endl;
	}
}