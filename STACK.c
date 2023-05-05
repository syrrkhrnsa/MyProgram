#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char infotype;
typedef struct huruf *address;
typedef struct huruf {
	infotype info;
	address next;
} hrf;

address Top;
address X,Y;

void Push(char huruf){
	X = (address) malloc (sizeof (hrf));
	if(X == NULL){
		printf("alokasi gagal");
	}else{
	X->info = huruf;
	X->next = NULL;
		if(Top == NULL){
			Top = X;
		}
		else{
			X->next = Top;
			Top = X;
		}
	}

}

int Pop(){
		if(Top != NULL){
			Y = Top;
			Top = Top->next;
			Y->next = NULL;
			free(Y);
		}else{
			free(Top);
		}
		return 0;
	}
	
void Display(){
	if (Top == NULL){
		printf("List Kosong...");
		return;
	}
	Y = Top;
	while (Y->next != NULL){
		printf("%c ",Y->info);
		Y = Y->next;
	}
	printf("%c ",Y->info);
}

int main(){
	Push('A');
	Push('B');
	Push('C');
	Push('D');
	Push('E');
	Pop();
	Display();
	return 0;
}
