class Solution:
    """
    @param: chars: The letter array you should sort by Case
    @return: nothing
    """
    def sortLetters(self, chars):
        # write your code here
        tail = len(chars)-1
        head = 0
        while(head < tail):
            while((chars[head] < 'A' or chars[head]>'Z') and head<tail):
                head += 1
            while((chars[tail] < 'a' or chars[tail]>'z') and head<tail):
                tail -= 1
            chars[head], chars[tail] = chars[tail], chars[head]