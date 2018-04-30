
using namespace std;

#include<vector>

class Solution {
public:
	vector<pair<int, double>> dicesSum(int n) {
		vector<pair<int, double>> ret;
		if (n < 1) { return ret; }

		// 初始化中间状态存储空间。
		double **f = new double *[n + 1];
		for (int i = 0; i < n + 1; i++) {
			f[i] = new double[6 * n + 1];
		}
		memset(f, 0, sizeof(f));

		// 初始化只有一个骰子的情况。
		for (int i = 1; i <= 6; i++) {
			f[1][i] = 1.0 / 6;
		}

		for (int i = 2; i <= n; i++) { // 由于每个骰子都依赖前面的色子的结果，所以必须从最开始的开始。
			for (int j = i; j <= (6 * i); j++) { // 对i个骰子，总和范围为： i - 6i，且是闭区间。
				for (int k = 1; k <= 6; k++) {   // 对当前骰子i的点数和j，分别有6种情况，也就是最后一个色子分别投出了1-6的情况；
					f[i][j] += f[i - 1][j - k];  // 每次投出来的和其实就是前面一次骰子概率的累加；
				}
				f[i][j] /= 6.0;                  // 前面累加的其实只是F(A|B)，这里必须除以6才是真正的概率和。
			}
		}
		for (int i = n; i <= (6 * n); i++) {
			ret.push_back(make_pair(n, f[n][i])); // 最后从中间状态中挑选符合条件的概率填入返回的空间中返回；
		}
		return ret;
	}
};

int main() {
	Solution s = Solution();
	s.dicesSum(4);
	return 0;
}
