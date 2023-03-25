#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
	int val;
	struct node_s* next;
} Node;


void add_to_list(Node** ptr_list, int val) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("Error: malloc failed in add_to_list.\n");
		exit(1);
	}
	// ͷ�巨
	newNode->val = val;
	newNode->next = *ptr_list;
	*ptr_list = newNode;
}


//int main(void) {
//	Node* list = NULL;
//	add_to_list(&list, 1);
//	add_to_list(&list, 2);
//	add_to_list(&list, 3);
//	add_to_list(&list, 4);
//
//	return 0;
//}
