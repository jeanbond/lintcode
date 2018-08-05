
class Solution:
    """
    @param: nums: a list of integers
    @return: A integer indicate the sum of minimum subarray
    和最大子串的问题思路一致，如有疑问，参考最大子串问题（1,2,3）
    """
    def minSubArray(self, nums):
        sum = 0; rslt = 99999999999;
        for i in range(len(nums)):
            sum += nums[i]
            rslt = min(rslt, sum)
            sum = min(0, sum)
        return rslt



if __name__ == '__main__':
    se = Solution()
    print(se.minSubArray([-1,2,-3,-3,4,5,-3]))