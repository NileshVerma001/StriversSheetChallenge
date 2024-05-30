class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)
            return list2;
        if(list2 == nullptr)
            return list1;

        ListNode *newList, *temp;
        
        if(list1->val <= list2->val)
        {
            newList = list1;
            list1 = list1->next;
        }
        else
        {
            newList = list2;
            list2 = list2->next;
        }
        temp = newList;
        
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                newList->next = list1;
                list1 = list1->next;
            }
            else
            {
                newList->next = list2;
                list2 = list2->next;
            }
            newList = newList->next;
        }
        
        if(list1 != nullptr)
            newList->next = list1;
        else if(list2 != nullptr)
            newList->next = list2;

        return temp;   
    }
};
