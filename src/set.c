//
// Created by Lavinia on 9/12/2020.
//

#include "set.h"

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