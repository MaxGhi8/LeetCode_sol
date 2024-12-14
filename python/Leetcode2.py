class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:

        def rec(l1, l2):
            l3 = ListNode() # Initialize the new node l3
            tot = l1.val + l2.val
            
            # Handle the carry-over amount
            if tot > 9:
                tot -= 10
                if l1.next is not None:
                    l1.next.val += 1
                elif l2.next is not None:
                    l2.next.val += 1
                else:
                    l3.next = ListNode(val=1, next=None)
            
            # Assign the calculated total to l3
            l3.val = tot

            # Recursion
            if (l1.next is None) and (l2.next is None):
                return l3

            elif l1.next is None:
                l1.val = 0
                if l2.next.val < 10:
                    l3.next = l2.next
                    return l3
                else:
                    l2.next.val = 0
                    if l2.next.next is None:
                        l2.next.next = ListNode(1)
                    else:
                        l2.next.next.val += 1
                    l3.next = rec(l1, l2.next)

            elif l2.next is None:
                l2.val = 0
                if l1.next.val < 10:
                    l3.next = l1.next
                    return l3
                else:
                    l1.next.val = 0
                    if l1.next.next is None:
                        l1.next.next = ListNode(1)
                    else:
                        l1.next.next.val += 1
                    l3.next = rec(l1.next, l2)

            else:
                letters = set(s[idx:idx+pc-1])
                cc = pc-1

            while (idx + cc < L) and (s[idx + cc] not in letters):
                letters.add(s[idx + cc])
                cc += 1
                
            idx += 1
            pc = cc
            if cc > maximum:
                maximum = cc


        return maximum