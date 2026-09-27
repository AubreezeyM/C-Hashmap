#ifndef HASHMAP_H
#define HASHMAP_H
#include <stddef.h>

#define DEFAULT_MAP_SIZE 10000
// borrowed these values from: https://xnacly.me/posts/2024/c-hash-map/
static const size_t BASE = 0x811c9dc5;
static const size_t PRIME = 0x01000193;

typedef struct Entry {
    char* key;
    void* data;
    struct entry* next_entry;
} Entry;

typedef struct HashMap {
    int length;
    int max_size;
    Entry** entries;
} HashMap;

HashMap* hashmap_init();
void hashmap_free(HashMap* this);
size_t hash(HashMap* this, char* str);
void hashmap_insert(HashMap* this, char* str, void* value);
void* hashmap_get(HashMap* this, char* str);
void hashmap_print_entries(HashMap* this);

#endif