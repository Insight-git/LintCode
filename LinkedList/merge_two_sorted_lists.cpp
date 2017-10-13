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
     * @param ListNode l1 is the head of the linked list
     * @param ListNode l2 is the head of the linked list
     * @return: ListNode head of linked list
     */
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    	ListNode *head_l1 = new ListNode(0);
    	ListNode *head_l2 = l2;
        ListNode *node = NULL, *temp = NULL;
        head_l1 ->next = l1;
        while(head_l2)
        {
        	node = head_l1;
        	while(node->next&&node->next->val<head_l2->val)//找到已排序链表中第一个比待排序结点大的结点的前一个结点，然后插在它后面
        	{
        		node = node->next;
        	}
        	temp = head_l2->next;
        	head_l2->next = node->next;
        	node->next = head_l2;
        	head_l2 = temp;
        }
        return head_l1->next;
    }
};