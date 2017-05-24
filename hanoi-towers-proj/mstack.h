#pragma once

#include "list.h"

/**
 * A basic stack implementation utilizing a list.
 * The type of the stack is `mstack_t` since stack_t conflicts with
 * a pre-existing type on certain OS X setups.
 */

typedef list_t mstack_t;

// Creates a stack
mstack_t* make_mstack(void);

// Frees a stack
void free_mstack(mstack_t *st);

// Returns the stack's size
// pre: st != NULL
int mstack_size(mstack_t *st);

// Prints the stack
// pre: st != NULL
void mstack_print(mstack_t *st);

// Pushes an element onto the stack
// pre: st != NULL
void mstack_push(mstack_t *st, int v);

// Pops an element off the stack
// pre: st != NULL, st is non-empty
int mstack_pop(mstack_t *st);

// Returns the top of the stack without popping it
// pre: st != NULL, st is non-empty
int mstack_peek(mstack_t *st);
