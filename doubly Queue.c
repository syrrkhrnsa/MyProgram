#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef char infotype;
typedef struct huruf *address;
typedef struct huruf {
	infotype info;
	address next;
	address prev;
} hrf;

address Front;
address Rear;
address X,Y;

void EnQueue(char huruf){
	X = (address) malloc (sizeof (hrf));
	if(X == NULL){
		printf("alokasi gagal");
	}else{
	X->info = huruf;
	X->next = NULL;
	X->prev = NULL;
		if(Front == NULL && Rear == NULL){
			Front = X;
			Rear = X;
		}
		else{
			Y = Front;
			while(Y->next != NULL){
			Y = Y->next;
			}
			Rear->next = X;
			X->prev = Rear;
			Rear = X;
		}	
	}
}

void EnQueueLeft(char huruf){
	X = (address) malloc (sizeof (hrf));
	if(X == NULL){
		printf("alokasi gagal");
	}else{
	X->info = huruf;
	X->next = NULL;
	X->prev = NULL;
		if(Front == NULL && Rear == NULL){
			Front = X;
			Rear = X;
		}
		else{
			X->next = Front;
			Front->prev = X;
			Front = X;
		}
	}

}

void DeQueue(){
		if(Front != Rear){
			Y = Front;
			Front = Front->next;
			Y->next = NULL;
			Front->prev = NULL;
			free(Y);
		}else{
			Rear = NULL;
			free(Front);
		}
	}
	
void DequeueRight(){
		if(Front != Rear){
			Y = Rear;
			Rear = Rear->prev;
			Y->prev = NULL;
			Rear->next =NULL;
			free(Y);
		}else{
			Front = NULL;
			free(Rear);
		}
}
	
	
void DisplayASC(){
	if (Front == NULL){
		printf("List Kosong");
		return;
	}
	Y = Front;
	while (Y->next != NULL){
		printf("%c ",Y->info);
		Y = Y->next;
	}
	printf("%c ",Y->info);
}

void DisplayDESC(){
	if (Front == NULL){
	printf("List Kosong");
	return;
	}
	Y = Rear;
	while (Y->prev != NULL){
		printf("%c ",Y->info);
		Y = Y->prev;
	}
	printf("%c ",Y->info);
}

int main(){
	EnQueue('A');
	EnQueue('B');
	EnQueue('C');
	EnQueue('D');
	EnQueue('E');
	EnQueue('F');
	DeQueue();
	DisplayASC();
	printf("\n");
	DisplayDESC();
}
