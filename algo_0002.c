/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int iCarryNum = 0;
    struct ListNode* l1end = l1;
    struct ListNode* l2end = l2;
    struct ListNode* resultList = NULL;
    struct ListNode* resultListEnd = NULL;

    //初始化
    resultList = malloc(sizeof(struct ListNode));
    resultListEnd = resultList;
    resultListEnd->next = NULL;
    resultListEnd->val = ((NULL==l1end)?0:l1end->val + (NULL==l2end)?0:l2end->val)%10;
    iCarryNum = ((NULL==l1end?0:l1end->val) + (NULL==l2end?0:l2end->val))/10;
    l1end = (NULL==l1end->next)?NULL:l1end->next;
    l2end = (NULL==l2end->next)?NULL:l2end->next;

    while(NULL != l1end || NULL != l2end||iCarryNum != 0)
    { 
        resultListEnd->next = malloc(sizeof(struct ListNode));
        resultListEnd = resultListEnd->next;
        resultListEnd->next = NULL;
        resultListEnd->val = ((NULL==l1end?0:l1end->val) + (NULL==l2end?0:l2end->val) + iCarryNum)%10;
        iCarryNum = ((NULL==l1end?0:l1end->val) + (NULL==l2end?0:l2end->val) + iCarryNum)/10;
        l1end = (NULL==l1end||NULL==l1end->next)?NULL:l1end->next;
        l2end = (NULL==l2end||NULL==l2end->next)?NULL:l2end->next;
    }
    return resultList;
}
