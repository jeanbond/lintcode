class Solution:
    """
    @param nums: An integer array
    @return: The length of LIS (longest increasing subsequence)
    """
    def longestIncreasingSubsequence(self, nums):
        if len(nums) < 1: return 0
        n = len(nums)
        ans = []
        ans.append(nums[0])
        for i in range(1, n):
            if nums[i] > ans[len(ans)-1]: ans.append(nums[i])
            else:
                for j in range(len(ans)):
                    if ans[j] > nums[i]:
                        ans[j] = nums[i]
                        break;
        return len(ans)



if __name__ == '__main__':
