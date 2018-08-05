class Solution:
    """
    @param A: an integer sorted array
    @param target: an integer to be inserted
    @return: a list of length 2, [index1, index2]
    """
    def searchRange(self, A, target):
        start, end, flag = 0, len(A)-1, False
        while(start <= end):
            mid = (start+end) // 2
            if A[mid] < target: start = mid + 1
            elif A[mid] > target: end = mid - 1
            else : flag = True; start = end = mid; break
        if flag :
            while start > 0 and A[start] == A[start-1]:start -= 1
            while end < len(A) - 1 and A[end] == A[end+1]: end += 1
            return [start, end]
        else: return [-1, -1]

if __name__ == "__main__":
    print(Solution().searchRange([1], 1))