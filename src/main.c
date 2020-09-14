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

//    Relation * R = (Relation*) calloc(1, sizeof(Relation));
//    R->initial = listOfSets;
//    R->final = listOfSets->next;
//    R->couple = less_than(R->initial->head, R->final->head);
//    R->image = image(R->couple);
//    R->domain = domain(R->couple);
//    R->total = is_total(R->domain, R->initial->head);
//    R->surjective = is_surjective(R->image, R->final->head);
//    R->functional = is_functional(R->couple);
//    R->injective = is_injective(R->couple);
//
//
//    Relation * S = (Relation*) calloc(1, sizeof(Relation));
//    S->initial = listOfSets->next;
//    S->final = listOfSets->next->next;
//    S->couple = less_than(S->initial->head, S->final->head);
//    S->image = image(S->couple);
//    S->domain = domain(S->couple);
//    S->total = is_total(S->domain, S->initial->head);
//    S->surjective = is_surjective(S->image, S->final->head);
//    S->functional = is_functional(S->couple);
//    S->injective = is_injective(S->couple);
//
//    Relation * RS = (Relation*) calloc(1, sizeof(Relation));
//    RS->initial = R->initial;
//    RS->final = S->final;
//    RS->couple = compose(R->couple, S->couple);
//    RS->image = image(RS->couple);
//    RS->domain = domain(RS->couple);
//    RS->total = is_total(RS->domain, RS->initial->head);
//    RS->surjective = is_surjective(RS->image, RS->final->head);
//    RS->functional = is_functional(RS->couple);
//    RS->injective = is_injective(RS->couple);

    char * test = "A<B<C";

    Couple * aa = solve_operation_list(prepare_operation_list(test));

    return 0;
}
