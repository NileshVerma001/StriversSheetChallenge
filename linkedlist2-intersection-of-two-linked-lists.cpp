/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int n1=0;
        ListNode * temp=headA;
        while(temp){
            n1++;
            temp=temp->next;
        }
        temp=headB;
        int n2=0;
        while(temp){
            n2++;
            temp=temp->next;
        }

        if(n1>n2){
            for(int i=0;i<n1-n2;i++){
                headA=headA->next;

            }
        }
        else if(n1<n2){
            for(int i=0;i<n2-n1;i++){
                headB=headB->next;

            }
        }
        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }

        return headA;
    }
};
