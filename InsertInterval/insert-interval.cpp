
using namespace std;

#include<vector>
#include<iostream>

 class Interval {
 public:
     int start, end;
     Interval(int start, int end) {
         this->start = start;
         this->end = end;
     }
 };

 /* LINTCODE上显示有人用c++解决该问题只用了20多ms，我的程序用了200多ms，说明程序有很大的优化空间
	推荐不适用java，时间基本都超过1600ms。 */
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ret;		
		if (intervals.empty()) { ret.push_back(newInterval); return ret; }

		vector<int> upArea, downArea;
		bool flag1 = true, flag2 = true;

		// 上下标分别顺序进入缓存空间；
		for (unsigned int i = 0; i < intervals.size();) {
			if (intervals[i].start > newInterval.start && flag1) {
				downArea.push_back(newInterval.start);
				flag1 = false;
			}
			else {
				downArea.push_back(intervals[i++].start);
			}
		}
		for (unsigned int i = 0; i < intervals.size();) {
			if (intervals[i].end > newInterval.end && flag2) {
				upArea.push_back(newInterval.end);
				flag2 = false;
			}
			else {
				upArea.push_back(intervals[i++].end);
			}
		}		
		if (flag1) {downArea.push_back(newInterval.start);}
		if (flag2) {upArea.push_back(newInterval.end);}
		showM(downArea);
		showM(upArea);

		//使用栈控制区间
		int sta[1000] = { 0 };
		int i = 0, j = 0, top = -1;
		sta[++top] = downArea[i];  //必须初始化栈低位置，否则在包含的情况下出错；

		while (j < upArea.size()) {
			// 下标比上标小，就入栈
			if (i < downArea.size() && downArea[i] <= upArea[j]) {
				sta[++top] = downArea[i++];
			}
			else {		
				// 上标比下标小，就出栈
				top--;
				j++;
				// 栈空，得到序列；
				if (top < 1) {
					ret.push_back(Interval(sta[top+1], upArea[j - 1]));
				}
			}
		}
		return ret;
	
	}
	void showM(vector<int> in)
	{
		for (int i = 0; i < in.size(); i++) {
			cout << in[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Solution s = Solution();
	Interval insert = Interval(6, 8);
	vector<Interval> ret;
	ret.push_back(Interval(1, 5));
	s.insert(ret, insert);
	return 0;
}