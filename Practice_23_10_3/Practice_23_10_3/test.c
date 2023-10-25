#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode* next;
};
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
    {
        return head;
    }
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;
    struct ListNode* next = cur->next;
    while (next != NULL)
    {
        prev = cur;
        cur = next;
        next = cur->next;
        cur->next = prev;
    }
    head->next = NULL;
    return cur;
}
int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next->val = 2;
    head->next->next = NULL;
    head = reverseList(head);

    return 0;
}