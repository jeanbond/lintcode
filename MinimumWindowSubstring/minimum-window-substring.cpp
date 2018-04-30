
using namespace std;
#include<iostream>
#include<string>
#include<math.h>

class Solution {
public:
	string minWindow(string &source, string &target) {
		int srcHash[255] = { 0 };
		int targHash[255] = { 0 };
		//标记target字符串中所有字符出现的个数。
		for (unsigned int i = 0; i < target.size(); i++) {
			targHash[target[i]]++;
		}
		int found = 0, start, i;
		int minlen = source.size();
		int begin = -1, end = source.size();

		for (start = i = 0; i < source.size(); i++) {
			srcHash[source[i]]++;//source字符串中间每个字符进来一次，都必须将出现次数加一，是的srchash表及时更新；
			if (srcHash[source[i]] <= targHash[source[i]]) found++;// 如果srchash中的出现次数小于taghash中的出现次数，则表示找到了一个匹配字符；
			//当找到的匹配字符的个数和target的字符串长度相同的时候，表示找到了对应的子字符串，使用标量标记这个子字符串的起始位置和长度；
			if (found == target.size()) {
				//处理start到i位置的重复无用字符；缩小start到i之间的窗口区间；
				//只有在窗口中的数据，才能在srcHash表中计数，否则需要将计数减掉；
				while (start < i && srcHash[source[start]] > targHash[source[start]]) {
					srcHash[source[start]]--;
					start++;
				}
				// 找到start到i之间的最小窗口，使用begin、end、minlen标记起始位置和长度；
				if (i - start < minlen) {
					minlen = i - start;
					begin = start;
					end = i;
				}
				//为了启动下一个搜索，必须将窗口起始位置右移一位，需要做以下事情：
				//start加一
				//同时将非窗口内的字符计数减一
				//found计数减一，因为start位置肯定是属于found计数中的一个，start右移，表示丢失一个found元素；
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