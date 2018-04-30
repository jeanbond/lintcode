using namespace std;

class Solution {
public:
	/**
	* @param number: A 3-digit number.
	* @return: Reversed number.
	*/
	int reverseInteger(int number) {
		if (number > 999 || number < 100) return -1;
		int sta[100] = { 0 };
		int top = -1;
		int ret = 0;
		while (number) {
			sta[++top] = number % 10;
			number /= 10;
		}
		for (int i = 0; i <= top; i++) {
			ret = (ret * 10) + sta[i];
		}
		return ret;
	}
};

int main() {
	Solution s = Solution();
	s.reverseInteger(123);
	return 0;
}