
import os

class Solution:
    """
    @param nums: A list of integers
    @param k: An integer denote to find k non-overlapping subarrays
    @return: An integer denote the sum of max k non-overlapping subarrays
    只能做到 O(nk) 时间。
mustTheLast[ i ][ j ] 表示前 i 个数中 j 个子数组的最大子数组和，且第 i 个数是第 j 个子数组的元素。
notTheLast[ i ][ j ] 表示前 i 个数中 j 个子数组的最大子数组和，且第 i 个数不一定是第 j 个子数组的元素。

****时间复杂度 O（nk），  空间复杂度 O（nk） ****
    思路上和前面最大子串1/2是类似的，使用sum统计最大和，使用rslt缓存最大的值，只不过这里涉及到k个元素的时候
    有多种情况，所以使用n*k循环，每次更新mustThelast（sum）和notThelast（rslt），最后在rslt中返回值；
    """
    def maxSubArray(self, nums, k):
        # write your code here
        #mustTheLast[i][j] repesent the number i of nums must be the last number in the j-th subarrays.
        #notTheLast[i][j] repesent the number i of nums can be the last number in the j-th subarrays or not.
        #DP
        n = len(nums)
        mustTheLast = [[-1e9 for i in range(k+1)] for j in range(n+1)]
        notTheLast = [[-1e9 for i in range(k+1)] for j in range(n+1)]
        mustTheLast[0][0] = 0
        notTheLast[0][0] = 0
        #DP都必须给出原始状态，空间都必须向后偏移一个；
        #这里的k个元素里面第一个元素依然是从0开始计数的；
        for i in range(1, n+1):
            mustTheLast[i][0] = 0
            notTheLast[i][0] = 0
            for j in range(1, k+1):
                mustTheLast[i][j] = max(notTheLast[i-1][j-1] + nums[i-1], mustTheLast[i-1][j] + nums[i-1])
                notTheLast[i][j] = max(mustTheLast[i][j], notTheLast[i-1][j])
        return notTheLast[n][k]


class Solution2:
    def showAllDirs(self, path="c:\\"):
        cnt = 0
        for top, dirs, files in os.walk(path):
            for i in dirs:
                fullPath = os.path.join(top, i)
                if len(fullPath.split('\\')) <= 4:
                    print(fullPath)
                    cnt += 1
        return cnt

if __name__ == '__main__':
    test = Solution()
    ot = test.maxSubArray([-1,3,343,5],3)
    print(ot)
    s2 = Solution2()
    print('Total dir cont: %d' %s2.showAllDirs())