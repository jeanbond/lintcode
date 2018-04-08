using namespace std;

#include<vector>
#include<iostream>

class Solution {
private:
	vector<int> tmp;

public:
	void show(vector<vector<int>> in) {
		cout << "The total count is : " << in.size() << endl;
		for (int i = 0; i < (int)in.size(); i++) {
			for (int j = 0; j < (int)in[i].size(); j++) {
				cout << in[i][j] << " ";
			}
			cout << endl;
		}
	}	

	int completePermut(vector<int> &in, int cnt, int total) {
		/* ���������������Ĳ�����ϸ���ͣ�
		   combination(vector<int> &in, int cnt, int total, vector<vector<int>> &out)��
				 cnt��ѡȡ�����ո�����total�Ǳ�ѡ�����еĸ��������Ǿ�����Ϊ0����СΪ1����Ϊ
				 ����ѡȡ��������Ϊ0��ֻ�ܴ�1��ʼ������
		   permut(vector<int> &in, int start,  int end, vector<vector<int>> &out)
				 ȫ���к����У�startλ�ô�0��ʼ�������޸ĺ�����1��ʼ����
				 end��ʾ���ǽ���λ�ã���0�����Ľ���λ�ã���
		   ����������������ʹ�õ�ʱ����ע�⣬���в��㡣 */
		vector<vector<int>> comRet;
		vector<vector<int>> ret;
		/* �ȴ��������ҵ�������� */
		combination(in, cnt, total,comRet);
		for (int i = 0; i < comRet.size(); i++) {
			/* Ȼ�����ÿ�������ȫ���� */
			vector<int> it = comRet[i];
			permut(it, 0, it.size(), ret);
		}
		show(ret);
		return 0;
	}

private:
	int isExsitedInHighLoc(vector<int> in, int loc, int val) {
		for (int i = loc+1; i < in.size(); i++) {
			if (in[i] == val) { return true; }
		}
		return false;
	}

	int combination(vector<int> &in, int cnt, int total, vector<vector<int>> &out) {
		if (cnt > total) { tmp.clear(); return -1; }
		for (int i = tmp.size(); i < cnt ; i++) {
			tmp.push_back(-1);
		}

		for (int j = total-1; j >= cnt-1 && j >= 0; j--) {
			/* �ų���ǰλ���ظ�ѡ���λ���Ѿ�ѡȡ�������ݣ���Ҫ */
			if (isExsitedInHighLoc(tmp, cnt - 1, in[j])) { continue; }
			tmp[cnt-1] = in[j];
			if (cnt > 1) {
				combination(in, cnt - 1, total - 1, out);
			}
			else {
				out.push_back(tmp);
			}
		}
		return 0;
	}

	/* --------------------------------------------------------------------------------
	���õ��ŵݹ飺 ֻ������ȫ����
		���Ǵ�0��ʼ����ȫ���У���������ѡȡN��Ԫ�أ�NΪ���Ԫ�صĸ��������������Ǳ�������ʼ
		������˳���ǹ̶��ģ����Ǳ����������̶���˳���Ͻ���ѡȡ���������ҡ���һ��ѡȡ��һ����
		�ڶ���ѡȡ�ڶ���... ... �Դ����ƣ�������һֱѡȡ�����һ��Ԫ�أ����Եݹ����˳�������Ϊ��
		��ǰѡȡԪ�ص��±�Ϊ���һ��Ԫ�أ����Ǿ��˳�������ǰ���м�¼�������������Ǹôε�ȫ���С�
		��ô�����м���κ�һ����������У��������Ԫ���ǵ�ǰ��M��Ԫ�أ�M<=N������M��Ԫ�ر���Ҫ��
		�����������Ϊ��1������Ҫ�ͺ���δ����ȫ�������ݵ�Ԫ�ؽ���λ�û����������µĿ����ԡ���ÿ��
		һ�ֿ��������棬��Ҫ��M+1��Ԫ�ؽ���ȫ���У��ݹ飩,��Ե�M��Ԫ�������˽�����M+1��ȫ����
		֮��������Ҫ����Ԫ�غ�ԭ��������Ԫ�ػָ�������Ҳ�������½����������ܱ�֤�б��˳��
		��Ϊ���ǵ����е������������֮һ���Ǹ����б�˳���Ǹ����ġ�һ�����ƣ�ȫ���оͳ����ˡ�
		-------------------------------------------------------------------------------
		������ֳ��������֣�0-start����λ�Ѿ�ѡ��õ����䣬start-endΪ��ѡ�������
		ÿ�δӴ�ѡ�������ѡ��һ�����룬Ȼ��ݹ���һ���غϣ�
		
	-----------------------------------------------------------------------------------*/
	int permut(vector<int> &in, int start,  int end, vector<vector<int>> &out) {
		if (end <= start) {
			out.push_back(in);
			return 0;
		}

		//��������
		for (int i = start; i < end; i++) {
			swap(in[i], in[start]);// ���������Ϊ�˻�ȡ������
			permut(in, start + 1, end, out);
			swap(in[i], in[start]);// ���������Ϊ�˻ָ���ԭ�����������У���Ϊ���ǵ�ǰ�������������ǹ̶��ģ�
								   // �ڹ̶���˳������ϵõ���ͬ�����й���
		}
		return 0;
	}

	void swap(int &a, int &b) {
		int tmp = a;
		a = b;
		b = tmp;
		return;
	}
};


int main() {
	Solution s = Solution();
	vector<int> in = {0,1,2};
	s.completePermut(in, 2, in.size());
	system("pause");
	return 0;
}


