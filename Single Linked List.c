#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


typedef char infotype;
typedef struct huruf *address;
typedef struct huruf {
	infotype info;
	address next;
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
		if(First == NULL && Last == NULL){
			First = x;
			Last = x;
		}
		else{
			x->next = First;
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
			Last = x;
		}	
	}
}

void InsertBetween(char item, char key){
	x = (address) malloc (sizeof (hrf));
		x->info = item;
		x->next = NULL;
		y = First;
		while (y->info != key){
			y = y->next;
		}
		x->next = y->next;
		y->next = x;
		y = x->next;
	}

void DeleteLast(){
		if(First != Last){
			y = Last;
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
		x->next = y->next;
		y->next = NULL;
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

void swap(address a, address b){
	char temp;
	temp = a->info;
	a->info = b->info;
	b->info = temp;
}

void bubbleSort(){
	y = NULL;
	int swapped;
	if (First == NULL){
        return;
    }
    do {
        swapped = 0;
        x = First;

        // Lakukan bubble sort pada linked list
        while (x->next != y) {
            if (x->info > x->next->info) {
                swap(x, x->next);
                swapped = 1;
            }
            x = x->next;
        }
        y = x;
    } while (swapped);
}

int main() {
	
	First = NULL;
    Last = NULL;
    int i;
    char kata[100];
    printf("Masukkan huruf-huruf yang ingin di short: ");
    scanf("%[^\n]", kata);
    for (i = 0; i < strlen(kata); i++) {
        InsertLast(kata[i]);
    }
    printf("huruf yang sebelum di sort:\n");
    ASC();
    printf("\n");
    printf("huruf setelah di sort\n");
    bubbleSort();
    ASC();
//	InsertFirst('A');
//	InsertLast('B');
//	InsertLast('C');
//	InsertBetween('S', 'B');
//	InsertLast('Z');
//	InsertBetween('R', 'A');
//	ASC();
   return 0;
}
