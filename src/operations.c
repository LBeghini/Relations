//
// Created by Lavinia on 9/12/2020.
//

#include "operations.h"
#include "set.h"
#include <math.h>

Relation * create_relation(char* op, char * initial, char * final){
    Relation * result = (Relation*) calloc(1, sizeof(Relation));
    result->initial = find_set(initial);
    result->final = find_set(final);
    if(strcmp(op, "<") == 0){
        result->couple = less_than(result->initial->head, result->final->head);
    }
    if(strcmp(op, ">") == 0){
        result->couple = greater_than(result->initial->head, result->final->head);
    }
    if(strcmp(op, "=") == 0){
        result->couple = equals(result->initial->head, result->final->head);
    }
    if(strcmp(op, "*") == 0){
        result->couple = square_of(result->initial->head, result->final->head);
    }
    if(strcmp(op, "/") == 0){
        result->couple = square_root_of(result->initial->head, result->final->head);
    }

    return result;
}

void fill_operation_list(char *str, List * current){

    char *buff = (char *) malloc(sizeof(char) * (int)(strlen(str) +1) );
    strcpy(buff, str);

    char * firstHalf = buff;
    char * secondHalf;

    char *operand = (char*) malloc(strlen(buff) + 1);
    strcpy(operand, strpbrk(buff, OPERANDS));       //<B<C
    *(operand+1) = '\0';                            //<

    secondHalf = strchr(buff, *operand);            //<B<C
    *secondHalf = '\0';                             //first half == A
    secondHalf = secondHalf+1;                      //B < C

    char *final = (char *) malloc(sizeof(char) * (int)(strlen(str) +1) );
    strcpy(final, secondHalf);
    *(final+1) = '\0';                              //teoricamente, == B

    current->relation = create_relation(operand, firstHalf, final);
    if (strlen(secondHalf) == 1) {
        return;
    }
    current->next = (List*) malloc(sizeof(List));
    current->next->next = NULL;
    current->next->relation = NULL;
    fill_operation_list(secondHalf, current->next);

}

List *prepare_operation_list(char *str){
    char *buff = (char *) malloc(sizeof(char) * (int) (strlen(str)+1));
    strcpy(buff, str);

    List *result = (List*) malloc(sizeof(List));
    result->relation = NULL;
    result->next = NULL;

    fill_operation_list(buff, result);

    return result;

}

Couple * solve_operation_list(List * current){
    if(current->next == NULL){
        return current->relation->couple;
    }

    current->relation->couple = compose(current->relation->couple, solve_operation_list(current->next));
}

List * find_tail(List * list_head){
    List * current = list_head;
    while(current->next != NULL){
        current = current->next;
    }
    return current;
}

Relation * generate_relation(List * op_list){
    Relation * result = (Relation*) calloc(1, sizeof(Relation));
    result->initial = op_list->relation->initial;
    result->couple = solve_operation_list(op_list);
    result->final = find_tail(op_list)->relation->final;

    result->image = image(result->couple);
    result->domain = domain(result->couple);

    result->total = is_total(result->domain, result->initial->head);
    result->surjective = is_surjective(result->image, result->final->head);
    result->functional = is_functional(result->couple);
    result->injective = is_injective(result->couple);

    result->monomorphism = result->total && result->injective;
    result->epimorphism = result->functional && result->surjective;
    result->isomorphism = result->monomorphism && result->epimorphism;

    return result;
}


Couple *greater_than(Node *Ahead, Node *Bhead) {
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;
    int count = 0;
    int is_null = 1;

    while (A != NULL) {
        while (B != NULL){
            if(A->value > B->value){
                is_null = 0;
                if(count == 0){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    count = 1;
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

    if(is_null){
        return NULL;
    }
    return result;

}

Couple *less_than(Node *Ahead, Node *Bhead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;
    int count = 0;
    int is_null = 1;

    while (A != NULL) {
        while (B != NULL){
            if(A->value < B->value){
                is_null = 0;
                if(count == 0){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    count = 1;
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

    if(is_null){
        return NULL;
    }
    return result;

}

Couple *equals(Node *Ahead, Node *Bhead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;
    int count = 0;
    int is_null = 1;

    while (A != NULL) {
        while (B != NULL){
            if(A->value == B->value){
                is_null = 0;
                if(count == 0){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    count = 1;
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

    if (is_null){
        return 0;
    }
    return result;

}

Couple *square_of(Node *Ahead, Node *Bhead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;
    int count = 0;
    int is_null = 1;

    while (A != NULL) {
        while (B != NULL){
            if(A->value == (B->value * B->value)){
                is_null = 0;
                if(count == 0){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    count = 1;
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

    if(is_null){
        return NULL;
    }

    return result;
}

Couple *square_root_of(Node *Ahead, Node *Bhead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Node * A = Ahead;
    Node * B = Bhead;
    int count = 0;
    int is_null = 1;

    while (A != NULL) {
        while (B != NULL){
            if((double)A->value == sqrt(B->value)){
                is_null = 0;
                if(count == 0){
                    current->x = A->value;
                    current->y = B->value;
                    B = B->next;
                    count = 1;
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

    if(is_null){
        return NULL;
    }

    return result;

}


Node *domain(Couple *couple){
    Node * domain = (Node *) malloc(sizeof(Node));
    domain->next = NULL;
    Couple * currentCouple = couple;
    Node * currentNode = domain;
    Node * empty = NULL;
    int count = 0;
    int flag = 0;

    if(!couple){
        return NULL;
    }

    while (currentCouple != NULL){
        if(currentCouple->x == 0){
            empty = (Node*) malloc(sizeof(Node));
            empty->value = 0;
            empty->next = NULL;
            flag = 1;
            currentCouple = currentCouple->next;
            continue;
        }
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
    if (flag) {
        empty->next = domain;
        return empty;
    }
    return domain;
}

Node *image(Couple *couple){
    Node * image = (Node *) malloc(sizeof(Node));
    image->next = NULL;
    Couple * currentCouple = couple;
    Node * currentNode = image;
    Node * empty = NULL;
    int count = 0;
    int flag = 0;

    if(!couple){
        return NULL;
    }

    while (currentCouple != NULL){
        if(currentCouple->x == 0){
            empty = (Node*) malloc(sizeof(Node));
            empty->value = 0;
            empty->next = NULL;
            flag = 1;
            currentCouple = currentCouple->next;
            continue;
        }
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

    if (flag) {
        empty->next = image;
        return empty;
    }

    return image;
}


int is_functional(Couple * couple){
    //only one x
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
    //only one y
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
    //domain == initial; every x appears
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
    //image == final; every y appears
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

Couple *compose(Couple *initialHead, Couple *finalHead){
    Couple * result = (Couple *)calloc(1, sizeof(Couple));
    Couple * current = result;
    Couple * initial = initialHead;
    Couple * final = finalHead;
    int count = 0;

    if(initialHead == NULL || finalHead == NULL){
        return NULL;
    }

    while (initial != NULL) {
        while (final != NULL){
            if(initial->y == final->x){
                if(!already_exists(initial->x, final->y, result)){
                    if(count == 0){
                        current->x = initial->x;
                        current->y = final->y;
                        final = final->next;
                        count = 1;
                        continue;
                    }
                    current->next = (Couple *) calloc(1, sizeof(Couple));
                    current = current->next;
                    current->x = initial->x;
                    current->y = final->y;
                }
            }
            final = final->next;
        }
        final = finalHead;
        initial = initial->next;
    }
    return result;
}