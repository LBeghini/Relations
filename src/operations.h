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

Couple *greater_than(Node *Ahead, Node *Bhead);
Couple *less_than(Node *Ahead, Node *Bhead);
Couple *equals(Node *Ahead, Node *Bhead);
Couple *square_of(Node *Ahead, Node *Bhead);
Couple *square_root_of(Node *Ahead, Node *Bhead);

Node *domain(Couple *couple);
Node *image(Couple *couple);
int belongs_to(int value, Node *A);
int is_injective(Couple * couple);
int is_functional(Couple * couple);
int is_total(Node * domain, Node * initial);
int is_surjective(Node * image, Node * final);

#endif //RELATIONS_OPERATIONS_H
