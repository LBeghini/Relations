//
// Created by Lavinia on 9/12/2020.
//

#include "operations.h"
#include <math.h>

Couple *set_greater_than(Node *Ahead, Node *Bhead) {
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

Couple *set_less_than(Node *Ahead, Node *Bhead){
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

Couple *set_equals(Node *Ahead, Node *Bhead){
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

Couple *set_square_of(Node *Ahead, Node *Bhead){
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

Node *domain(Couple *couple){
    Node * domain = (Node *) calloc(1, sizeof(Node));
    Couple * currentCouple = couple;
    Node * currentNode = domain;
    int count = 0;

    while (currentCouple != NULL){
        if(!belongs_to(currentCouple->x, domain)) {
            if (count == 0){
                domain->value = currentCouple->x;
                currentCouple = currentCouple->next;
                count ++;
                continue;
            }
            currentNode->next = (Node *) calloc(1, sizeof(Node));
            currentNode->next->value = currentCouple->x;
            currentNode = currentNode->next;
        }
        currentCouple = currentCouple->next;

    }

    return domain;
}

Node *image(Couple *couple){
    Node * image = (Node *) calloc(1, sizeof(Node));
    Couple * currentCouple = couple;
    Node * currentNode = image;
    int count = 0;

    while (currentCouple != NULL){
        if(!belongs_to(currentCouple->y, image)) {
            if (count == 0){
                image->value = currentCouple->y;
                currentCouple = currentCouple->next;
                count ++;
                continue;
            }
            currentNode->next = (Node *) calloc(1, sizeof(Node));
            currentNode->next->value = currentCouple->y;
            currentNode = currentNode->next;
        }
        currentCouple = currentCouple->next;

    }

    return image;
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

int is_functional(Couple * couple){
    Couple * current = couple;
    Couple * aux = couple;
    int count = 0;

    while (aux != NULL){
        while (current != NULL){
            if(aux->x == current->x){
                count++;
                if(count > 1) {
                    return 0;
                }
            }
            current = current->next;
        }
        aux = aux->next;
        current = couple;
        count = 0;
    }
    return 1;
}

int is_injective(Couple * couple){
    Couple * current = couple;
    Couple * aux = couple;
    int count = 0;

    while (aux != NULL){
        while (current != NULL){
            if(aux->y == current->y){
                count++;
                if(count > 1) {
                    return 0;
                }
            }
            current = current->next;
        }
        aux = aux->next;
        current = couple;
        count = 0;
    }
    return 1;
}

int is_total(Node * domain, Node * initial){
    Node * currentDomain = domain;
    Node * currentElement = initial;
    int flag = 0;

    while (currentElement != NULL){
        while (currentDomain != NULL){
            if (currentDomain->value == currentElement->value){
                flag = 1;
                currentDomain = domain;
                break;
            }
            currentDomain = currentDomain->next;
        }
        if(flag == 0){
            return 0;
        }
        currentElement = currentElement->next;
        flag = 0;
    }
    return 1;
}

int is_surjective(Node * image, Node * final){
    Node * currentImage = image;
    Node * currentElement = final;
    int flag = 0;

    while (currentElement != NULL){
        while (currentImage != NULL){
            if (currentImage->value == currentElement->value){
                flag = 1;
                currentImage = image;
                break;
            }
            currentImage = currentImage->next;
        }
        if(flag == 0){
            return 0;
        }
        currentElement = currentElement->next;
        flag = 0;
    }
    return 1;
}