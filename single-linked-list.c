#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct employee {
    char name[32];
    unsigned char age;
} Employee;

typedef struct node {
	void* data;
	struct node *next;
} Node;

typedef struct linkedLidt {
    Node* head;
    Node* tail;
    Node* current;
} LinkedList;

typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);

int compareEmployee(Employee* e1, Employee* e2) {
    return strcmp(e1->name, e2->name);
}
void displayEmployee(Employee* employee) {
    printf("%s\t%d\n", employee->name, employee->age);
}

void list_init(LinkedList*);
void addHead(LinkedList*, void*);
void addTail(LinkedList*, void*);
void insert(LinkedList*, void*);
void delete(LinkedList*, Node*);
Node* getNode(LinkedList*, COMPARE, void*);
void  list_print(LinkedList*, DISPLAY);
int   list_len(LinkedList*);

int main() {
    LinkedList* list;
    list_init(list);

    Employee* samuel = (Employee*)malloc(sizeof(Employee));
    strcpy(samuel->name, "Samuel");
    samuel->age = 32;
    Employee* sally = (Employee*)malloc(sizeof(Employee));
    strcpy(sally->name, "Sally");
    sally->age = 28;
    Employee* susan = (Employee*)malloc(sizeof(Employee));
    strcpy(susan->name, "Susan");
    susan->age = 45;
    
    addHead(list, samuel);
    addHead(list, sally);
    addHead(list, susan);
    printf("so nhan vien: %d", list_len(list));
    list_print(list, (DISPLAY)displayEmployee);

    Node* node = getNode(list, (int (*)(void*, void*))compareEmployee, sally);
    delete(list, node);
    list_print(list, (DISPLAY)displayEmployee);
	return 0;
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
list_init(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
addHead(LinkedList* list, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;

    if (list->head = NULL) {
        list->head = node;
        list->tail = node;
        node->next = NULL;
    }
    else {
        node->next = list->head;
        list->head = node;
    }
    
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
addTail(LinkedList* list, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;

    if (list->head = NULL) {
        list->head = node;
        list->head = node;
    }
    else {
        list->tail->next = node;
        list->tail = node;
    }   
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
delete(LinkedList* list, Node* node) {
    if (node == list->head)
    {
        if (list->head->next == NULL) {
            list->head = list->tail = NULL;
        }
        else {
            list->head = list->head->next;
        }
    }
    else {
        Node* tmp = list->head;
        while (tmp != NULL && tmp->next != node) {
            tmp = tmp->next;
        }
        if (tmp != NULL) {
            tmp->next = node->next;
        }
    }
    free(node);
}

/*
 *\brief
 *\param[in]
 *\retval
 */
Node* 
getNode(LinkedList* list, COMPARE compare, void* data) {
    Node* node = list->head;
    while (node != NULL) {
        if (compare(node->data, data) == 0) {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
list_print(LinkedList* list, DISPLAY display) {
    printf("\nLinked List\n");
    Node* current = list->head;
    while (current != NULL) {
        display(current->data);
        current = current->next;
    }
}

/*
 *\brief			
 *\param[in]			
 *\return			
 */
int 
list_len(LinkedList* list) {
   int len = 0;
   Node *current;
	
   for(current = list->head; current != NULL; current = current->next) {
      len++;
   }
	
   return len;
}
