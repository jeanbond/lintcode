using namespace std;

#include<vector>
#include<string>

class Solution {
public:
	/**
	* @param n: An integer
	* @return: A list of strings.
	*/
	vector<string> fizzBuzz(int n) {
		vector<string> ret = vector<string>();
		// write your code here
		for (int i = 1; i <= n; i++) {
			int n3 = ((i % 3 ==0) && (i/3)!=0) ? 1 : 0;
			int n5 = ((i % 5 == 0) && (i/5)!=0) ? 1 : 0;
			int n35 = (n3 & n5) ? 1 : 0;

			if (n35) { ret.push_back("fizz buzz"); }
			else if(n3) { ret.push_back("fizz"); }
			else if(n5) { ret.push_back("buzz"); }
			else { ret.push_back(to_string(i)); }
		}
		return ret;
	}
};

int main() {
	Solution s = Solution();
	s.fizzBuzz(15);
	return 0;
}