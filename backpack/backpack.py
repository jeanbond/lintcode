

class Solution:
    """
    Error: time limit
    this is a typical pathon run-time-limit problem
    same code as cpp, problem solved;
    """
    def backPack(self, m, A):
        val = [0 for i in range(m+1)]

        for i in range(0, len(A)):
            for j in range(m, 0, -1):
                if j >= A[i]:
                    val[j] = max(val[j], val[j - A[i]]+A[i])
                    # print('node[%d] rest[%d] val[%d]' %(i-1, j,val[j]))
        return val[m]

if __name__ == "__main__": 
    print(Solution().backPack(10, [3,4,8,5]))
