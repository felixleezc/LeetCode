/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseKGroup(struct ListNode* head, int k){
    struct ListNode* pRetInit = NULL;
    struct ListNode* pHead = NULL;
    struct ListNode* pTail = NULL;
    struct ListNode* pRetTail = NULL;
    struct ListNode* pTmp = NULL;
    struct ListNode* pTmp2 = NULL;
    struct ListNode* pTmp3 = NULL;
    pTail = head;
    pRetTail = head;
    int i = 0;
    int j = 0;
    int iCycle = 0;
    if(1 == k)
    {
        return head;
    }
    while(NULL != pTail)
    {
        pHead = pTail;
        i=0;
        j=0;
        while(i < k - 1 && NULL != pTail->next)
        {
            pTail = pTail->next;
            i++;
        } 
        if(i == k - 1)
        {
            //此时未到链表结尾，对k个节点反转
            pTmp = pHead;
            pTmp2 = pTmp->next;
            pTmp3 = pTmp2->next;
            pTmp->next = NULL; //没有这句就死循环了
            pTmp2->next = pTmp;

            while(pTmp2 != pTail)
            {
                pTmp = pTmp2;
                pTmp2 = pTmp3;
                pTmp3 = pTmp2->next;
                pTmp2->next = pTmp;
            }
            if(0 == iCycle)
            {
                pRetInit = pTail;
            }
            else
            {
                pRetTail->next = pTail;
            }
            pRetTail = pHead;
            pTail = pTmp3;
            iCycle++;
        }
        else if(i < k - 1)
        {
            //此时已到链表结尾，不对最后的节点反转
            if(0 == iCycle)
            {
                pRetInit = pHead;
            }
            else
            {
                pRetTail->next = pHead;
            }
            iCycle++;
            pTail = NULL;
        }
    }
    return pRetInit;
}
