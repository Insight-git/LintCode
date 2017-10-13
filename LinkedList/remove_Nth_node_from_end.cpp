/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @param n: An integer.
     * @return: The head of linked list.
     */
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *new_head = new ListNode(0);
        ListNode *p=NULL;
        unsigned int length = 0, i =0;
        new_head->next = head;
        head = new_head;
        while(head->next)//统计链表长度
        {
            length++;
            head = head->next;
        }
        head = new_head;
        for(i=1;i<=length-n;i++)
        {
            head = head->next;
        }
        p = head->next;
        head->next = p->next;
        delete p;
        return new_head->next;
    }
};


