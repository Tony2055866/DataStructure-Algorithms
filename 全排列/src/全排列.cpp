//============================================================================
// Name        : ȫ����.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

//�������׳�
int f[20];

//���ݷ���ӡȫ����
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
		//ͳ���ڵ�ǰ���ֺ������Щ�����У��ȵ�ǰ����С�ĸ���
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
		//���Ҫ�õڼ�����(δ�ù�����)
		int cnt = kt / f[n - 1 - i];
		int k;
		for (k = 0; k < n; k++) {
			//δ�ù�����
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

	cout <<"ʹ�ÿ���չ��ʽ���㣺" << endl;
	//ʹ���濵��չ��ʽ ���� ȫ����
	int n = sizeof(arr) / sizeof(arr[0]);
	int number = f[n];
	for (int k = 0; k < number; k++) {
		int * res = convertKT(k, n);//�濵��չ��ʽ
		for (int i = 0; i < 4; i++)
			cout << arr[ res[i] ] << " ";

		int ktnum = kt(res, n);//����չ��ʽ
		cout <<" ;  kt=" <<ktnum << endl;
	}

	cout <<"ʹ�õݹ��ӡ��" << endl;
	perm(arr,0,n);
	return 0;
}
