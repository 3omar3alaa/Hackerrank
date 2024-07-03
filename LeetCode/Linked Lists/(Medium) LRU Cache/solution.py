from collections import defaultdict


class ListNode:
    def __init__(self, key, val):
        self.key = key
        self.val = val
        self.next = None
        self.prev = None

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.dic = defaultdict(ListNode)
        self.head = ListNode(-1, -1)
        self.tail = ListNode(-1, -1)
        self.head.next = self.tail # dummy
        self.tail.prev = self.head # dummy

    def get(self, key: int) -> int:
        if key not in self.dic:
            return -1

        node = self.dic[key]
        self._remove(node)
        self._add(node)
        return node.val


    def put(self, key: int, value: int) -> None:
        if key in self.dic:
            old_node = self.dic[key]
            self._remove(old_node)

        node = ListNode(key, value)
        self.dic[key] = node
        self._add(node)

        if len(self.dic) > self.capacity:
            node_to_delete = self.head.next
            self._remove(node_to_delete)
            del self.dic[node_to_delete.key]

    def _add(self, node: ListNode) -> int:
        node.next = self.tail
        node.prev = self.tail.prev
        prevNode = self.tail.prev
        prevNode.next = node
        self.tail.prev = node

    def _remove(self, node: ListNode) -> None:
        prevNode = node.prev
        nextNode = node.next
        prevNode.next = node.next
        nextNode.prev = prevNode

    

            


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)