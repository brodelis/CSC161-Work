#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

node_t* make_node(int value, node_t *next) {
    node_t *ret = (node_t*) malloc(sizeof(node_t));
    ret->value = value;
    ret->next  = next;
    return ret;
}

void free_node(node_t *n) {
    free(n);
}

list_t* make_list(void) {
    list_t *ret = (list_t*) malloc(sizeof(list_t));
    ret->first = NULL;
    return ret;
}

void free_list(list_t *l) {
    node_t *cur = l->first;
    while (cur != NULL) {
        node_t *t = cur->next;
        free_node(cur);
        cur = t;
    }
    free(l);
}

void insert_front(list_t *l, int value) {
    l->first = make_node(value, l->first);
}

void insert_back(list_t *l, int value) {
    if (l->first == NULL) {
        insert_front(l, value);
    } else {
        node_t *cur = l->first;
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = make_node(value, NULL);
    }
}

int list_size(list_t *l) {
    node_t *cur = l->first;
    int sz = 0;
    while (cur != NULL) {
        sz += 1;
        cur = cur->next;
    }
    return sz;
}

void print_list(list_t *l) {
    printf("[");
    if (l->first != NULL) {
        printf("%d", l->first->value);
        node_t *cur = l->first->next;
        while (cur != NULL) {
            printf(", %d", cur->value);
            cur = cur->next;
        }
    }
    printf("]\n");
}

bool list_remove(list_t *l, int index) {
    if (index < 0 || index >= list_size(l)) {
        return false;
    } else if (index == 0) {
        node_t *t = l->first->next;
        free_node(l->first);
        l->first = t;
        return true;
    } else {
        node_t *cur = l->first;
        while (index > 1) {
            cur = cur->next;
            index--;
        }
        node_t *t = cur->next->next;
        free_node(cur->next);
        cur->next = t;
        return true;
    }
}

// pre: index >= 0 >= size(l)
int list_get(list_t *l, int index) {
    if (index < 0 || index >= list_size(l)) {
        return -1;    // N.B. ugh, nothing to do...
    } else {
        node_t *cur = l->first;
        while (index != 0) {
            cur = cur->next;
            index--;
        }
        return cur->value;
    }
}
