class Solution:
    """
    @param nums: A list of integers
    @return: An integer indicate the value of maximum difference between two substrings
    """

    def maxDiffSubArrays(self, nums):
        # write your code here
        s1 = self.subad(nums)
        nums.reverse()
        s2 = self.subad(nums)
        return max(s1, s2)

    def subad(self, nums):
        sum, maxx, minn, ret = 0, -9999999, 9999999, 0
        left, right = [], []

        for i in nums:
            sum += i
            maxx = max(maxx, sum)
            sum = max(sum, 0)
            left.append(maxx)
        sum = 0
        for i in range(len(nums) - 1, -1, -1):
            sum += nums[i]
            minn = min(minn, sum)
            sum = min(sum, 0)
            right.append(minn)
        right.reverse()
        for i in range(len(nums) - 1):
            ret = max(ret, abs(left[i] - right[i + 1]))
        return ret

if __name__ == "__main__":
    so = Solution()
    print(so.maxDiffSubArrays([1,2,3,23,2,5,54,566,6,63]))