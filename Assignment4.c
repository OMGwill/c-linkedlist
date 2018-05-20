#include <stdio.h>
#include <stdlib.h>

struct Node{
	char letter;
	int num;
	struct Node* next;
	struct Node* prev;
};


struct Node* head; //gloabl variable pointer to head node

void listAddEnd(char c, int n);
void displayList();
void release(char c);
struct Node* combine(struct Node* A, struct Node* B);
void insert(struct Node* node, char c, int n);

int main(){

	head = (struct Node*) malloc(sizeof(head));
	listAddEnd('*', 1);
	listAddEnd('A', 4);
	listAddEnd('*', 2);
	listAddEnd('B', 1);
	listAddEnd('*', 2);
	listAddEnd('C', 5);
	listAddEnd('*', 1);
	listAddEnd('D', 8);
	listAddEnd('*', 2);
	listAddEnd('E', 2);
	listAddEnd('*', 1);
	listAddEnd('F', 4);
	listAddEnd('*', 2);
	listAddEnd('G', 3);
	listAddEnd('*', 5);


	displayList();

	release('A');
	
	displayList();

	release('C');

	displayList();
	
return 0;
}

void listAddEnd(char c, int n){

	if(head->num == 0)
	{
		head->letter = c;
		head->num = n;
	}else{	


		struct Node* newNode = (struct Node*) malloc(sizeof (newNode));
		struct Node* tmp = head;

		newNode->letter = c;
		newNode->num = n;

	

		while (tmp->next != NULL){
			tmp = tmp->next;
		}
	
		tmp->next = newNode;
		newNode->prev = tmp;
		newNode->next = NULL;
	}
}

void displayList(){
	struct Node* tmp = head;
	
	while(tmp->next != NULL){
		printf("%c%d->",tmp->letter, tmp->num);
		tmp= tmp->next;
	}
	
	printf("%c%d->\n",tmp->letter, tmp->num);
	
}

void release(char c){
	struct Node* tmp = head;

	while(tmp->letter != c){
		tmp = tmp->next;
	}
	//found node to delete


	if(tmp->next->letter == '*')
		tmp = combine(tmp, tmp->next);
	
	if (tmp->prev->letter == '*')
		tmp = combine(tmp->prev, tmp);

	
}

struct Node* combine(struct Node* A, struct Node* B){

	A->num = A->num + B->num;
	A->letter = '*';
	A->next = B->next;
	A->next->prev = A;
	free(B);

	return A;

}

void insert(struct Node* node, char c, int n){
	
	struct Node* tmp = (struct Node*) malloc(sizeof(tmp));
	
	tmp->letter = c;
	tmp->num = n;

	if (node->next != NULL){
		node->next->prev = tmp;
		tmp->next = node->next;
		node->next = tmp;
		tmp->prev = node;	
	} else {
	
		node->next = tmp;
		tmp->prev = node;
		tmp-> next = NULL;	
	}
	
}
