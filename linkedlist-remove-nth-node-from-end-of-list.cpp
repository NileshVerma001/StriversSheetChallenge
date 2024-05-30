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
        ListNode *curr=head;
        int x=0;
        while (curr!=nullptr)
        {
            x++;
            curr=curr->next;

        }

        if(x==n)
        return head->next;

        if(n>x)
        return head;
       
            ListNode *temp=head;
            ListNode *prev=nullptr;
            for(int i=0;i<x-n;i++)
            {   
                prev=temp;

                temp=temp->next;


                
            }
            prev->next=temp->next;
            return head;


       
        
    }
};
