using namespace std;

#include<string>

class Solution {
public:
	// DP
	bool isInterleave(string &s1, string &s2, string &s3) {
		if (s1.empty() && s2.empty() && s3.empty()) { return true; }
		if (s1.empty() && s2.empty()) { return false; }
		if (s3.length() != (s1.length() + s2.length())) { return false; }

		/* 初始化状态缓存空间 */
		bool **dp = new bool *[s1.size() + 1];
		for (unsigned int i = 0; i < s1.size() + 1; i++) {
			dp[i] = new bool[s2.size() + 1];
			for (unsigned int j = 0; j <= s2.size(); j++) {
				dp[i][j] = false;
			}
		}

		/* 初始化原始条件 */
		for (unsigned int i = 1; i < s1.size() + 1; i++) {
			if (s1.at(i - 1) == s3.at(i - 1)) { dp[i][0] = true; }
		}
		for (unsigned int i = 1; i < s2.size() + 1; i++) {
			if (s2.at(i - 1) == s3.at(i - 1)) { dp[0][i] = true; }
		}

		/* 计算所有情况 */
		for (unsigned int i = 1; i <= s1.size(); i++) {
			for (unsigned int j = 1; j <= s2.size(); j++) {
				if (s1.at(i - 1) == s3.at(i + j - 1)) {
					dp[i][j] = dp[i - 1][j];
				}
				if (dp[i][j]) { continue; } // 如果能从s1推出，就不考虑s2的情况；
				if (s2.at(j - 1) == s3.at(i + j - 1)) {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
		/* 返回目标结果 */
		return dp[s1.size()][s2.size()];
	}
};

int main() {
	Solution s = Solution();
	string s1 = "aa";
	string s2 = "a";
	string s3 = "aaa";
	s.isInterleave(s1, s2, s3);
	system("pause");
	return 0;
 }