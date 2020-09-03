#include<stdio.h>
#include<stdlib.h>
#include "sll.h"

void insert_at_end(List *list, int data) {
	struct Node* new_node = malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->link = NULL;
	
	if (list->head == NULL) {
		list->head = new_node;
	}
	else {
		struct Node* temp = list->head;
		while (temp->link != NULL) {
			temp = temp->link;
		}
		temp->link = new_node;
	}
	list->number_of_nodes++;
}


void list_delete_front(List* list) {
	if (list->head != NULL) {
		struct Node* del = list->head;
		list->head = del->link;
		list->number_of_nodes --;
	}
}

void list_insert_at (List *list, int data, int position) {

	if (position == 0) {
		struct Node* new_node = malloc(sizeof(struct Node));
    	new_node->data = data;
		new_node->link = list->head;
		list->head = new_node;
		list->number_of_nodes += 1;
	}

	else if (position <= list->number_of_nodes && position > 0) {
		struct Node* new_node = malloc(sizeof(struct Node));
    	new_node->data = data;
		struct Node* temp = list->head;
		for (int index = 0; index <= position; index++) {
			if (index == position - 1) {
				new_node->link = temp->link;
				temp->link = new_node;
				list->number_of_nodes += 1;
			}
			temp = temp->link;
		}	
	}
	
}

void list_reverse(List* list) { 
    struct Node* prev = NULL; 
    struct Node* curr = list->head; 
    struct Node* next = NULL; 

    while (curr != NULL) { 
        next = curr->link; 
        curr->link = prev; 
        prev = curr; 
        curr = next; 
    } 

    list->head = prev; 
}