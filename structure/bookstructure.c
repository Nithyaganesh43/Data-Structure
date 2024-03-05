#include<stdio.h>
struct books{
    char title[50];
    char author[20];
    float price;
}book[3];
int main(){
    for (int i = 0; i < 3; i++) {
        printf("\nEnter book %d title: ", i + 1);
        scanf("%s", book[i].title);
        printf("\nEnter book %d author: ", i + 1);
        scanf("%s", book[i].author);  
        printf("\nEnter book %d price: ", i + 1);
        scanf("%f", &book[i].price);  
    }
for (int i = 0; i < 3; i++) {
        printf("\nBOOK %d\n", i + 1);
        printf("Title: %s\n", book[i].title);
        printf("author: %s\n", book[i].author);
        printf("price: %f\n", book[i].price);
    }
    int maxIndex = 0;
    int minIndex = 0;

    // Finding the index of the book with the maximum price
    if (book[1].price > book[maxIndex].price)
        maxIndex = 1;

    if (book[2].price > book[maxIndex].price)
        maxIndex = 2;

    // Finding the index of the book with the minimum price
    if (book[1].price < book[minIndex].price)
        minIndex = 1;

    if (book[2].price < book[minIndex].price)
        minIndex = 2;

    printf("\nMaximum price book\n");
    printf("Title: %s\n", book[maxIndex].title);
    printf("Author: %s\n", book[maxIndex].author);
    printf("Price: %.2f\n", book[maxIndex].price);

    printf("\nMinimum price book\n");
    printf("Title: %s\n", book[minIndex].title);
    printf("Author: %s\n", book[minIndex].author);
    printf("Price: %.2f\n", book[minIndex].price);

}