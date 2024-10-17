//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    // Function to split a linked list into two lists alternately
   vector<Node*> alternatingSplitList(struct Node* head) {
        // Your code here
        Node*head1 = head;
        Node*head2 = head->next;
        vector<Node*>v;
        v.push_back(head1);
        v.push_back(head2);
        if(head->next == NULL || head2->next == NULL)
        {
            if(head != NULL)
            head->next = NULL;
            if(head2 != NULL)
            head2->next = NULL;
            return v;
        }
        else
        {
            Node* slow = head1;
            Node* fast = head2;
            while(fast!=NULL && fast->next!=NULL)
            {
                slow->next = fast->next;
                slow = slow->next;
                fast->next = slow->next;
                fast = fast->next;
            }
            if(slow != NULL)
            slow->next = NULL;
            if(fast != NULL)
            fast->next = NULL;
            return v;
        }
        
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends