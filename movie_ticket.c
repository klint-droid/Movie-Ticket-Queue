#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer{
    char name[50];
    int ticketCount;
    struct Customer* next;
}Customer;

Customer *front = NULL;
Customer *rear = NULL;

void addCustomer(char *name, int ticketCount){
    Customer *newCustomer = (Customer*)malloc(sizeof(Customer));
    strcpy(newCustomer->name, name);
    newCustomer->ticketCount = ticketCount;
    newCustomer->next = NULL;

    if(rear == NULL){
        front = rear = newCustomer;
    } else {
        rear->next = newCustomer;
        rear = newCustomer;
    }
    printf("Customer %s added with %d tickets.\n", name, ticketCount);
}

int isEmpty(){
    return front == NULL;
}

void serveCustomer(){
    if(isEmpty()){
        printf("No customers in queue.\n");
        return;
    }
    Customer *temp = front;
    printf("Serving customer %s with %d tickets.\n", temp->name, temp->ticketCount);
    front = front->next;
    if(front == NULL){
        rear = NULL;
    }
    free(temp);
}

void viewQueue(){
    if(isEmpty()){
        printf("No customers in queue.\n");
        return;
    }
    Customer *temp = front;
    int count = 1;
    printf("Current Queue: \n");
    while(temp != NULL){
        printf("Customer [%d]: %s, Tickets: %d\n", count, temp->name, temp->ticketCount);
        temp = temp->next;
    }
    printf("\n");
}

int main(){

    int choice;
    char name[50];
    int ticketCount;

    printf("Movie Ticket Booking System\n");
    do
    {
        printf("1. Add Customer\n");
        printf("2. Serve Customer\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            getchar();
            printf("Enter customer name:  ");
            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;

            printf("Enter number of tickets: ");
            scanf("%d", &ticketCount);
            addCustomer(name, ticketCount);
            break;
        case 2:
            serveCustomer();
            break;
        case 3:
            viewQueue();
            break;
        case 4:
            printf("Exiting the system.\n");
            exit(0);
        default:
        printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (choice != 4);

    return 0;
}