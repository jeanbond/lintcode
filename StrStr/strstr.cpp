using namespace std;

#include<iostream>

class Solution {
public:
	/*
	* @param source: source string to be scanned.
	* @param target: target string containing the sequence of characters to match
	* @return: a index to the first occurrence of target in source, or -1  if target is not part of source.
	*/
	int strStr(const char *source, const char *target) {
		// write your code here
		if (source == NULL || target == NULL) { return -1; }
		if (target[0] == '\0') { return 0; }

		for (int i = 0; source[i] != '\0'; i++) {
			for (int j = 0; target[j] != '\0'; j++) {
				if (source[i+j] != target[j]) {
					break;
				}
				if (target[j+1] == '\0') {
					return i;
				}
			}
		}
		return -1;
	}
};

int main() {
	Solution s = Solution();
	cout<<s.strStr("abcdabcdefg", "bcd");
	system("pause");
	return 0;
}