#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

/*  Wrapping init() and free() into utility functions for now, as
    I might need to extend their functionality later. */
HashMap* hashmap_init() {
    HashMap* hm = malloc(sizeof(HashMap));
    hm->length = 0;
    hm->max_size = DEFAULT_MAP_SIZE;
    hm->entries = calloc(0, sizeof(void*) * hm->max_size);

    return hm;
}

void hashmap_free(HashMap* this) {
    free(this->entries);
    free(this);
}

size_t hash(HashMap* this, char* str) {
    size_t initial = BASE;
    while (*str) {
        initial ^= *str++;
        initial *= PRIME;
    }
    return initial % this->max_size;
}

void hashmap_insert(HashMap* this, char* str, void* value) {
    Entry* entry = malloc(sizeof(Entry));
    entry->key = str;
    entry->data = value;
    entry->next_entry = NULL;
    size_t hashed_key = hash(this, str);

    this->length++;
    this->entries[hashed_key] = entry;
}

void* hashmap_get(HashMap* this, char* str) {
    Entry* entry = this->entries[hash(this, str)];
    return entry ? entry->data : NULL;
}