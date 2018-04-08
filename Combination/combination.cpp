
using namespace std;

#include<vector>
#include<iostream>

class Combination
{
	/* ��� */
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

	/* ��total����ȡcnt������ϸ��� */
	int permut(vector<int> &in,int total, int cnt) {		
		if ((unsigned int)cnt > in.size()) { out.clear(); return -1; }

		/* tmp����ľֲ�����ռ䣬�������м����ɵ����У�ʹ��֮ǰ�����ʼ�� */
		if (tmp.size() < (unsigned int)total) {
			//reload tmp.
			for (int i = tmp.size(); i < cnt; i++) {
				tmp.push_back(-1);
			}
		}

		/* ��permutation���ƣ�ÿ��Ԫ�ض���total-cnt����ѡ��ÿ��ѡ�������ִ���ʽ��
			1���ݹ鵽����ˣ�ֱ�ӻ����Ԫ�ء�2���м�Ԫ�أ�������total-1��ѡȡcnt-1��������ϡ���
			��Ҫע����ǣ�total��cnt���Ǹ�������1��ʼ������Ԫ���±��0��ʼ����������Ҫ��total��
			cnt ��ȥ1֮���������� */
		for (int k = total - 1; k >= cnt-1 && k >= 0; k--) {
			/* �ر�ע�⣺ ���λ�ñ����ų���ǰ���и�λ�Ѿ�ѡ������ݣ�������д��� */
			if (isSelected(tmp, cnt - 1, in[k])) { continue; }
			else{ tmp[cnt - 1] = in[k]; }
			
			// ����1��Ԫ�أ���ִ����һ��ݹ顣
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