class Solution:
    """
    @param A: An integer array
    @return: An integer
    """
    def singleNumber(self, A):
        ret = 0
        for i in A:
            ret ^= i
        return ret

if  __name__ == "__main__":
    print(Solution().singleNumber([1,2,1,2,3]))