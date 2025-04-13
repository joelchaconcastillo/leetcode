# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def negativeness(self, current: ListNode):
        while current:
            current.val *=-1
            current = current.next

    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        res = None
        self.negativeness(headA)
        current = headB
        while current and res == None:
            if current.val < 0:
                res = current
            current = current.next
        self.negativeness(headA)
        return res


        
