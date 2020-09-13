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

Set *domain(Couple *couple){
    Set * result = (Set *)calloc(1, sizeof(Set));
    Node * domain = (Node *) calloc(1, sizeof(Node));
    result->head = domain;
    Couple * current = couple;

    while (current != NULL){
        if(!belongs_to(current->x, result->head)){
            domain->value =  current->x;
        }
        current = current->next;
        if(current == NULL){
            continue;
        }
        domain->next = (Node *) calloc(1, sizeof(Node));
        domain = domain->next;
    }

    return result;
}

Set *image(Couple *couple){
    Set * result = (Set *)calloc(1, sizeof(Set));
    Node * image = (Node *) calloc(1, sizeof(Node));
    result->head = image;
    Couple * current = couple;

    while (current != NULL){
        if(!belongs_to(current->y, result->head)){
            image->value =  current->y;
        }
        current = current->next;
        if(current == NULL){
            continue;
        }
        image->next = (Node *) calloc(1, sizeof(Node));
        image = image->next;
    }

    return result;
}

int belongs_to(int value, Node *A) {
    if(!A){
        return 0;
    }

    Node *current = A;
    while (current) {
        if (current->value == value) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}