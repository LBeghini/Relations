//
// Created by Lavinia on 9/12/2020.
//

#ifndef RELATIONS_OPERATIONS_H
#define RELATIONS_OPERATIONS_H

#include "set.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"

typedef struct List {
    struct Relation *relation;
    struct List *next;
} List;

List *prepare_operation_list(char *str);
void fill_operation_list(char *str, List * current);
Couple * solve_operation_list(List * current);


Couple *greater_than(Node *Ahead, Node *Bhead);
Couple *less_than(Node *Ahead, Node *Bhead);
Couple *equals(Node *Ahead, Node *Bhead);
Couple *square_of(Node *Ahead, Node *Bhead);
Couple *square_root_of(Node *Ahead, Node *Bhead);

Node *domain(Couple *couple);
Node *image(Couple *couple);

int is_injective(Couple * couple);
int is_functional(Couple * couple);
int is_total(Node * domain, Node * initial);
int is_surjective(Node * image, Node * final);

Couple *compose(Couple *initialHead, Couple *finalHead);
#endif //RELATIONS_OPERATIONS_H
