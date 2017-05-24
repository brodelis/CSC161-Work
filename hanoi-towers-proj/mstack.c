#include "mstack.h"
#include <assert.h>

mstack_t* make_mstack(void) {
    return make_list();
}

void free_mstack(mstack_t *st) {
    free_list(st);
}

int mstack_size(mstack_t *st) {
    return list_size(st);
}

void mstack_print(mstack_t *st) {
    print_list(st);
}

void mstack_push(mstack_t *st, int v) {
    insert_front(st, v);
}

int mstack_pop(mstack_t *st) {
    assert(mstack_size(st) > 0);
    int ret = list_get(st, 0);
    list_remove(st, 0);
    return ret;
}

int mstack_peek(mstack_t *st) {
    assert(mstack_size(st) > 0);
    return list_get(st, 0);
}
