/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr=head;
        ListNode* tail;
        int length=1;
        while(curr->next!=nullptr)
        {
            curr=curr->next;
            length++;
        }
        tail=curr;
        int node=length-n+1;
        curr=head;
        ListNode* prev=nullptr;
        ListNode* temp;
        ListNode* next;
        if(node==1)
        {
            head=head->next;
            return head;
        }
        while(node>1)
        {
            prev=curr;
            curr=curr->next;
            node--;
        }
        prev->next=curr->next;
        return head;
    }
};
