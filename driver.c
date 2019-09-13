//  Jonathan Kim
//  TCSS 380
//  Programming Assignment 1


#include <stdio.h>
#include "logic.h"
#include <string.h>


int main(){
    // Initializing variables to be used in the program.
    int userChoice= 0, part = 0, partSize = 0, partAdd = 0, id = 0, delId = 0;
    Partition list;
    printf("Enter the number of partitions: \n");
    scanf("%d", &part);
    printf("Enter the size of each partition: \n");
    scanf("%d", &partSize);
    list = createList(part);

    // While loop for user choices.
    while(userChoice != 4){
        printf("Add a process? Enter 1 \n");
        printf("Delete a process? Enter 2 \n");
        printf("Print values? Enter 3 \n");
        printf("Quit? Enter 4 \n");
        scanf("%d", &userChoice);
        if (userChoice == 1){
            id++;   // id counter increment
            printf("Adding -enter process size: ");
            scanf("%d", &partAdd);
            addProcessSize(list, partAdd, id, partSize, part);  // Method to add to the partition table.

        } else if (userChoice == 2){
            printf("Deleting -enter process id: ");
            scanf("%d", &delId);
            removeProcess(list, delId, part);  // Method to remove from the partition table.

        } else if (userChoice == 3){
            printList(part, id, list);  // Method to print everything.
        }
    }
}