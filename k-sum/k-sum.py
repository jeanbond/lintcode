class Solution:
    """
    @param A: An integer array
    @param k: A positive integer (k <= length(A))
    @param target: An integer
    @return: An integer
    """
    def kSum(self, A, k, target):
        dp = [[0 for i in range(target+1)] for j in range(k+1)]
        dp[0][0] = 1
        '''
        dp2 = [[0 for i in range(target+1)]] * (k+1)
        print(id(dp[0]), id(dp[1]))
        print(id(dp2[0]), id(dp2[1]))
        '''
        self.show(dp)

        for i in A:
            for j in range(k, 0, -1):
                s = target
                while s >= i:
                    dp[j][s] += dp[j-1][s-i]
                    s -= 1
                    self.show(dp)
        return dp[k][target]
    
    def show(self, dp):
        if True:
            print(dp)

if __name__== '__main__':
    Solution().kSum([1,2,3,4], 2, 5)