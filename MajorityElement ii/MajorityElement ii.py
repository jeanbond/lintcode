class Solution:
    """
    @param: nums: a list of integers
    @return: find a  majority number
    """
    def majorityNumber(self, nums):
        # write your code here
        flag = {}
        for i in range(len(nums)):
            toint=nums[i]
            if toint not in flag.keys():
                flag[toint] = 1
            else:
                flag[toint] += 1
        for i in flag.keys():
            if flag[i] > len(nums)/3:
                return i