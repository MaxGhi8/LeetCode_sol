
// First solution: with sorting
// #include <stdio.h>
// #include <stdlib.h>

// int compare(const void* a, const void*b){
//     return (*(int *)a - *(int *)b);
// }

// bool containsDuplicate(int* nums, int numsSize) {
//     if(numsSize <= 1){
//         return false;
//     }

//     // Sort the array 
//     qsort(nums, numsSize, sizeof(int), *compare);
    
//     // Check for duplicate
//     for(int i = 0; i < numsSize-1; i++){
//         if(nums[i] == nums[i+1]){
//             return true;
//         }
//     }
//     return false;
// }

// Second solutions: with Hashmaps
#include <stdbool.h>
#include <stdlib.h>

struct HashNode {
    int key;
    struct HashNode* next;
};

#define TABLE_SIZE 10007

// Hash function
unsigned int hash(int key) {
    return abs(key) % TABLE_SIZE;
}

// Insert into hash table
bool insert(struct HashNode** table, int key) {
    unsigned int index = hash(key);
    struct HashNode* node = table[index];
    while (node) {
        if (node->key == key) {
            return true; // Duplicate found
        }
        node = node->next;
    }
    // Insert new node
    struct HashNode* newNode = (struct HashNode*)malloc(sizeof(struct HashNode));
    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;
    return false;
}

bool containsDuplicate(int* nums, int numsSize) {
    // Initialize hash table
    struct HashNode* table[TABLE_SIZE] = {0};

    // Check for duplicates
    for (int i = 0; i < numsSize; i++) {
        if (insert(table, nums[i])) {
            // Free allocated memory before returning
            for (int j = 0; j < TABLE_SIZE; j++) {
                struct HashNode* node = table[j];
                while (node) {
                    struct HashNode* temp = node;
                    node = node->next;
                    free(temp);
                }
            }
            return true;
        }
    }

    // Free allocated memory
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct HashNode* node = table[i];
        while (node) {
            struct HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }

    return false;
}
