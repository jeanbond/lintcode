
using namespace std;

#include<vector>

class Solution {
public:
	vector<pair<int, double>> dicesSum(int n) {
		vector<pair<int, double>> ret;
		if (n < 1) { return ret; }

		// ��ʼ���м�״̬�洢�ռ䡣
		double **f = new double *[n + 1];
		for (int i = 0; i < n + 1; i++) {
			f[i] = new double[6 * n + 1];
		}
		memset(f, 0, sizeof(f));

		// ��ʼ��ֻ��һ�����ӵ������
		for (int i = 1; i <= 6; i++) {
			f[1][i] = 1.0 / 6;
		}

		for (int i = 2; i <= n; i++) { // ����ÿ�����Ӷ�����ǰ���ɫ�ӵĽ�������Ա�����ʼ�Ŀ�ʼ��
			for (int j = i; j <= (6 * i); j++) { // ��i�����ӣ��ܺͷ�ΧΪ�� i - 6i�����Ǳ����䡣
				for (int k = 1; k <= 6; k++) {   // �Ե�ǰ����i�ĵ�����j���ֱ���6�������Ҳ�������һ��ɫ�ӷֱ�Ͷ����1-6�������
					f[i][j] += f[i - 1][j - k];  // ÿ��Ͷ�����ĺ���ʵ����ǰ��һ�����Ӹ��ʵ��ۼӣ�
				}
				f[i][j] /= 6.0;                  // ǰ���ۼӵ���ʵֻ��F(A|B)������������6���������ĸ��ʺ͡�
			}
		}
		for (int i = n; i <= (6 * n); i++) {
			ret.push_back(make_pair(n, f[n][i])); // �����м�״̬����ѡ���������ĸ������뷵�صĿռ��з��أ�
		}
		return ret;
	}
};

int main() {
	Solution s = Solution();
	s.dicesSum(4);
	return 0;
}
