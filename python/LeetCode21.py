# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:

        def rec(l1, l2):
            l3 = ListNode()
            if l1 is None:
                return l2
            elif l2 is None:
                return l1
            else:
                if l1.val <= l2.val:
                    l3.val = l1.val
                    l3.next = rec(l1.next, l2)
                else:
                    l3.val = l2.val
                    l3.next = rec(l1, l2.next)
            return l3

        return rec(list1, list2)