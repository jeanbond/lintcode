
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

 /* LINTCODE����ʾ������c++���������ֻ����20��ms���ҵĳ�������200��ms��˵�������кܴ���Ż��ռ�
	�Ƽ�������java��ʱ�����������1600ms�� */
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> ret;		
		if (intervals.empty()) { ret.push_back(newInterval); return ret; }

		vector<int> upArea, downArea;
		bool flag1 = true, flag2 = true;

		// ���±�ֱ�˳����뻺��ռ䣻
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

		//ʹ��ջ��������
		int sta[1000] = { 0 };
		int i = 0, j = 0, top = -1;
		sta[++top] = downArea[i];  //�����ʼ��ջ��λ�ã������ڰ���������³���

		while (j < upArea.size()) {
			// �±���ϱ�С������ջ
			if (i < downArea.size() && downArea[i] <= upArea[j]) {
				sta[++top] = downArea[i++];
			}
			else {		
				// �ϱ���±�С���ͳ�ջ
				top--;
				j++;
				// ջ�գ��õ����У�
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