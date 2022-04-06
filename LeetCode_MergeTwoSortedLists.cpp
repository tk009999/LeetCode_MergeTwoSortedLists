// LeetCode_MergeTwoSortedLists.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	// if list1 happen to be NULL
	// we will simply return list2.
	if (l1 == NULL)
	{
		return l2;
	}

	// if list2 happen to be NULL
	// we will simply return list1.
	if (l2 == NULL)
	{
		return l1;
	}

	// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
	// we wall call recursively l1 -> next and whole l2 list.
	if (l1->val <= l2->val)
	{
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	// we will call recursive l1 whole list and l2 -> next
	else
	{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

int main()
{
	ListNode* l1 = new ListNode(1);
	l1 = new ListNode(2, l1);
	l1 = new ListNode(4, l1);

	ListNode* l2 = new ListNode(1);
	l2 = new ListNode(3, l2);
	l2 = new ListNode(4, l2);

	ListNode* l3 = mergeTwoLists(l1, l2);

	cout << l3->val << "\n";

	do
	{
		l3 = l3->next;

		cout << l3->val << "\n";

	} while (l3->next != NULL);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
