#include <iostream>
using namespace std;

#define TABLE_SIZE 10

// Function to perform hash search
int hash_search(int hashTable[], int keys[], int values[], int key);

// Function to insert a key-value pair into the hash table
void insert(int hashTable[], int keys[], int values[], int key, int value) {
    int index = key % TABLE_SIZE;

    // If the bucket is empty
    if (hashTable[index] == -1) {
        hashTable[index] = key;
        keys[index] = key;
        values[index] = value;
    } else { // If collision occurs, linear probing
        int i = index + 1;
        while (hashTable[i % TABLE_SIZE] != -1 && i % TABLE_SIZE != index) {
            i++;
        }
        if (i % TABLE_SIZE == index) {
            cout << "Hash table is full, unable to insert key-value pair\n";
            return;
        }
        hashTable[i % TABLE_SIZE] = key;
        keys[i % TABLE_SIZE] = key;
        values[i % TABLE_SIZE] = value;
    }
}

// Function to perform hash search
int hash_search(int hashTable[], int keys[], int values[], int key) {
    int index = key % TABLE_SIZE;
    int i = index;
    // Linear probing to find the key
    while (hashTable[i % TABLE_SIZE] != key && hashTable[i % TABLE_SIZE] != -1 && i % TABLE_SIZE != index) {
        i++;
    }
    if (hashTable[i % TABLE_SIZE] == key) {
        return values[i % TABLE_SIZE];
    } else {
        return -1; // Key not found
    }
}

void result(int a)
{
    if (a == -1)
        cout << "Key not in array";
    else
        cout << "Value: " << a << endl;
}

int main() {
    int hashTable[TABLE_SIZE];
    int keys[TABLE_SIZE];
    int values[TABLE_SIZE];

    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    // Insert key-value pairs into the hash table
    insert(hashTable, keys, values, 1, 1);
    insert(hashTable, keys, values, 8, 8);
    insert(hashTable, keys, values, 19, 19);
    insert(hashTable, keys, values, 23, 23);
    insert(hashTable, keys, values, 45, 45);
    insert(hashTable, keys, values, 88, 88);
    insert(hashTable, keys, values, 107, 107);

    int k = 0;
    int hash_result = hash_search(hashTable, keys, values, k);

    cout << "Hash Search: ";
    result(hash_result);

    return 0;
}

