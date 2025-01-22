#User function Template for python3

''' Node for linked list:

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''
class Solution:
    def addTwoLists(self, num1, num2):
        # code here
        prev1 = None
        cur = num2
        while cur.data == 0:
            cur = cur.next
            if cur == None:
                break
        while cur != None:
            temp = cur.next
            cur.next = prev1
            prev1 = cur
            cur = temp
        prev2 = None
        cur = num1
        while cur.data == 0:
            cur = cur.next
            if cur == None:
                break
        while cur != None:
            temp = cur.next
            cur.next = prev2
            prev2 = cur
            cur = temp
        res = Node(-1)
        cur = res
        carry = 0
        while carry or prev1 or prev2:
            
            n1 = prev1.data if prev1 is not None else 0
            n2 = prev2.data if prev2 is not None else 0
            m_sum = carry + n1 + n2
            
            
            carry = m_sum//10
                
            cur.next = Node(m_sum%10)
            cur = cur.next
            prev1 = None if prev1 is None else prev1.next
            prev2 = None if prev2 is None else prev2.next
            
         
        res = res.next
        
        prev = None
        cur = res 
        while cur != None:
            temp = cur.next
            cur.next = prev
            prev = cur
            cur = temp
        
        if prev == None:
            return Node(0)
        return prev


#{ 
 # Driver Code Starts
#Initial Template for Python 3


# Node Class
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


# Linked List Class
class LinkedList:

    def __init__(self):
        self.head = None
        self.tail = None

    # creates a new node with given value and appends it at the end of the linked list
    def insert(self, val):
        if self.head is None:
            self.head = Node(val)
            self.tail = self.head
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next


# prints the elements of linked list starting with head
def printList(n):
    while n:
        print(n.data, end=' ')
        n = n.next
    print()


if __name__ == '__main__':
    for _ in range(int(input())):

        arr1 = (int(x) for x in input().split())
        num1 = LinkedList()
        for i in arr1:
            num1.insert(i)

        arr2 = (int(x) for x in input().split())
        num2 = LinkedList()
        for i in arr2:
            num2.insert(i)

        res = Solution().addTwoLists(num1.head, num2.head)
        printList(res)
        print("~")

# } Driver Code Ends