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

typedef struct Relation{
    struct Set * initial;
    struct Set * final;
    struct Couple * couple;
    int functional;
    int injective;
    int surjective;
    int total;
    int monomorphism;
    int epimorphism;
    int isomorphism;
    Node * domain;
    Node * image;
} Relation;

Set *create_list_set(Set *head, Line *input);
void process_nodes(Node *current, Line *charNumber);
void populate(Set *empty, Line *charNumbers);

Node * copy_of_node(Node *A);
Set * copy_of_set(Set * A);
Set * find_set(char* name);

int belongs_to(int value, Node *A);
int already_exists(int x, int y, Couple * head);

#endif //RELATIONS_SET_H
