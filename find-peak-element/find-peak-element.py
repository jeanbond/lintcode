class Solution:
    """
    @param: A: An integers array.
    @return: return any of peek positions.
    """
    def findPeak(self, A):
        if len(A) < 1: return 0
        l, h, mid = 0, len(A)-1, 0
        while(l <= h):
            mid = (l + h) // 2
            if A[mid] < A[mid+1]:
                l = mid + 1
            else:
                h = mid - 1
        return l

if __name__ == '__main__':
    print(Solution().findPeak([1,2,3,5,6,3,6,7,2,3]))