// Sort a Doubly Linked List (GeeksforGeeks Problem)
class Solution {
public:

    Node* merge(Node* first, Node* second) {

        if(!first) return second;
        if(!second) return first;

        if(first->data <= second->data) {

            first->next = merge(first->next, second);

            if(first->next)
                first->next->prev = first;

            first->prev = NULL;

            return first;
        }
        else {

            second->next = merge(first, second->next);

            if(second->next)
                second->next->prev = second;

            second->prev = NULL;

            return second;
        }
    }

    Node* findMid(Node* head) {

        Node* slow = head;
        Node* fast = head;

        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* sortDoubly(Node* head) {

        if(head == NULL || head->next == NULL)
            return head;

        Node* mid = findMid(head);

        Node* second = mid->next;

        mid->next = NULL;

        if(second)
            second->prev = NULL;

        Node* left = sortDoubly(head);
        Node* right = sortDoubly(second);

        return merge(left, right);
    }
};
