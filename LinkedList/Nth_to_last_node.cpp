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

/*solution 1*/
class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode * nthToLast(ListNode * head, int n) {
        unsigned int length = 0, i = 0;
        ListNode *p = head;
        while(p)
        {
        	length++;
        	p = p->next;
        }
        p = head;
        for(i=1;i<=length-n;i++)
        {
        	p = p->next;
        }
        return p;
    }
};

/*solution 2*/
class Solution {
public:
    /*
     * @param head: The first node of linked list.
     * @param n: An integer
     * @return: Nth to last node of a singly linked list. 
     */
    ListNode * nthToLast(ListNode * head, int n) {
        unsigned int i = 0;
        ListNode *p1 = head, *p2 = head;
        for(i=1;i<=n-1;i++)
        {
        	if(!p2)
        		return NULL;
        	p2 = p2->next;
        }
        while(p2)
        {
        	p1 = p1->next;
        	p2 = p2->next;
        }
        return p1;
    }
};