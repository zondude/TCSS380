//  Jonathan Kim
//  TCSS 380
//  Programming Assignment 1


#include <stdio.h>
#include <stdlib.h>
#include "logic.h"
#include <string.h>

// Method to create the partition table.
Partition createList(int listSize){
    int i;
    Partition list = malloc(sizeof(struct partition) * listSize);
    
    // For loop to initialize an array of partitions.
    for(i = 0; i < listSize; i++){
        list[i].pid = -1;
        list[i].frag = -1;
        list[i].avail = 'Y';
    }
    return list;
}

// Method to add to the partition table.
void addProcessSize(Partition list, int processAdd, int id, int partSize, int part){
    
    // Intializing variables to be used to fill the table.
    int i, counter, leftOver;
    counter = processAdd / partSize;
    leftOver = processAdd % partSize;

    // For loop to check whether or not to add to the table.
    for (i = 0; i < part; i++){
        if (list[i].avail == 'Y'){
            if (counter > 0){
                list[i].avail = 'N';
                list[i].frag = 0;
                list[i].pid = id;
                counter--;
            } else if (leftOver > 0){
                list[i].avail = 'N';
                list[i].frag = partSize - (processAdd % partSize);
                list[i].pid = id;
                leftOver = 0;
            }
        }
    }
}

// Method that will "remove" partiitons, essentially resetting their values.
void removeProcess(Partition list, int delId, int partCount) {
    int i;
    
    // For loop that will reset partition that was chosen to be removed.
    for (i = 0; i < partCount; i++) {
        if (list[i].pid == delId) {
            list[i].pid = -1;
            list[i].frag = -1;
            list[i].avail = 'Y';
        }
    }
}

// Method that will print the whole table.
void printList(int partSize, int id, Partition list){
    // Initializing variables.
    int i, procId = 1;
    printf("Printing -\n");
    printf("---------------------------------------------------------------------------\n");
    printf("Process Table: -\n");
    printf("Process id           Frames-\n");

    // Initialzing a temporary variable for the process table.
    int temp = 0;

    // This for loop will print the process table going through each partitions pid.
    for(i = 0; i < partSize; i++) {
        if(list[i].pid != -1 && list[i].pid != temp) {
            printf("\n%d\t\t", list[i].pid);
            temp = list[i].pid;
        }
        if (list[i].pid == temp) {
            printf("%d ", i);
        }
    }
    printf("\n");
    printf("\n");
    printf("Partition Number    Process id        Frag       Availability \n");
    printf("---------------------------------------------------------------------------\n");

    // This if statement will keep track of empty, full, or partially filled partitions.
    if (id == 0){
        for(i = 0; i < partSize; i++){
            printf("%d                        %c                  %c                  %c       \n",i , '?', '?', list[i].avail);
        }
        } else {
            for(i = 0; i < partSize; i++){
                if (list[i].pid == -1){
                    printf("%d                        %c                  %c                  %c       \n",i , '?', '?', list[i].avail);

                } else {
                    printf("%d                        %d                  %d                  %c       \n",i , list[i].pid, list[i].frag, list[i].avail);
                }
            }

        }
}