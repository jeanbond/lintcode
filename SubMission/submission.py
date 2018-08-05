class Solution:
    """
    @param: nums: a list of integers
    @return: A integer indicate the sum of minimum subarray
    """
    def minSubArray(self, nums):
        sum = 0; rslt = 99999999999;
        for i in range(len(nums)):
            sum += nums[i]
            rslt = min(rslt, sum)
            sum = min(0, sum)
        return rslt

if __name__ == '__main__':
    st = Solution()
    print(st.minSubArray([12,2,33,4,55,32,442]))