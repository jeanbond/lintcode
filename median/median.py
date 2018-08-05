
class Solution:
    """
    @param nums: A list of integers
    @return: An integer denotes the middle number of the array
    """
    def median(self, nums):
        if len(nums) < 1: return 0
        self.qsort(nums, 0, len(nums)-1)
        print(nums)
        idx = int(len(nums)/2) if len(nums)%2 != 0 else int(len(nums)/2-1)
        return nums[idx]

    def partition(self, nums, low, high):
        key, l, h = nums[low], low, high
        while l < h:
            while l < h and key <= nums[h]: h -= 1
            nums[l], nums[h] = nums[h], nums[l]
            while l < h and key >= nums[l]: l += 1
            nums[l], nums[h] = nums[h], nums[l]
        return l
    def qsort(self, nums, start, end):
        if len(nums) < 1: return 0
        if start >= end : return
        loc = self.partition(nums, start, end)
        self.qsort(nums, start, loc-1)
        self.qsort(nums, loc+1, end)



if __name__ == '__main__':
    print(Solution().median([2,3423,4,423,43,9]))