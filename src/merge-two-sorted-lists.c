// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:
// Input: list1 = [], list2 = []
// Output: []
// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

#include <stdio.h>


//Definition for singly-linked list.
struct ListNode {
     int val;
     struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* temp1 = list1;
    struct ListNode* temp2 = list2;
    struct ListNode* newList = NULL;
    struct ListNode* temp3 = NULL;

    if (temp1 == NULL) {
        newList = list2;
        return newList;
    } else if (temp2 == NULL) {
        newList = list1;
        return newList;
    }

    while(temp1 != NULL || temp2 != NULL) {
        if (temp1 == NULL) {
            printf("temp1 is NULL\n");
            temp3->next = temp2;
            temp3 = temp3->next;
            temp2 = temp2->next;
            continue;
        } else if (temp2 == NULL) {
            printf("temp2 is NULL\n");
            temp3->next = temp1;
            temp3 = temp3->next;
            temp1 = temp1->next;
            continue;
        }
        printf("Running the loop\n");
        if(temp1->val > temp2->val) {
            if (newList == NULL) {
                newList = temp2;
                temp3 = newList;
               // printf("Storing temp2 for first time\n");
            } else {
                temp3->next = temp2;
                temp3 = temp3->next;
            }
            temp2 = temp2->next;
        } else {
            if (newList == NULL) {
                newList = temp1;
                temp3 = newList;
                //printf("storing temp1 for the first time\n");
            } else {
                temp3->next = temp1;
                temp3 = temp3->next;
            }
            temp1 = temp1->next;
        }
    }
    temp3->next = NULL;
    return newList;
}
