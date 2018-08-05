class Solution:
    """
    @param: nums: A list of integers
    @return: An integer denotes the sum of max two non-overlapping subarrays
    从左自右、从右自左分别遍历数组。每次遍历均记录当前最大的单子数组，用2个数组left,right保存。如left[i]的值表示nums从0至i中最大子数组的值，right[i]的值表示nums从i至size-1中最大子数组的值。
    最后遍历left,right数组，left[i]+right[i+1]表示在第i位拆分数组，得到其子数组的和。
    """

    def maxTwoSubArrays(self, nums):
        # write your code here
        sum = 0; result=nums[0]
        s1 = [0 for i in range(len(nums))]
        s2 =[0 for i in range(len(nums))]
        for i in range(0,len(nums),1):
            sum += nums[i]
            result = max(sum,result)
            sum = max(sum,0)
            s1[i] = result
        sum = 0; result=nums[len(nums)-1];
        for i in range(len(nums)-1,-1,-1):
            sum += nums[i]
            result = max(sum, result)
            sum = max(sum,0)
            s2[i] = result;
        result = -11111111111
        for i in range(0,len(nums)-1,1):
            result = max(result, s1[i]+s2[i+1])
        return result;


if __name__ == "__main__":
    si = Solution()
    print(si.maxTwoSubArrays([-1, -1]))