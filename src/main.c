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
    Relation * relation = (Relation*) calloc(1, sizeof(Relation));
    relation->initial = listOfSets;
    relation->final = listOfSets->next;
    relation->couple = square_root_of(relation->initial->head, relation->final->head);
    relation->image = image(relation->couple);
    relation->domain = domain(relation->couple);
    relation->total = is_total(relation->domain, relation->initial->head);
    relation->surjective = is_surjective(relation->image, relation->final->head);
    relation->functional = is_functional(relation->couple);
    relation->injective = is_injective(relation->couple);

    return 0;
}
