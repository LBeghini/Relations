//
// Created by Lavinia on 9/12/2020.
//

#ifndef RELATIONS_SET_H
#define RELATIONS_SET_H

#include "fileIO.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Couple{
    int x;
    int y;
    struct Couple * next;
} Couple;

typedef struct Node {
    int value;
    struct Node * next;
} Node;


typedef struct Set {
    char name;
    struct Node * head;
    struct Set * next;
} Set;

Set *create_list_set(Set *head, Line *input);
void process_nodes(Node *current, Line *charNumber);
void populate(Set *empty, Line *charNumbers);
char * set_to_string(Set *A);


#endif //RELATIONS_SET_H
