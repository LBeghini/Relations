//
// Created by Lavinia on 9/12/2020.
//

#include <math.h>
#include "operations.h"
#include "set.h"
#include "global.h"

void populate(Set *empty, Line *charNumbers) {
    if (charNumbers) {
        empty->head = (Node *) malloc(sizeof(Node));
        process_nodes(empty->head, charNumbers);
    }
}

void process_nodes(Node *current, Line *charNumber) {
    if (charNumber) {
        current->next = NULL;
        if (charNumber->next) {
            Node *head;
            head = (Node *) calloc(1, sizeof(Node));
            current->next = head;
        }

        current->value = (int) strtol(charNumber->value, NULL, 10);
        process_nodes(current->next, charNumber->next);
    }
}

Set *create_list_set(Set *head, Line *input) {

    if (input->value[0] >= 'A' && input->value[0] <= 'Z') {
        head = (Set *) malloc(sizeof(Set));
        head->name = input->value[0];
        head->next = NULL;
        head->head = NULL;
        populate(head, get_numbers(input->value));

        if (input->next != NULL) {
            head->next = create_list_set(head->next, input->next);
        }

    } else if (input->next != NULL) {

        head = create_list_set(head, input->next);
    }
    return head;
}

char * couple_to_string(Couple * couple){
    if(couple == NULL){
        return "< >";
    }
    Couple * current = couple;
    char * result = (char*) calloc(2, sizeof(char));
    char * aux = (char*) calloc(7, sizeof(char));
    while(current){
        result = realloc(result, sizeof(char) * ((int)strlen(result) + 7 ));
        sprintf(aux, "<%d,%d>,", current->x, current->y);
        strcat(result, aux);
        current = current->next;
    }
    strcpy((result+(int)strlen(result)-1), "\0");
    return result;
}

char * set_to_string(Set *A){
    if(!A->head){
        return "{ }";
    }
    Node *current = A->head;
    char * result = (char*) malloc(sizeof(char));
    strcpy(result, "{");
    char * str = (char*) malloc(sizeof(char));
    while(current){
        sprintf(str, "%d, ", current->value);
        strcat(result, str);
        current = current->next;
    }
    strcpy((result+strlen(result)-2), "}\0");
    return result;
}

Set * copy_of_set(Set * A){
    Set * current = A;
    Set * copy = (Set*) calloc(1, sizeof(Set));
    Set * head = copy;
    while(current){
        copy->name = current->name;
        copy->head = copy_of_node(current->head);

        if(!current->next){
            break;
        }
        copy->next = (Set*) calloc(1, sizeof(Set));
        copy = copy->next;
        current = current->next;
    }

    return head;
}

Node * copy_of_node(Node *A){
    Node * current = A;
    Node *copy = (Node*) calloc(1, sizeof(Node));
    Node * head = copy;
    while(current){
        copy->value = current->value;

        if(!current->next){
            break;
        }
        copy->next = (Node*) calloc(1, sizeof(Node));
        copy = copy->next;
        current = current->next;
    }

    return head;
}

Set * find_set(char* name){
    Set *current = copy_of_set(listOfSets);

    while (current) {
        if (strchr(name, current->name)){
            current->next = NULL;
            return current;
        }
        current = current->next;
    }
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

int already_exists(int x, int y, Couple * head){
    if(!head){
        return 0;
    }

    Couple *current = head;
    while (current) {
        if ((current->x == x)&&(current->y == y)) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}