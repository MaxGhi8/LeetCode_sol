# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def getIntersectionNode(
        self, headA: ListNode, headB: ListNode
    ) -> Optional[ListNode]:
        lenA = self.get_len(headA, 0)
        lenB = self.get_len(headB, 0)
        return self.helper(headA, headB, lenA, lenB)

    def get_len(self, linked_list, tot):
        if linked_list.next == None:
            return tot + 1
        else:
            return self.get_len(linked_list.next, tot + 1)

    def helper(self, listA, listB, lenA, lenB):
        if lenA == 0 or lenB == 0:
            return
        elif lenA < lenB:
            return self.helper(listA, listB.next, lenA, lenB - 1)
        elif lenA > lenB:
            return self.helper(listA.next, listB, lenA - 1, lenB)
        else:
            if listA is listB:
                return listA
            else:
                return self.helper(listA.next, listB.next, lenA - 1, lenB - 1)
