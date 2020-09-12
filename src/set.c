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

