# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def frequenciesOfElements(self, head: Optional[ListNode]) -> Optional[ListNode]:
        freq = {}
        current = head
        while current:
            freq[current.val] = freq.get(current.val, 0)+1
            current = current.next

        prev = None
        current = None
        prevHead = None
        for key, val in freq.items():
            current = ListNode(val)
            if not prevHead:
                prevHead = current
            if prev:
                prev.next = current
            prev = current
        return prevHead
