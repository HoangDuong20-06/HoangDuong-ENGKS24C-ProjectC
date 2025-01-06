#include"function.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void menuStore(){
	system("cls");
	printf("==========STORE MANAGEMENT=========\n");
	printf("1. Category management\n");
	printf("2. Product management\n");
	printf("3. Exit\n");
	printf("===================================\n");
}
void menuCategory(){
	struct Category user[100];
	int choice2;
	int n=0;
	do{
		system("cls");
		printf("        *****STORE MANAGEMENT*****\n");
	    printf("==========CATEGORY MANAGEMENT=========\n");
	    printf("1. Show Category\n");
	    printf("2. Add Category\n");
	    printf("3. Fix Category\n");
	    printf("4. Delete Category\n");
	    printf("5. Arrange Category\n");
	    printf("6. Find Category\n");
	    printf("7. Exit\n");
	    printf("==========================================\n");
	    printf("Your choice:");
	    scanf("%d",&choice2);
	    getchar();
	    switch(choice2){
		    case 1:
		    	system("cls");
		    	readFileCategory(&n,user);
		    	printCategory(&n,user);
		    	printf("Enter any key to back to menu:");
		    	getchar();
			    break;
		    case 2:
		    	system("cls");
		    	printf("Enter number of category want to add:");
		    	scanf("%d",&n);
		    	getchar();
		    	moreCategory(&n,user);
		    	saveFileCategory(&n,user);
		    	printCategory(&n,user);
		    	printf("Enter any key to back to menu:");
		    	getchar();
			    break;
		    case 3:
		    	system("cls");
		    	fixCategory(&n,user);
		    	printCategory(&n,user);
		    	checkCategory(&n,user);
		    	printCategory(&n,user);
		    	printf("Enter any key to back to menu:");
		    	getchar();
			    break;
		    case 4:
		    	system("cls");
		    	deleteCategory(&n,user);
		    	printCategory(&n,user);
		    	printf("Enter any key to back to menu:");
		    	getchar();
			    break;
		    case 5:
		    	system("cls");
		    	arrangeCategory(&n,user);
			    break;
		    case 6:
		    	system("cls");
		    	findCategory(&n,user);
		    	printf("Enter any key to back to menu:");
		    	getchar();
			    break;
		    case 7:
			    break;
	    }
	}while(choice2!=7);
}
void printCategory(int *n, struct Category *user){
	int i;
	printf("==============================\n");
	printf("| %-10s | %-10s |\n","ID","NAME CATEGORY");
	for(i=0;i<*n;i++){
		printf("| %-10s | %-10s    |\n",user[i].categoryId,user[i].categoryName);
	}
	printf("==============================\n");
}
void moreCategory(int *n, struct Category *user){
	int i;
	for(i=0;i<*n;i++){
		printf("Enter ID:");
	    fgets(user[i].categoryId,100,stdin);
	    user[i].categoryId[strcspn(user[i].categoryId,"\n")]='\0';
	    printf("Enter Category:");
	    fgets(user[i].categoryName,100,stdin);
	    user[i].categoryName[strcspn(user[i].categoryName,"\n")]='\0';
	}
	checkCategory(n,user);
}
void fixCategory(int *n, struct Category *user){
	char addIndex[10];
	int findIndex=-1;
	printf("Enter ID category to fix:");
	fgets(addIndex,10,stdin);
	addIndex[strcspn(addIndex,"\n")]='\0';
	int i;
	for(i=0;i<*n;i++){
		if(strcmp(addIndex,user[i].categoryId)==0){
			findIndex=i;
		}
	}
	if(findIndex==-1){
		printf("Not found id\n");
	}else{
		printf("Enter Category:");
	    fgets(user[findIndex].categoryName,100,stdin);
	    user[findIndex].categoryName[strcspn(user[findIndex].categoryName,"\n")]='\0';
	}
}
void deleteCategory(int *n, struct Category *user){
	int choice3;
	char deleIndex[10];
	int foundIndex=-1;
	printf("Enter ID category to delete:");
    fgets(deleIndex,10,stdin);
	deleIndex[strcspn(deleIndex,"\n")]='\0';
	int i;
	for(i=0;i<*n;i++){
		if(strcmp(deleIndex,user[i].categoryId)==0){
			foundIndex=i;
		}
	}
	if(foundIndex==-1){
		printf("Not found id\n");
	}else {
		printf("Do you want to delete:");
		printf("1.yes | 2.No\n");
		scanf("%d",&choice3);
		switch(choice3){
			case 1:
				for(i=foundIndex;i<*n;i++){
					user[i]=user[i+1];
				}
				(*n)--;
				printf("Delete complete\n");
				break;
			case 2:
				break;
		}
		}
}
void arrangeCategory(int *n, struct Category *user){
	struct Category up;
	int choice4;
	int i,j;
	do{
		system("cls");
		printf("Choose arrangement\n");
	    printf("1.A-Z\n");
	    printf("2.Z-A\n");
	    printf("3.Exit\n");
	    printf("Your choice:");
	    scanf("%d",&choice4);
	    switch(choice4){
		    case 1:
			    system("cls");
	            for(i=0;i<(*n);i++){
		            for(j=0;j<(*n)-i-1;j++){
			            if(strcmp(user[j].categoryName,user[j+1].categoryName)>0){
				            up=user[j];
				            user[j]=user[j+1];
				            user[j+1]=up;
			            }
		            }
	            }
	            printf("==============================\n");
	            printf("| %-10s | %-10s |\n","ID","NAME CATEGORY");
	            for(i=0;i<*n;i++){
		        printf("| %-10s | %-10s |\n",user[i].categoryId,user[i].categoryName);
	            }
	            printf("==============================\n");
	            printf("Enter any key to back to menu:");
		    	getchar();
		    	getchar();
			    break;
		    case 2:
		    	system("cls");
		    	for(i=0;i<(*n);i++){
		    		for(j=0;j<(*n)-i-1;j++){
		    			if(strcmp(user[j].categoryName,user[j+1].categoryName)<0){
		    				up=user[j];
		    				user[j]=user[j+1];
		    				user[j+1]=up;
						}
					}
				}
				printf("==============================\n");
	            printf("| %-10s | %-10s |\n","ID","NAME CATEGORY");
	            for(i=0;i<*n;i++){
		        printf("| %-10s | %-10s |\n",user[i].categoryId,user[i].categoryName);
	            }
	            printf("==============================\n");
	            printf("Enter any key to back to menu:");
		    	getchar();
		    	getchar();
			    break;
		    case 3:
			    break;
			    default:
				    printf("Invalid choice");
	    }
    }while(choice4!=3);
}
void findCategory(int *n, struct Category *user){
	char searchName[100];
	int arr[100];
	int index=0;
	int flag=-1;
	printf ("Enter category want to find:"); 
	fgets(searchName,100,stdin);
	searchName[strcspn(searchName,"\n")]='\0';
	int i;
	for(i=0;i<*n;i++){
		if(strstr(user[i].categoryName,searchName) !=NULL){
			arr[index]=i;
			index++;
			flag=i; 
		} 
	}
	if(flag==-1){
		printf("Not found category!!\n"); 
	} else{
		printf("============================================\n"); 
        printf("==============================\n");
	    printf("| %-10s | %-10s |\n","ID","NAME CATEGORY");
        for(i=0;i<index;i++){
        	printf("| %-10s | %-10s |\n",user[i].categoryId,user[i].categoryName);
	    }
	    printf("==============================\n");
    }
}
void checkCategory(int *n, struct Category *user){
	int i,j;
	int check=-1;
	for(i=0;i<*n;i++){
		if(strlen(user[i].categoryId)==strlen(user[i].categoryName)){
			printf("Invalid length\n");
			printf("Enter category of %s again:\n",user[i].categoryName);
			fgets(user[i].categoryId,100,stdin);
			user[i].categoryId[strcspn(user[i].categoryId,"\n")]='\0';
			check=i;
		}
	}
	for(i=0;i<(*n)-1;i++){
		for(j=0;j<(*n);j++){
			if(i!=j&&strcmp(user[i].categoryId,user[j].categoryId)==0){
				printf("The ID cannot be the same\n");
				printf("Enter ID category of %s again:\n",user[i].categoryName);
			    fgets(user[i].categoryId,100,stdin);
			    user[i].categoryId[strcspn(user[i].categoryId,"\n")]='\0';
			    j--;
			    check=i;
			    break;
			}
		}
	}
	for(i=0;i<(*n)-1;i++){
		for(j=0;j<*n;j++){
			if(i!=j&& strcmp(user[i].categoryName,user[j].categoryName)==0){
				printf("The Category Name cannot be the same\n");
				printf("Enter category name of %s again:\n",user[i].categoryId);
				fgets(user[i].categoryName,100,stdin);
				user[i].categoryName[strcspn(user[i].categoryName,"\n")]='\0';
				j--;
				check=i;
				break;
			}
		}
	}
	for(i=0;i<*n;i++){
		if(strlen(user[i].categoryId)==0){
			printf("ID category cannot be left blank\n");
			printf("Enter ID category of %s again:\n",user[i].categoryName);
			fgets(user[i].categoryId,100,stdin);
			user[i].categoryId[strcspn(user[i].categoryId,"\n")]='\0';
			check=i;
		}
		if(strlen(user[i].categoryName)==0){
			printf("NAME CATEGORY category cannot be left blank\n");
			printf("Enter name category of %s again:\n",user[i].categoryName);
			fgets(user[i].categoryName,100,stdin);
			user[i].categoryName[strcspn(user[i].categoryName,"\n")]='\0';
			check=i;
		}
	}
	if(check==-1){
		printf("Data correct\n");
	}
}
void saveFileCategory(int *n, struct Category *user){
	FILE *ptr=fopen("storeData.dat","wb");
	if(ptr==NULL){
		printf("Can't open file\n'");
	}
	fwrite(user,sizeof(struct Category),*n,ptr);
	printf("Save file success\n");
	fclose(ptr);
}
void readFileCategory(int *n, struct Category *user){
	FILE *ptr=fopen("storeData.dat","rb");
	if(ptr==NULL){
		printf("Can't open file'");
	}
	while(fread(&user[*n],sizeof(struct Category),1,ptr)==1){
		(*n)++;
	}
	printf("Read data success\n");
	fclose(ptr);
}
void menuProduct(){
	struct Product customer[100];
	int choice5;
	int length=0;
	do{
		system("cls");
		printf("        *****STORE MANAGEMENT*****\n");
	    printf("==========PRODUCT MANAGEMENT=========\n");
	    printf("1. Show Product\n");
	    printf("2. Add Product\n");
	    printf("3. Fix Product\n");
	    printf("4. Delete Product\n");
	    printf("5. Arrange Product\n");
	    printf("6. Exit\n");
	    printf("==========================================\n");
	    printf("Your choice:");
	    scanf("%d",&choice5);
	    getchar();
	    switch(choice5){
	    	case 1:
	    		system("cls");
	    		readFileProduct(&length,customer);
	    		printProduct(&length,customer);
	    		printf("Enter any key to back to menu:");
		    	getchar();
	    		break;
	    	case 2:
	    		system("cls");
	    		printf("Enter number of category want to add:");
		    	scanf("%d",&length);
		    	getchar();
	    		scanProduct(&length,customer);
	    		saveFileProduct(&length,customer);
	    		printProduct(&length,customer);
	    		printf("Enter any key to back to menu:");
		    	getchar();
	    		break;
	    	case 3:
	    		system("cls");
	    		fixProduct(&length,customer);
	    		auditProduct(&length,customer);
	    		printProduct(&length,customer);
	    		printf("Enter any key to back to menu:");
		    	getchar();
	    		break;
	    	case 4:
	    		system("cls");
	    		deleteProduct(&length,customer);
	    		printProduct(&length,customer);
	    		printf("Enter any key to back to menu:");
		    	getchar();
	    		break;
	    	case 5:
	    		system("cls");
	    		arrangeProduct(&length,customer);
	    		break;
	    	case 6:
	    		break;
	    		default:
	    			printf("Invalid selection\n");
		}
    }while(choice5!=6);
}
void printProduct(int *length, struct Product *customer){
	int i;
	printf("====================================================================\n");
	printf("| %-10s | %-10s | %-10s | %-10s | %-10s|\n","ID CATEGOTY","ID PRODUCT","NAME PRODUCT","QUANTITY","PRICE");
	for(i=0;i<*length;i++){
		printf("| %-10s  | %-10s |  %-10s  |  %-10d| %-10d|\n",customer[i].categoryId,customer[i].productId,customer[i].productName,customer[i].quantity,customer[i].price);
	}
	printf("====================================================================\n");
}
void scanProduct(int *length, struct Product *customer){
	int i;
	for(i=0;i<*length;i++){
		printf("Enter ID CATEGORY:");
	    fgets(customer[i].categoryId,100,stdin);
	    customer[i].categoryId[strcspn(customer[i].categoryId,"\n")]='\0';
	    printf("Enter ID PRODUCT:");
	    fgets(customer[i].productId,100,stdin);
	    customer[i].productId[strcspn(customer[i].productId,"\n")]='\0';
	    printf("Enter NAME PRODUCT:");
	    fgets(customer[i].productName,100,stdin);
	    customer[i].productName[strcspn(customer[i].productName,"\n")]='\0';
	    printf("Enter QUANTITY:");
	    scanf("%d",&customer[i].quantity);
	    printf("Enter PRICE:");
	    scanf("%d",&customer[i].price);
	    getchar();
    }
    auditProduct(length,customer);
}
void fixProduct(int *length, struct Product *customer){
	char moreIndex[10];
	int foundIndex=-1;
	printf("Enter ID product to fix:");
	fgets(moreIndex,10,stdin);
	moreIndex[strcspn(moreIndex,"\n")]='\0';
	int i;
	for(i=0;i<*length;i++){
		if(strcmp(moreIndex,customer[i].productId)==0){
			foundIndex=i;
		}
	}
	if(foundIndex==-1){
		printf("Not found id product\n");
	}else{
		printf("Enter Name Product:");
	    fgets(customer[foundIndex].productName,100,stdin);
	    customer[foundIndex].productName[strcspn(customer[foundIndex].productName,"\n")]='\0';
	    printf("Enter QUANTITY:");
	    scanf("%d",&customer[foundIndex].quantity);
	    printf("Enter PRICE:");
	    scanf("%d",&customer[foundIndex].price);
	    getchar();
	    printf("Fix complete\n");
	}
}
void deleteProduct(int *length, struct Product *customer){
	int choice6;
	char removeIndex[10];
	int index=-1;
	printf("Enter ID category to delete:");
    fgets(removeIndex,10,stdin);
	removeIndex[strcspn(removeIndex,"\n")]='\0';
	int i;
	for(i=0;i<*length;i++){
		if(strcmp(removeIndex,customer[i].productId)==0){
			index=i;
		}
	}
	if(index==-1){
		printf("Not found id\n");
	}else {
		printf("Do you want to delete:");
		printf("1.yes | 2.No\n");
		scanf("%d",&choice6);
		switch(choice6){
			case 1:
				for(i=index;i<*length;i++){
					customer[i]=customer[i+1];
				}
				(*length)--;
				printf("Delete complete\n");
				break;
			case 2:
				break;
		}
		}
}
void arrangeProduct(int *length, struct Product *customer){
	struct Product arrange;
	int choice7;
	int i,j;
	do{
		system("cls");
		printf("Choose arrangement\n");
	    printf("1.High-Low\n");
	    printf("2.Low-High\n");
	    printf("3.Exit\n");
	    printf("Your choice:");
	    scanf("%d",&choice7);
	    switch(choice7){
		    case 1:
			    system("cls");
	            for(i=0;i<(*length);i++){
		            for(j=0;j<(*length)-i-1;j++){
			            if((customer[j].price,customer[j+1].price)<0){
				            arrange=customer[j];
				            customer[j]=customer[j+1];
				            customer[j+1]=arrange;
			            }
		            }
	            }
	            printf("====================================================================\n");
	            printf("| %-10s | %-10s | %-10s | %-10s | %-10s|\n","ID CATEGOTY","ID PRODUCT","NAME PRODUCT","QUANTITY","PRICE");
	            for(i=0;i<*length;i++){
		            printf("| %-10s  | %-10s |  %-10s  |  %-10d| %-10d|\n",customer[i].categoryId,customer[i].productId,customer[i].productName,customer[i].quantity,customer[i].price);
	            }
	            printf("====================================================================\n");
	            printf("Enter any key to back to menu:");
		    	getchar();
		    	getchar();
			    break;
		    case 2:
		    	system("cls");
		    	for(i=0;i<(*length);i++){
		    		for(j=0;j<(*length)-i-1;j++){
		    			if((customer[j].price,customer[j+1].price)>0){
		    				arrange=customer[j];
		    				customer[j]=customer[j+1];
		    				customer[j+1]=arrange;
						}
					}
				}
				printf("====================================================================\n");
	            printf("| %-10s | %-10s | %-10s | %-10s | %-10s|\n","ID CATEGOTY","ID PRODUCT","NAME PRODUCT","QUANTITY","PRICE");
	            for(i=0;i<*length;i++){
		            printf("| %-10s  | %-10s |  %-10s  |  %-10d| %-10d|\n",customer[i].categoryId,customer[i].productId,customer[i].productName,customer[i].quantity,customer[i].price);
	            }
	            printf("====================================================================\n");
	            printf("Enter any key to back to menu:");
		    	getchar();
		    	getchar();
			    break;
		    case 3:
			    break;
			    default:
				    printf("Invalid choice");
	    }
    }while(choice7!=3);
}
void auditProduct(int *length, struct Product *customer){
	int i,x;
	int audit=-1;
	for(i=0;i<*length;i++){
		if(strlen(customer[i].productId)==strlen(customer[i].productName)){
			printf("Invalid length\n");
			printf("Enter category of %s again:\n",customer[i].productName);
			fgets(customer[i].productId,100,stdin);
			customer[i].productId[strcspn(customer[i].productId,"\n")]='\0';
			audit=i;
		}
	}
	for(i=0;i<(*length)-1;i++){
		for(x=0;x<(*length);x++){
			if(i!=x&&strcmp(customer[i].categoryId,customer[x].categoryId)==0){
				printf("The ID cannot be the same\n");
				printf("Enter ID category of %s again:\n",customer[i].productName);
			    fgets(customer[i].categoryId,100,stdin);
			    customer[i].categoryId[strcspn(customer[i].categoryId,"\n")]='\0';
			    x--;
			    audit=i;
			    break;
			}
		}
	}
	for(i=0;i<(*length)-1;i++){
		for(x=0;x<*length;x++){
			if(i!=x&& strcmp(customer[i].productName,customer[x].productName)==0){
				printf("The Category Name cannot be the same\n");
				printf("Enter category name of %s again:\n",customer[x].categoryId);
				fgets(customer[i].productName,100,stdin);
				customer[i].productName[strcspn(customer[i].productName,"\n")]='\0';
				x--;
				audit=i;
				break;
			}
		}
	}
	for(i=0;i<(*length)-1;i++){
		for(x=0;x<*length;x++){
			if(i!=x&& strcmp(customer[i].productId,customer[x].productId)==0){
				printf("The Product ID cannot be the same\n");
				printf("Enter Product ID of %s again:\n",customer[x].productName);
				fgets(customer[i].productId,100,stdin);
				customer[i].productId[strcspn(customer[i].productId,"\n")]='\0';
				x--;
				audit=i;
				break;
			}
		}
	}
	for(i=0;i<*length;i++){
		if(strlen(customer[i].productId)==0){
			printf("ID category cannot be left blank\n");
			printf("Enter ID category of %s again:\n",customer[i].productName);
			fgets(customer[i].categoryId,100,stdin);
			customer[i].categoryId[strcspn(customer[i].categoryId,"\n")]='\0';
			audit=i;
		}
		if(strlen(customer[i].productName)==0){
			printf("NAME CATEGORY category cannot be left blank\n");
			printf("Enter name category of %s again:\n",customer[i].productId);
			fgets(customer[i].productName,100,stdin);
			customer[i].productName[strcspn(customer[i].productName,"\n")]='\0';
			audit=i;
		}
	}
	if(audit==-1){
		printf("Data correct\n");
	}
}
void saveFileProduct(int *length, struct Product *customer){
	FILE *ptr=fopen("productData.dat","wb");
	if(ptr==NULL){
		printf("Can't open file\n'");
	}
	fwrite(customer,sizeof(struct Product),*length,ptr);
	printf("Save file success\n");
	fclose(ptr);
}
void readFileProduct(int *length, struct Product *customer){
	FILE *ptr=fopen("productData.dat","rb");
	if(ptr==NULL){
		printf("Can't open file'");
	}
	while(fread(&customer[*length],sizeof(struct Product),1,ptr)==1){
		(*length)++;
	}
	printf("Read data success\n");
	fclose(ptr);
}
void productFiltering(int *n, struct Category *user,int *length, struct Product *customer){
//	int choice8;
//	do{
//		system("cls");
//		printf("1.Filter by category\n");
//		printf("2.Filter by price\n");
//		printf("3.Exit\n");
//		printf("Your choice:");
//		scanf("%d",&choice8);
//		switch(choice8){
//			case 1:
//		
//		}
//	}while(choice8!=3);
}
