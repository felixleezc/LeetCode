/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode* pTrailor = head;
    struct ListNode* pTailor = NULL;
    struct ListNode* pLastTailor = NULL;
    struct ListNode* pTmp = NULL;
    if(head&&head->next)
    {
        pTailor = head->next;
    }
    else
    {
        return head;
    }
    head = head->next;
    pTmp = pTailor->next;
    while(pTailor)
    {
        pTrailor->next = pTmp;
        pTailor->next = pTrailor;
        if(pLastTailor)
        {
            pLastTailor->next = pTailor;
        }
        pLastTailor = pTrailor;
        pTrailor = pTmp;
        if(pTrailor)
        {
            if(pTrailor->next)
            {
                pTailor = pTrailor->next;
            }
            else
            {
                pTailor = NULL;
            }
            if(pTailor)
            {
                pTmp = pTailor->next;
            }
            else
            {
                pTmp = NULL;
            }
        }
        else
        {
            pTailor = NULL;
        }
    }
    return head;
}
