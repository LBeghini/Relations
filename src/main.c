#include "set.h"
#include <stdio.h>
#include "fileIO.h"
#include <conio.h>
#include "global.h"
#define PATH "..\\set.txt"
#include "operations.h"


int main() {
    Line *input = process_input(PATH);
    listOfSets = (Set*) malloc(sizeof(Set));
    listOfSets = create_list_set(listOfSets, input);

    Relation * R = (Relation*) calloc(1, sizeof(Relation));
    R->initial = listOfSets;
    R->final = listOfSets->next;
    R->couple = square_root_of(R->initial->head, R->final->head);
    R->image = image(R->couple);
    R->domain = domain(R->couple);
    R->total = is_total(R->domain, R->initial->head);
    R->surjective = is_surjective(R->image, R->final->head);
    R->functional = is_functional(R->couple);
    R->injective = is_injective(R->couple);


    Relation * S = (Relation*) calloc(1, sizeof(Relation));
    S->initial = listOfSets->next;
    S->final = listOfSets->next->next;
    S->couple = square_root_of(S->initial->head, S->final->head);
    S->image = image(S->couple);
    S->domain = domain(S->couple);
    S->total = is_total(S->domain, S->initial->head);
    S->surjective = is_surjective(S->image, S->final->head);
    S->functional = is_functional(S->couple);
    S->injective = is_injective(S->couple);


    return 0;
}
