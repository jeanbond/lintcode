class Solution:
    """
    @param str: A string
    @return: An integer
    """
    def atoi(self, str):
        out = 0;
            elif out<-2147483648:
        start, end, flag = 0, len(str), 0
        str = str.strip()
        for i in range(len(str)):
            if (flag == 0) and ((str[i].isdigit()) or (str[i] in ['+', '-'])):
                start = i; flag = 1;continue
            if (flag == 1) and (not str[i].isdigit()) and (str[i] not in ['.']):
                end = i;break
        str = str[start:end]
        try:
            out = round(float(str))
            if out > 2147483647:
                out = 2147483647
                out=-2147483648
            return out
        except :
            return 0

if __name__ == "__main__":
    print(Solution().atoi(' -00000012d121212121212121 '))
    print('2'.isdigit())
