#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct {
    int key;
    int value;
    int isOccupied;
} HashTableEntry;

void initializeTable(HashTableEntry hashTable[]) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i].isOccupied = 0; 
    }
}

int hash(int key) {
    return key % TABLE_SIZE;
}

void insert(HashTableEntry hashTable[], int key, int value) {
    int index = hash(key);
    int originalIndex = index;
    int i = 1;

    while (hashTable[index].isOccupied) {
        index = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (index == originalIndex) {
            printf("Hash table is full, cannot insert key %d.\n", key);
            return;
        }
    }

    hashTable[index].key = key;
    hashTable[index].value = value;
    hashTable[index].isOccupied = 1; 
    printf("Inserted key %d with value %d at index %d.\n", key, value, index);
}

int search(HashTableEntry hashTable[], int key) {
    int index = hash(key);
    int originalIndex = index;
    int i = 1;

    while (hashTable[index].isOccupied) {
        if (hashTable[index].key == key) {
            return hashTable[index].value;
        }
        index = (originalIndex + i) % TABLE_SIZE;
        i++;
        if (index == originalIndex) {
            break;
        }
    }
    return -1;
}

void printHashTable(HashTableEntry hashTable[]) {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i].isOccupied) {
            printf("Index %d: (Key: %d, Value: %d)\n", i, hashTable[i].key, hashTable[i].value);
        } else {
            printf("Index %d: (NULL)\n", i);
        }
    }
}

int main() {
    HashTableEntry hashTable[TABLE_SIZE];
    initializeTable(hashTable);

    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 42, 30);
    insert(hashTable, 4, 40);
    insert(hashTable, 12, 50);

  printHashTable(hashTable);
    int key = 42;
    int value = search(hashTable, key);
    if (value != -1) {
        printf("\nKey %d found with value %d.\n", key, value);
    } else {
        printf("\nKey %d not found.\n", key);
    }
   
    return 0;
}
