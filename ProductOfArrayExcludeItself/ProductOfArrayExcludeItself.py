class Solution:
    """
    @param: nums: Given an integers array A
    @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
    """
    def productExcludeItself(self, nums):
        # write your code here
        out=[]
        for i in range(len(nums)):
            tmp = 1
            for j in range(len(nums)):
                if i!=j:
                    tmp *= nums[j]
            out.append(tmp)
        return out


if __name__ == "__main__":
    so = Solution()
    print(so.productExcludeItself([12,2,3,4,4,5,5,6,54]))