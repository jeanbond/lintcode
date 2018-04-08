
using namespace std;

#include<vector>
#include<iostream>

class Combination
{
	/* 组合 */
private:
	vector<vector<int>> out;
	vector<int> tmp;
	
public:
	void show(void) {
		cout << "The total count is : " << out.size() << " ." << endl;
		for (unsigned int i = 0; i < out.size(); i++) {
			for (unsigned int j = 0; j < out[i].size(); j++) {
				cout << out[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	bool isSelected(vector<int> in, int lowAdd, int val) {
		for (int i = lowAdd+1; i < in.size(); i++) {
			if (in[i] == val) { return true; }
		}
		return false;
	}

	/* 从total个钟取cnt个的组合个数 */
	int permut(vector<int> &in,int total, int cnt) {		
		if ((unsigned int)cnt > in.size()) { out.clear(); return -1; }

		/* tmp是类的局部缓存空间，用来存中间生成的序列，使用之前必须初始化 */
		if (tmp.size() < (unsigned int)total) {
			//reload tmp.
			for (int i = tmp.size(); i < cnt; i++) {
				tmp.push_back(-1);
			}
		}

		/* 和permutation类似，每个元素都有total-cnt个的选择，每个选择有两种处理方式：
			1、递归到最后了，直接缓存该元素。2、中间元素，继续在total-1中选取cnt-1个数的组合。、
			需要注意的是：total、cnt都是个数，从1开始计数，元素下表从0开始计数，故需要将total和
			cnt 减去1之后参与操作。 */
		for (int k = total - 1; k >= cnt-1 && k >= 0; k--) {
			/* 特别注意： 这个位置必须排除当前序列高位已经选入的数据，否则会有错误 */
			if (isSelected(tmp, cnt - 1, in[k])) { continue; }
			else{ tmp[cnt - 1] = in[k]; }
			
			// 大于1个元素，就执行下一层递归。
			if (cnt > 1) {
				permut(in, total -1, cnt - 1);
			}
			else {
				out.push_back(tmp);
			}
		}
		return 0;
	}
};

int main() {
	Combination d = Combination();
	vector<int> in = {0,1,2};
	d.permut(in,in.size(), 2);
	d.show();
	system("pause");
	return 0;
}