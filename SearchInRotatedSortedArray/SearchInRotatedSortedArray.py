class Solution:
    """
    @param A: an integer rotated sorted array
    @param target: an integer to be searched
    @return: an integer
    """
    def search(self, A, target):
        if len(A) == 0: return -1
        if len(A) == 1:
            if A[0] == target: return 0;
            else: return -1

        midloc = 0
        for i in range(len(A)-1):
            if A[i] > A[i+1] : midloc = i;break
        pre = self.midS(A, target, 0, midloc)
        if pre != -1:return pre
        tail = self.midS(A, target, midloc + 1, len(A) - 1)
        if tail != -1: return tail
        return -1

    def midS(self, A, target, start, end):
        while(start <= end):
            mid = (start + end) // 2
            if A[mid] < target: start = mid + 1
            elif A[mid] > target: end = mid - 1
            else: return mid
        return -1

if __name__ == "__main__":
    print(Solution().search([], 1))