
using namespace std;
#include<iostream>
#include<string>
#include<math.h>

class Solution {
public:
	string minWindow(string &source, string &target) {
		int srcHash[255] = { 0 };
		int targHash[255] = { 0 };
		//���target�ַ����������ַ����ֵĸ�����
		for (unsigned int i = 0; i < target.size(); i++) {
			targHash[target[i]]++;
		}
		int found = 0, start, i;
		int minlen = source.size();
		int begin = -1, end = source.size();

		for (start = i = 0; i < source.size(); i++) {
			srcHash[source[i]]++;//source�ַ����м�ÿ���ַ�����һ�Σ������뽫���ִ�����һ���ǵ�srchash��ʱ���£�
			if (srcHash[source[i]] <= targHash[source[i]]) found++;// ���srchash�еĳ��ִ���С��taghash�еĳ��ִ��������ʾ�ҵ���һ��ƥ���ַ���
			//���ҵ���ƥ���ַ��ĸ�����target���ַ���������ͬ��ʱ�򣬱�ʾ�ҵ��˶�Ӧ�����ַ�����ʹ�ñ������������ַ�������ʼλ�úͳ��ȣ�
			if (found == target.size()) {
				//����start��iλ�õ��ظ������ַ�����Сstart��i֮��Ĵ������䣻
				//ֻ���ڴ����е����ݣ�������srcHash���м�����������Ҫ������������
				while (start < i && srcHash[source[start]] > targHash[source[start]]) {
					srcHash[source[start]]--;
					start++;
				}
				// �ҵ�start��i֮�����С���ڣ�ʹ��begin��end��minlen�����ʼλ�úͳ��ȣ�
				if (i - start < minlen) {
					minlen = i - start;
					begin = start;
					end = i;
				}
				//Ϊ��������һ�����������뽫������ʼλ������һλ����Ҫ���������飺
				//start��һ
				//ͬʱ���Ǵ����ڵ��ַ�������һ
				//found������һ����Ϊstartλ�ÿ϶�������found�����е�һ����start���ƣ���ʾ��ʧһ��foundԪ�أ�
				srcHash[source[++start]]--;
				found--;
			}
		}
		return begin == -1 ? "" : source.substr(begin, end - begin + 1);
	}
};


int  main() {
	Solution s = Solution();
	string src = string("abcd");
	string targ = string("ac");
	s.minWindow(src, targ);
	system("pause");
	return 0;
}