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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next){
            return head;
        }

        ListNode* curr=head;
        int n=0;
        while(curr->next){
            n++;
            curr=curr->next;
        }
        n++;
        if(k%n==0){
            return head;
        }
        k=k%n;
        ListNode *last=curr;
        curr=head;
        vector<ListNode*> rotate;
        for(int i=1;i<n-k;i++){
            curr=curr->next;
        }
        ListNode * first=curr->next;
        curr->next=nullptr;
        last->next=head;
        return first;
        
        


        
    }
};
