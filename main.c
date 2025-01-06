#include <stdio.h>
#include <stdlib.h>
#include"function.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	struct Category user[100];
	struct Product customer[100];
	int choice;
	do{
		menuStore();
		printf("Your choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				system("cls");
				menuCategory();
				break;
			case 2:
				system("cls");
				menuProduct();
				break;
			case 3:
				printf("\t=====Thank You=====\n");
				printf("\t=====Good Bye=====");
				break;
				default:
					printf("Invalid Selection\n");
	    }
	}while(choice!=3);
	return 0;
}
