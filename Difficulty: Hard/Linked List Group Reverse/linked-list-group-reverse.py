"""Node is defined as

class Node:
    def __init__(self, data):
		self.data = data
		self.next = None
"""


 
class Solution:
    def reverseKGroup(self, head, k):
        
        def findKthNode(node):
            count=1
            curr=node
            while curr and curr.next and count<k:
                curr=curr.next
                count+=1
            
            return curr
            
        def reverse(node):
            curr=node
            prev=None
            while curr:
                nextt=curr.next
                curr.next=prev
                prev=curr
                curr=nextt
                
            return prev
        
        temp=head
        while (temp):
            kthNode=findKthNode(temp)
            nextNode=kthNode.next
            kthNode.next=None
            
            reverse(temp)
            if (temp==head):
                head=kthNode
            else:
                prevNode.next=kthNode
            
            prevNode=temp
            temp=nextNode
        
        return head

#{ 
 # Driver Code Starts
class Node:

    def __init__(self, data):
        self.data = data
        self.next = None


class LinkedList:

    def __init__(self):
        self.head = None

    def push(self, new_data):
        new_node = Node(new_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        temp = self.head
        while temp:
            print(temp.data, end=" ")
            temp = temp.next
        print()


if __name__ == '__main__':
    t = int(input())  # Number of test cases
    while t > 0:
        llist = LinkedList()

        # Read list values and push them to the LinkedList
        values = list(map(int, input().split()))
        for i in reversed(values):
            llist.push(i)

        k = int(input())  # Size of the group for reversal
        ob = Solution()
        new_head = ob.reverseKGroup(llist.head, k)
        llist.head = new_head
        llist.printList()  # Print the modified linked list
        t -= 1

        print("~")

# } Driver Code Ends