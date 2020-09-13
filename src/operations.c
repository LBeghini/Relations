//
// Created by Lavinia on 9/12/2020.
//

#include "operations.h"
#include <math.h>

Couple *greater_than(Node *Ahead, Node *Bhead) {
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;

    while (A != NULL) {
        while (B != NULL){
            if(A->value > B->value){
                if(!current->y || !current->x){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    continue;
                }
                current->next = (Couple *) calloc(1, sizeof(Couple));
                current = current->next;
                current->x = A->value;
                current->y = B->value;
            }
            B = B->next;
        }
        B = Bhead;
        A = A->next;
    }

    return result;

}

Couple *less_than(Node *Ahead, Node *Bhead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;

    while (A != NULL) {
        while (B != NULL){
            if(A->value < B->value){
                if(!current->y || !current->x){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    continue;
                }
                current->next = (Couple *) calloc(1, sizeof(Couple));
                current = current->next;
                current->x = A->value;
                current->y = B->value;
            }
            B = B->next;
        }
        B = Bhead;
        A = A->next;
    }

    return result;

}

Couple *equals(Node *Ahead, Node *Bhead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;

    while (A != NULL) {
        while (B != NULL){
            if(A->value == B->value){
                if(!current->y || !current->x){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    continue;
                }
                current->next = (Couple *) calloc(1, sizeof(Couple));
                current = current->next;
                current->x = A->value;
                current->y = B->value;
            }
            B = B->next;
        }
        B = Bhead;
        A = A->next;
    }

    return result;

}

Couple *square_of(Node *Ahead, Node *Bhead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;

    while (A != NULL) {
        while (B != NULL){
            if(A->value == (B->value * B->value)){
                if(!current->y || !current->x){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    continue;
                }
                current->next = (Couple *) calloc(1, sizeof(Couple));
                current = current->next;
                current->x = A->value;
                current->y = B->value;
            }
            B = B->next;
        }
        B = Bhead;
        A = A->next;
    }

    return result;

}

Couple *square_root_of(Node *Ahead, Node *Bhead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;

    while (A != NULL) {
        while (B != NULL){
            if((double)A->value == sqrt(B->value)){
                if(!current->y || !current->x){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    continue;
                }
                current->next = (Couple *) calloc(1, sizeof(Couple));
                current = current->next;
                current->x = A->value;
                current->y = B->value;
            }
            B = B->next;
        }
        B = Bhead;
        A = A->next;
    }

    return result;

}