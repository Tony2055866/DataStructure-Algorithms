//============================================================================
// Name        : ThreeSum.cpp
// Author      : Gaotong
// Version     :
// Copyright   : www.acmerblog.com
// Description : LeetCode Tree Sum. ³¬Ê±µÄ´úÂë£¡
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	 vector<vector<int> > ans;
    	if(num.size() < 3) return ans;
    	map<int,int> m;
        for(int i=0; i<num.size(); i++){
            m[num[i]] = i+1;
        }
        for(int i=0; i<num.size()-2; i++){
            int twoSum = 0 - num[i];
            for(int j=i+1; j<num.size()-1; j++){
                int f = m[twoSum - num[j]];
                if(f && f > (j+1) ){
                	//cout << i  <<" find: " <<j << " " << f-1 << "  " << twoSum <<  endl;
                    vector<int> tmp(3,0);
                    tmp[0]=num[i];
                    tmp[1]=num[j];
                    tmp[2]=num[f-1];
                    sort(tmp.begin(),tmp.end());
                    ans.push_back(tmp);
                }
            }
        }
        vector< vector<int> >::iterator it = ans.begin();
        sort(ans.begin(), ans.end());
        vector<vector<int> > ansU;
        if(ans.size() > 0)
        	ansU.push_back(ans[0]);
        for(int i=1; i<ans.size(); i++){
        	if(ans[i][0] != ans[i-1][0] || ans[i][1] != ans[i-1][1] || ans[i][2]!= ans[i-1][2])
        		ansU.push_back(ans[i]);
        }
        return ansU;
    }
};

int main() {
	Solution s;
	vector<int> v;
	v.push_back(0);
	v.push_back(1);
	v.push_back(1);
//	v.push_back(2);
//	v.push_back(-1);
//	v.push_back(4);
	vector<vector<int> > ans = s.threeSum(v);
	cout << ans.size() << endl;

	atoi("123");
	return 0;
}
