
using namespace std;

#include<iostream>
#include<vector>
#include <algorithm>



class Solution {
public:
    /**
     DP solution
     to see the dp when dp is the status of rest value;
     */
    int backPack(int m, vector<int> &A) {
		vector<int> val(m + 1, 0);
        
        for(int i = 0; i < (m + 1); i++){
            val[i] = 0;
        }

        for(int i = 0; i < A.size(); i++){
            for(int j = m; j > 0; j--){
                if(j >= A[i]){
                    val[j] = max(val[j], val[j-A[i]]+A[i]);
                }
            }
        }
		return val[m];
    }
};

int main(int argc, char const *argv[])
{
    vector<int> a = { 20,15,15,15,15,15,15,15,15,15,15,15,15,15,15,7,2,15,15,15,15 };
    cout<< Solution().backPack(10, a) << endl;
	system("pause");
    return 0;
}
