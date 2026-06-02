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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(head == nullptr || head->next == nullptr)
        {
            return;
        }
        while(fast and fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;

        ListNode* list2=mid->next;
        mid->next=nullptr;
        ListNode* prev=nullptr;
        ListNode* curr=list2;
        ListNode* next=curr->next;
        while(curr!=nullptr)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        list2=prev;

        ListNode* list1=head;
        ListNode* tail=list1;
        list1=list1->next;
        int chance=0;
        while(list1 and list2)
        {
            if(chance==0)
            {
                tail->next=list2;
                tail=tail->next;
                list2=list2->next;
                chance=1;
            }
            else if(chance==1)
            {
                tail->next=list1;
                tail=tail->next;
                list1=list1->next;
                chance=0;
            }
        }
        if(list2==nullptr)
        {
            while(list1!=nullptr)
            {
                tail->next=list1;
                tail=tail->next;
                list1=list1->next;
            }
        }
        else if(list1==nullptr)
        {
            while(list2!=nullptr)
            {
                tail->next=list2;
                tail=tail->next;
                list2=list2->next;
            }
        }
    }
};
