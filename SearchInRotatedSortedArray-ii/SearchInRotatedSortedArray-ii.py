class Solution:
    """
    @param A: an integer rotated sorted array
    @param target: an integer to be searched
    @return: an integer
    """
    def search(self, A, target):
        if len(A) == 0: return False
        if len(A) == 1:
            if A[0] == target: return 0;
            else: return False

        midloc = 0
        for i in range(len(A)-1):
            if A[i] > A[i+1] : midloc = i;break
        pre = self.midS(A, target, 0, midloc)
        if pre != -1:return True
        tail = self.midS(A, target, midloc + 1, len(A) - 1)
        if tail != -1: return True
        return False

    # use mid search to find element location[0~n-1].
    # this function do not return True/False.
    def midS(self, A, target, start, end):
        while(start <= end):
            mid = (start + end) // 2
            if A[mid] < target: start = mid + 1
            elif A[mid] > target: end = mid - 1
            else: return mid
        return -1


if __name__ == "__main__":
        print(Solution().search([1,2,2,2,2,2,3,0], 222))