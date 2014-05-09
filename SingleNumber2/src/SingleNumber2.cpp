//============================================================================
// Name        : SingleNumber2.cpp
// Author      : Gaotong
// Version     :
// Copyright   : www.acmerblog.com
// Description : leetCode, Single Number II.
// Your algorithm should have a linear runtime complexity.
// Could you implement it without using extra memory?
//============================================================================

#include <iostream>
using namespace std;

class Solution {
public:
	//依次计算每个位上的和，然后 %3
    int singleNumber(int A[], int n) {
    	int cnt, ans = 0;
    	for(int i=0; i<32; i++){
    		cnt = 0;
    		int ibit = (1<<i);
    		for(int j=0; j<n; j++){
    			cnt += ( (A[j] & ibit) > 0 );
    		}
    		ans |= ( (cnt%3) << i);
    	}
    	return ans;
    }
};

int main() {
	int arr[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
	Solution s;
	int size = sizeof(arr)/sizeof(arr[0]);
	int ans = s.singleNumber(arr,size );

	cout << ans << endl;
	return 0;
}
