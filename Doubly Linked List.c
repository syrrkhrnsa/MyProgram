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

address First;
address Last;
address x;
address y;

void InsertFirst(char item){
	x = (address) malloc (sizeof (hrf));
	if(x == NULL){
		printf("alokasi gagal");
	}else{
	x->info = item;
	x->next = NULL;
	x->prev = NULL;
		if(First == NULL && Last == NULL){
			First = x;
			Last = x;
		}
		else{
			x->next = First;
			First->prev = x;
			First = x;
		}
	}

}

void InsertLast(char item){
	x = (address) malloc (sizeof (hrf));
	if(x == NULL){
		printf("alokasi gagal");
	}else{
	x->info = item;
	x->next = NULL;
	x->prev = NULL;
		if(First == NULL && Last == NULL){
			First = x;
			Last = x;
		}
		else{
			y = First;
			while(y->next != NULL){
			y = y->next;
			}
			Last->next = x;
			x->prev = Last;
			Last = x;
		}	
	}
}

void InsertBetween(char item, char key){
	x = (address) malloc (sizeof (hrf));
		x->info = item;
		x->next = NULL;
		x->prev = NULL;
		y = First;
		while (y->info != key){
			y = y->next;
		}
		x->prev = y;
		x->next = y->next;
		y->next = x;
		y = x->next;
		y->prev = x;
	}

void DeleteLast(){
		if(First != Last){
			y = Last;
			Last = Last->prev;
			y->prev = NULL;
			Last->next =NULL;
			free(y);
		}else{
			First = NULL;
			free(Last);
		}
	}

void DeleteFirst(){
		if(First != Last){
			y = First;
			First = First->next;
			y->next = NULL;
			First->prev = NULL;
			free(y);
		}else{
			Last = NULL;
			free(First);
		}
	}
	
void DeleteBetween(char key){
		y = First;
		while(y->info != key){
			y = y->next;
		}
		x = y->next;
		x->prev = y->prev;
		x = y->prev;
		x->next = y->next;
		y->next = NULL;
		y->prev = NULL;
		free(y);
	}
	
void ASC(){
	if (First == NULL){
		printf("List Kosong");
		return;
	}
	y = First;
	while (y->next != NULL){
		printf("%c ",y->info);
		y = y->next;
	}
	printf("%c ",y->info);
}

void DESC(){
	if (First == NULL){
	printf("List Kosong");
	return;
	}
	y = Last;
	while (y->prev != NULL){
		printf("%c ",y->info);
		y = y->prev;
	}
	printf("%c ",y->info);
}


int main() {
	InsertFirst('A');
	InsertLast('B');
	InsertLast('C');
	InsertBetween('S', 'B');
	InsertLast('Z');
	InsertBetween('R', 'A');
	ASC();
	printf("\n");
	DESC();
   return 0;
}
