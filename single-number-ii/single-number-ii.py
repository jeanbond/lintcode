class Solution:
    '''
    Warning:  following class data define is not accept by lintcode online judge;
              it is possible to use less globe data define  when we use online judge;
              All online judge plat have this bug;
    dataBitLen = 32
    repeatTimes = 3
    mask = [0 for i in range(dataBitLen)]
    '''
    def singleNumberII(self, A):
        #max bit len for normal integer;
        dataBitLen = 32
        #repeat time;
        repeatTimes = 3
        mask = [0 for i in range(dataBitLen)]
        rst = 0
        if len(A) < repeatTimes :return A[0]

        #mask all input in mask;
        for i in range(len(mask)):
            for j in range(len(A)):
                mask[i] += ((A[j] >> i) & 1)
            mask[i] %= repeatTimes
            rst |= (mask[i] << i)
        return rst

if __name__ == '__main__':
    print(Solution().singleNumberII([6,1,1,1,2,2,2,4,5,6,4,5,0,4,5,6]))
