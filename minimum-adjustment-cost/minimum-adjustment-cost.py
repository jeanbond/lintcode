import sys

class Solution:
    """
    @param: A: An integer array
    @param: target: An integer
    @return: An integer
    """
    def MinAdjustmentCost(self, A, target):
        n = len(A)
        dp = [[sys.maxsize for i in range(101)] for j in range(len(A)+1)]
        # init 0 loc for calculating;
        for i in range(101):
            dp[0][i] = 0
        
        for i in range(1, len(A)+1):
            for j in range(101):
                for k in range(101):
                    if abs(j-k) <= target: #when target is legal(equal is legal);
                        '''
                        dp[i-1][k]: the cost of pre number adjust to k;
                        abs(A[i-1]-j): the cost of current number adjust to j;
                        when adjustment is legal, get the minmal one to record the cost;
                        '''
                        dp[i][j] = min(dp[i-1][k]+abs(A[i-1]-j), dp[i][j])

        #self.show(dp, 4)
        mincost = sys.maxsize
        # get the minmal cost;
        for i in range(100):
            mincost = mincost if mincost < dp[n][i] else dp[n][i]
        return mincost
    
    def show(self, ans, cnt):
        # show data;
        for i in range(len(ans)):
            print(ans[i][:cnt])
        

if __name__ == '__main__':
    print(Solution().MinAdjustmentCost([1,4,2,3], 1))