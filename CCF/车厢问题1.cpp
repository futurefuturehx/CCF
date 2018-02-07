#include<iostream>
#include<vector>
using namespace std;
typedef struct {
	int num;
	int flag;
	int bianhao[5];
}leixin;
//而且必须要先typedef
//结构体最好定义在函数体外面
//结构体本身可以是数组
//里面也可以有数组
int main(){
	leixin std[20];
	int n;
	int temp;
	int count = 0;
	int qishi = 1;
	int bidui[100];
	vector<int> list;
	for (int i = 0; i < 100; i++) {
		bidui[i] = i + 1;
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		std[i].num = temp;
	}
	std[0].flag = 0;
	for (int i = 1; i < n; i++) {
		std[i].flag = 0;
		for (int j = 0; j < i; j++) {
			if (std[i].num + std[j].num <= 5) {
				std[i].flag = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (std[i].flag == 0) {
			for (int j = 0; j < std[i].num; j++) {
				std[i].bianhao[j] = qishi + j;
                bidui[qishi+j-1]=101;//有简单的对应关系 就用对应关系
				}//对应删选
			}
			qishi = 5 + qishi;//起始值不断变化
		}
	for(int i=0;i<100;i++){
		if(bidui[i]!=101){
			list.push_back(bidui[i]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (std[i].flag == 1) {
			for(int j=0;j<std[i].num;j++){
				std[i].bianhao[j]=list.at(i);
				list.remove(i);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < sizeof(std[i].num); j++) {//普通数组是用sizeof() vector才用size()
			cout << std[i].bianhao[j] << " ";//大小不就是num吗 预先保存了呀
		}
		cout << endl;
	}
	return 0; }
