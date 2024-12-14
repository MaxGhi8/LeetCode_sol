# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        else:
            return self.helper(root, 0)

    def helper(self, root, depth):
        if root.left is None and root.right is None:
            return depth + 1
        elif root.left is None:
            return max([depth + 1, self.helper(root.right, depth + 1)])
        elif root.right is None:
            return max([self.helper(root.left, depth + 1), depth + 1])
        else:
            return max(
                [self.helper(root.left, depth + 1), self.helper(root.right, depth + 1)]
            )
