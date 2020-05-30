#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/*
Success
Details
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Convert Binary Number in a Linked List to Integer.
*/
int getDecimalValue(ListNode* head) {
    int count = {};
    string s = {};
    
    while(head) {
      s += to_string(head->val);
      head = head->next;
      count++;
    }
    
    
    int bin = {};
    count--;
    for(auto e : s) {
        // if char is equal to 1
        if(e - '0' == 1)
            bin += pow(2,count);
        count--;
    }
        
    return bin;
}

int main(int argc, char** argv) {
	ListNode *l1 = new ListNode(1);
	ListNode *l2 = new ListNode(0);
	ListNode *l3 = new ListNode(1);
	l1->next = l2;
	l2->next = l3;

	cout << getDecimalValue(l1) << endl;
}