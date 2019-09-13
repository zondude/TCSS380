//  Jonathan Kim
//  TCSS 380
//  Programming Assignment 1

#ifndef LOGIC_H
#define LOGIC_H

typedef struct partition *Partition;

struct partition {
  int pid;
  int frag;
  char avail;
  int partNum;
};

Partition createList(int part);

void addProcessSize(Partition list, int processAdd, int id, int partSize, int part);

void removeProcess(Partition list, int delId, int partCount);

void printList(int partSize, int id, Partition list);

#endif