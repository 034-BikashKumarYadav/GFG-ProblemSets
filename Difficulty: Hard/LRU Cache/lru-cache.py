#User function Template for python3

# design the class in the most optimal way

class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.prev = None
        self.next = None

class LRUCache:

    def __init__(self, cap):
        """
        Initialize the LRUCache with a given capacity.
        """
        self.capacity = cap
        self.cache = {}  # Hashmap to store key-node pairs
        self.head = Node(0, 0)  # Dummy head node
        self.tail = Node(0, 0)  # Dummy tail node
        self.head.next = self.tail
        self.tail.prev = self.head

    def _remove(self, node):
        """
        Remove a node from the doubly linked list.
        """
        prev_node = node.prev
        next_node = node.next
        prev_node.next = next_node
        next_node.prev = prev_node

    def _add(self, node):
        """
        Add a node right after the head.
        """
        next_node = self.head.next
        self.head.next = node
        node.prev = self.head
        node.next = next_node
        next_node.prev = node

    def get(self, key):
        """
        Return the value of the key if it exists in the cache; otherwise, return -1.
        """
        if key in self.cache:
            node = self.cache[key]
            self._remove(node)  # Move the accessed node to the head (most recently used)
            self._add(node)
            return node.value
        return -1

    def put(self, key, value):
        """
        Add a key-value pair to the cache. If the cache exceeds capacity,
        remove the least recently used item.
        """
        if key in self.cache:
            # If the key exists, remove the old node
            self._remove(self.cache[key])
        elif len(self.cache) == self.capacity:
            # If at capacity, remove the least recently used item (tail's previous node)
            lru_node = self.tail.prev
            self._remove(lru_node)
            del self.cache[lru_node.key]

        # Add the new node to the cache and the linked list
        new_node = Node(key, value)
        self.cache[key] = new_node
        self._add(new_node)




#{ 
 # Driver Code Starts
#Initial Template for Python 3


def inputLine():
    return input().strip().split()


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        capacity = int(input())
        cache = LRUCache(capacity)

        queries = int(input())
        for __ in range(queries):
            vec = inputLine()
            if vec[0] == "PUT":
                key = int(vec[1])
                value = int(vec[2])
                cache.put(key, value)
            else:
                key = int(vec[1])
                print(cache.get(key), end=" ")
        print()
        print("~")

# } Driver Code Ends