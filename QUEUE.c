#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char infotype;
typedef struct huruf *address;
typedef struct huruf {
	infotype info;
	address next;
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
			Rear = X;
		}	
	}
}

void DeQueue(){
		if(Front != Rear){
			Y = Front;
			Front = Front->next;
			Y->next = NULL;
			free(Y);
		}else{
			Rear = NULL;
			free(Front);
		}
	}

void Display(){
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

int main(){
	EnQueue('A');
	EnQueue('B');
	EnQueue('C');
	EnQueue('D');
	EnQueue('E');
	DeQueue();
	Display();
}

