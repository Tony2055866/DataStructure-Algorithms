//============================================================================
// Name        : leetCode-InsertInterval.cpp
// Author      : Gaotong
// Version     :
// Copyright   : www.acmerblog.com
// Description : Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

  struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
//  bool cmp(const Interval & inter1,const Interval & inter2){
//	  return inter1
//  }
  bool overlap(const Interval & inter1,const Interval & inter2){
  		return inter1.start <= inter2.end && inter1.end >= inter2.start;
  }
  class Solution {
  public:

      vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	  vector<Interval> ans;
    	  int i;
    	  bool addNew = false; //新添加的区间 是否被合并
    	  for( i=0; i<intervals.size(); i++){
    		  if( overlap(intervals[i], newInterval) ){
    			  newInterval.start = min( newInterval.start, intervals[i].start );
    			  newInterval.end = max( newInterval.end, intervals[i].end );
    		  }else if(newInterval.end < intervals[i].start){
    			  ans.push_back(newInterval);
    			  addNew = true;
    			  break;
    		  }else{
    			  ans.push_back(intervals[i]);
    		  }
    	  }
    	  for(; i<intervals.size(); i++)  ans.push_back(intervals[i]);
    	  if(!addNew) ans.push_back(newInterval);
    	  return ans;
      }
  };
int main() {
	Solution s;
	vector<Interval> vs;
	vs.push_back(Interval(10,12));
//	vs.push_back(Interval(3,5));
//	vs.push_back(Interval(6,7));
//	vs.push_back(Interval(8,10));
//	vs.push_back(Interval(12,16));

	Interval inter(4,9);
	vector<Interval> ans = s.insert(vs, inter);
	cout << ans.size() << endl;
	cout << ans[0].start << endl;
	return 0;
}
