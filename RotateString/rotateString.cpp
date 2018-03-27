using namespace std;

#include <string>

class Solution {
public:
	/**
	* @param str: An array of char
	* @param offset: An integer
	* @return: nothing
	*/
	void rotateString(string &str, int offset) {
		// write your code here
		if (!str.size()) { return; }
		offset %= str.size();

		for (int i = 1; i <= offset; i++) {		
			char tmp = str[str.size() - 1];			
			for (int j = str.size() - 1; j > 0; j--) {
				str[j] = str[j - 1];
			}
			str[0] = tmp;
		}
	}
};

int main() {
	Solution s = Solution();
	string str = string("");
	s.rotateString(str, 0);
	return 0;
}