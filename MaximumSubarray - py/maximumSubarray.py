class Solution:
    """
    @param nums: A list of integers
    @return: A integer indicate the sum of max subarray
    """
    def maxSubArray(self, nums):
        # write your code here
        sum=0;rslt=-99999999;
        for i in range(0,len(nums)):
            sum += nums[i]
            rslt = max(rslt,sum )
            sum = max(sum,0)
        return rslt

if __name__ == '__main__':
    se =Solution()
    print(se.maxSubArray([-1,-1,-1]))