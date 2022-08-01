#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	void* data;
	struct node* next;
} Node;

typedef struct queue {
	Node* front;
	Node* rear;
	Node* current;
} Queue;

typedef void(*DISPLAY)(void*);
typedef int(*COMPARE)(void*, void*);

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

void queue_init(Queue*);
void enqueue(Queue*, void*);
void dequeue(Queue*);
Node* getNode(Queue*, COMPARE, void*);
void  queue_print(Queue*, DISPLAY);
int   queue_size(Queue*);

int main() {

	return 0;
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void 
queue_init(Queue* queue) {
	queue->current = NULL;
	queue->front = NULL;
	queue->rear = NULL;
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void
enqueue(Queue* queue, void* data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = NULL;

	if (queue->front = NULL) {
		queue->front = node;
		queue->rear = node;
		
	}
	else {
		queue->rear->next = node;
		queue->rear = node;
	}
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void
dequeue(Queue* queue) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;

	if (queue->front = NULL) {
		queue->front = NULL;
		queue->rear = NULL;
	}
	else {
		Node* tmp = queue->front;
		queue->front = queue->front->next;
	}
	free(tmp);
}

/*
 *\brief
 *\param[in]
 *\retval
 */
Node*
getNode(Queue* queue, COMPARE compare, void* data) {
	for (queue->current = queue->front; queue->current != NULL; queue->current = queue->current->next) {
		if (compare(queue->current->data, data) == 0) {
			return queue->current;
		}
	}
}

/*
 *\brief
 *\param[in]
 *\retval
 */
void
queue_print(Queue* queue, DISPLAY display) {
	printf("\nQueue :\n");
	for (queue->current = queue->front; queue->current != NULL; queue->current = queue->current->next) {
		display(queue->current->data);
	}
}

/*
 *\brief
 *\param[in]
 *\retval
 */
int
queue_size(Queue* queue) {
	int size = 0;
	for (queue->current = queue->front; queue->current != NULL; queue->current = queue->current->next) {
		size++;
	}
	
	return size;
}