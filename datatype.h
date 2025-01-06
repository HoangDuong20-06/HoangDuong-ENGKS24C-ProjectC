#include<stdbool.h>
struct Category {
	char categoryId[100];
	char categoryName[100];
};
struct Product {
	char productId[100];
	char categoryId[100];
	char productName[100];
	int quantity;
	int price;
};
