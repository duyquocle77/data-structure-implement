#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef Node {
   int data;
   int key;
   Node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

void printList();
void insertFirst(int key, int data);
Node* deleteFirst();
bool isEmpty();
int length();
Node* find(int key);
Node* delete(int key);
void sort();
void reverse(Node** head_ref);

void main() {
	
}

void 
printList() {
   Node *ptr = head;
   printf("\n[ ");
	
   while(ptr != NULL) {
      printf("(%d,%d) ",ptr->key,ptr->data);
      ptr = ptr->next;
   }
	
   printf(" ]");
}

void 
insertFirst(int key, int data) {
   Node *link = (Node*) malloc(sizeof(Node));
	
   link->key = key;
   link->data = data;

   link->next = head;

   head = link;
}

Node* 
deleteFirst() {

   Node *tempLink = head;

   head = head->next;

   return tempLink;
}

bool 
isEmpty() {
   return head == NULL;
}

int 
length() {
   int length = 0;
   Node *current;
	
   for(current = head; current != NULL; current = current->next) {
      length++;
   }
	
   return length;
}

Node* 
find(int key) {

   Node* current = head;

   if(head == NULL) {
      return NULL;
   }

   while(current->key != key) {

      if(current->next == NULL) {
         return NULL;
      } else {
         current = current->next;
      }
   }      

   return current;
}

Node* 
delete(int key) {
   Node* current = head;
   Node* previous = NULL;

   if(head == NULL) {
      return NULL;
   }

   while(current->key != key) {

      if(current->next == NULL) {
         return NULL;
      } else {
         previous = current;
         current = current->next;
      }
   }

   if(current == head) {
      head = head->next;
   } else {
      previous->next = current->next;
   }    
	
   return current;
}

void 
sort() {

   int i, j, k, tempKey, tempData;
   Node *current;
   Node *next;
	
   int size = length();
   k = size ;
	
   for ( i = 0 ; i < size - 1 ; i++, k-- ) {
      current = head;
      next = head->next;
		
      for ( j = 1 ; j < k ; j++ ) {   

         if ( current->data > next->data ) {
            tempData = current->data;
            current->data = next->data;
            next->data = tempData;

            tempKey = current->key;
            current->key = next->key;
            next->key = tempKey;
         }
			
         current = current->next;
         next = next->next;
      }
   }   
}

void 
reverse(Node** head_ref) {
   Node* prev   = NULL;
   Node* current = *head_ref;
   Node* next;
	
   while (current != NULL) {
      next  = current->next;
      current->next = prev;   
      prev = current;
      current = next;
   }
	
   *head_ref = prev;
}


