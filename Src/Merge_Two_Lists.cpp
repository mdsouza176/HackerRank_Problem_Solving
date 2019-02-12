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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode*top;
		ListNode* head = nullptr;
		if (l1 == nullptr && l2 == nullptr) {
			return head;
		}
		if (l1 != nullptr || l2 != nullptr) {
			if (l1 == nullptr&& l2 == nullptr) {
				return head;
			}
			else if (l1 == nullptr && l2 != nullptr) {
				head = l2;
				l2 = l2->next;
			}
			else if (l1 != nullptr && l2 == nullptr) {
				head = l1;
				l1 = l1->next;
			}
			else {
				if (l1->val < l2->val) {
					head = l1;
					l1 = l1->next;
				}
				else {
					head = l2;
					l2 = l2->next;
				}
			}
		}
		top = head;
		while (l1 != nullptr || l2 != nullptr) {
			if (l1 != nullptr && l2 != nullptr) {
				if (l1->val < l2->val) {
					head->next = l1;
					head = head->next;
					l1 = l1->next;
				}
				else {
					head->next = l2;
					head = head->next;
					l2 = l2->next;
				}
			}
			else if (l1 != nullptr && l2 == nullptr) {
				while (l1 != nullptr) {
					head->next = l1;
					head = head->next;
					l1 = l1->next;
				}
			}
			else {
				while (l2 != nullptr) {
					head->next = l2;
					head = head->next;
					l2 = l2->next;
				}
			}
		}
		return top;
	}
};