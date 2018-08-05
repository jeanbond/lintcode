class Solution:
    """
    @param numbers: An array of Integer
    @param target: target = numbers[index1] + numbers[index2]
    @return: [index1, index2] (index1 < index2)
    """
    def twoSum(self, numbers, target):
        # write your code here
        ret = []
        for i in range(len(numbers)):
            for j in range(i+1, len(numbers),1):
                if numbers[i] + numbers[j] == target:
                    ret.append([i,j])
        return ret


if __name__ == '__main__':
    print(Solution().twoSum([1,2,3,4,5,6,7],7))