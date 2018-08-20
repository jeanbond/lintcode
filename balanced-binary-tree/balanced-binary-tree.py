"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param root: The root of binary tree.
    @return: True if this Binary tree is Balanced, or false.
    """
    def isBalanced(self, root):
        return False if self.deep(root)==-1 else True
    
    def deep(self, root):
        if root == None:
            return 0
        left = self.deep(root.left)
        right = self.deep(root.right)
        if left == -1 or right == -1 or abs(left-right)>1:
            return -1
        return max(left, right) + 1

    

if __name__ == '__main__':
    print(Solution().isBalanced(None))
