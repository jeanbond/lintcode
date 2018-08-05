class Solution:
    '''
    这个测试函数是没返回值的，但是在lintcode中的测试用例是能通过的
    因为lint用例中间A数组的后半部分是有限制位置的，所以能通过；
    该问题注意细节即可，没有太多的技术难度，注重细节；
    '''
    def mergeSortedArray(self, A, m, B, n):
        if len(B) == 0: return
        A[:] = [i for i in A if i != 0]
        i, j, k, ret = 0, 0, 0, []
        while(i < len(A) and j < n):
            if A[i] <= B[j]:
                ret.append(A[i]); i += 1
            else:
                ret.append(B[j]); j += 1
        while i < len(A): ret.append(A[i]); i += 1
        while j < len(B): ret.append(B[j]); j += 1
        i = 0
        while i < len(ret):
            if i < len(A):
                if A[i] != ret[i]: A[i] = ret[i]
            elif i >= len(A): A.append(ret[i])
            i += 1

if __name__  == "__main__":
    ss = Solution()
    A = [1,2,3]; B = [4,5]
    print(ss.mergeSortedArray(A, len(A), B, len(B)))
