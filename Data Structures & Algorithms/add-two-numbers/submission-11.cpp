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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy;
        int carry=0;

        while(l1!=nullptr and l2!=nullptr)
        {
            int result=l1->val+l2->val+carry;
            if(result>9)
            {
                carry=(result)/10;
                int seconddigit=(result)%10;
                curr->next=new ListNode(seconddigit);
                curr=curr->next;
            }
            else
            {
                carry=0;
                curr->next=new ListNode(result);
                curr=curr->next;
            }
            l1=l1->next;
            l2=l2->next;
        }
        if(l1==nullptr and l2==nullptr)
        {
            if(carry!=0)
            {
                curr->next=new ListNode(carry);
                curr=curr->next;
                return dummy->next;
            }
        }
        else if(l1==nullptr)
        {
            while(l2!=nullptr)
            {
                int result=l2->val+carry;
                if(result>9)
                {
                    carry=(result)/10;
                    int seconddigit=(result)%10;
                    curr->next=new ListNode(seconddigit);
                    curr=curr->next;
                }
                else
                {
                    carry=0;
                    curr->next=new ListNode(result);
                    curr=curr->next;
                }
                l2=l2->next;
            }
        }
        else if(l2==nullptr)
        {
            while(l1!=nullptr)
            {
                int result=l1->val+carry;
                if(result>9)
                {
                    carry=(result)/10;
                    int seconddigit=(result)%10;
                    curr->next=new ListNode(seconddigit);
                    curr=curr->next;
                }
                else
                {
                    carry=0;
                    curr->next=new ListNode(result);
                    curr=curr->next;
                }
                l1=l1->next;
            }
        }
        if(carry!=0)
        {
            curr->next=new ListNode(carry);
            curr=curr->next;
        }
        return dummy->next;
    }
};
