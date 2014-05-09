//============================================================================
// Name        : 全排列.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//先与计算阶乘
int f[20];

//回溯法打印全排序
void perm(int arr[], int k, int len) {
	if (k == len) {
		for (int i = 0; i < len; i++)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = k; i < len; i++) {
		swap(arr[i], arr[k]);
		perm(arr, k + 1, len);
		swap(arr[i], arr[k]);
	}
}

int kt(int arr[], int len) {
	int sum = 0;
	for (int i = 0; i < len; i++) {
		int k = 0;
		//统计在当前数字后面的那些数字中，比当前数字小的个数
		for (int j = i + 1; j < len; j++)
			if (arr[j] < arr[i])
				k++;
		sum += f[len - 1 - i] * k;
	}
	return sum;
}


int * convertKT(int kt, int n) {
	int * ans = new int[n];
	bool v[n];
	for (int i = 0; i < n; i++)
		v[i] = false;
	for (int i = 0; i < n; i++) {
		//算出要用第几个数(未用过的数)
		int cnt = kt / f[n - 1 - i];
		int k;
		for (k = 0; k < n; k++) {
			//未用过的数
			if (!v[k]) {
				if (cnt == 0)
					break;
				cnt--;
			}
		}
		ans[i] = k;
		v[k] = true;
		kt = kt % f[n - 1 - i];
	}
	return ans;
}

int main() {
	f[0] = 1;
	for (int i = 1; i < 20; i++)
		f[i] = i * f[i - 1];

	int arr[] = {6,7,8,9};

	cout <<"使用康拓展开式计算：" << endl;
	//使用逆康拓展开式 计算 全排列
	int n = sizeof(arr) / sizeof(arr[0]);
	int number = f[n];
	for (int k = 0; k < number; k++) {
		int * res = convertKT(k, n);//逆康拓展开式
		for (int i = 0; i < 4; i++)
			cout << arr[ res[i] ] << " ";

		int ktnum = kt(res, n);//康拓展开式
		cout <<" ;  kt=" <<ktnum << endl;
	}

	cout <<"使用递归打印：" << endl;
	perm(arr,0,n);
	return 0;
}
