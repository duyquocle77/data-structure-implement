#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	void* data;
	struct node* next;
} Node;

typedef struct stack {
	Node* top;
	Node* current;
} Stack;

typedef void(*COMPARE)(void*, void*);
typedef void(*DISPLAY)(void*);

typedef struct employee {
	char name[32];
	unsigned char age;
} Employee;

int compareEmployee(Employee* e1, Employee* e2) {
	return strcmp(e1->name, e2->name);
}
void displayEmployee(Employee* employee) {
	printf("%s\t%d\n", employee->name, employee->age);
}

void stack_init(Stack*);
void stack_push(Stack*, void*);
void stack_pop(Stack*, void*);
Node* getNode(Stack*, COMPARE, void*);
void stack_print(Stack*);
void stack_size(Stack*);

int main() {

	return 0;
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
stack_init(Stack* stack) {
	stack->top = NULL;
	stack->current = NULL;
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
stack_push(Stack* stack, void* data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->next = NULL;

	if (stack->top = NULL) {
		stack->top = node;
	}
	else {
		stack->top->next = node;
		stack->top = node;
	}
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
stack_pop(Stack* stack, void* data) {

}

/*
 *\brief
 *\param[in]
 *\retval
 */
Node* 
getNode(Stack* stack, COMPARE compare, void* data) {	
	for (stack->current = stack->top; stack->current != NULL; stack->current = stack->current->next) {
		if (compare(stack->current->data, data) == 0) {
			return stack->current;
		}
	}
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void stack_print(Stack* stack, DISPLAY display) {
	for (stack->current = stack->top; stack->current != NULL; stack->current = stack->current->next) {
		display(stack->current->data);
	}
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void stack_size(Stack* stack) {
	int size = 0;
	for (stack->current = stack->top; stack->current != NULL; stack->current = stack->current->next) {
		size++;
	}

	return size;
}