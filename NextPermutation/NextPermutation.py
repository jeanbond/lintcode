class Solution:
    """
    @param: nums: A list of integers
    @return: A list of integers that's previous permuation
    """
    def nextPermutation(self, nums):
        # write your code here
        l = 0
        for i in range(len(nums)-1, 0, -1):
            if nums[i] > nums[i-1]:
                l = i-1
                break
            if i == 1:
                start, end = 0, len(nums)-1
                while(start > end):
                    nums[start], nums[end] = nums[end], nums[start]
                    start += 1; end -= 1;
                return nums
        for i in range(len(nums)-1, l, -1):
            if nums[i] > nums[l]:
                nums[i], nums[l] = nums[l], nums[i]
                break
        k = len(nums)-1; l += 1
        while(l < k):
            nums[l], nums[k] = nums[k], nums[l]
            l += 1; k -= 1;
        return nums



if __name__ == "__main__":
    print(Solution().nextPermutation([1,2]))