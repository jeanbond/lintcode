
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None

import sys

class Solution:
    """
    perfect recursion
    use min and max bound to limit every node area;
    """
    def isValidBST(self, root):
        if not root:return True
        return self.validt(root, -sys.maxsize, sys.maxsize)
    
    def validt(self, root, minVal, maxVal):
        if not root: return True
        #bound judgement;
        if root.val <= minVal or root.val >= maxVal: return False
        #recursion;
        return self.validt(root.left, minVal, root.val) and self.validt(root.right, root.val, maxVal)


if __name__ == '__main__':
    print(Solution().isValidBST(TreeNode(1)))
