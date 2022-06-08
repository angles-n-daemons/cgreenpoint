#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../main/object/table.h"
#include "../../main/object/object.h"

void testBasic() {
    Table table;
    initTable(&table);

    ObjString* key1 = copyString("tests", 5);

    tableSet(&table, key1, BOOL_VAL(false));

    Value result;
    bool newKey = tableGet(&table, key1, &result);

    if (!newKey) {
        printf("testTable testBasic: expected key to be new, but tableSet returned false\n");
        exit(1);
    }

    if (AS_BOOL(result) != false) {
        printf("testTable testBasic: expected false for %s\n", key1->chars);
        exit(1);
    }
}

void testLotsOfStuff() {
    Table table;
    initTable(&table);

    char randstrs[300][11] = {{0}};
    ObjString* keys[300] = {NULL};
    srand (time(NULL));
    
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 10; j++) {
            randstrs[i][j] = rand() % 26 + 65;
        }
        randstrs[i][10] = '\0';
        keys[i] = copyString(randstrs[i], 10);
    }
    
    for (int i = 0; i < 300; i++) {
        tableSet(&table,keys[i], NUMBER_VAL(i)); 
    }

    for (int i = 0; i < 300; i++) {
        Value result;
        tableGet(&table, keys[i], &result);
        if (AS_NUMBER(result) != i) {
            printf("testTable testLotsOfStuff: expected %f but got %f\n", (double)i, AS_NUMBER(result));
            exit(1);
        }
    }
}

void testOverwriteKey() {
    Table table;
    initTable(&table);

    ObjString* key1 = copyString("tests", 5);

    // same as first test, but set value again after first set
    tableSet(&table, key1, BOOL_VAL(false));
    bool newKey = tableSet(&table, key1, BOOL_VAL(true));

    if (newKey) {
        printf("testTable testOverwriteKey: expected key to not be new, but tableSet returned true\n");
        exit(1);
    }

    Value result;
    bool found = tableGet(&table, key1, &result);
    if (!found) {
        printf("testTable testOverwriteKey: tableGet returned false\n");
        exit(1);
    }

    if (AS_BOOL(result) != true) {
        printf("testTable testOverwriteKey: expected true for %s\n", key1->chars);
        exit(1);
    }
}

void testDelete() {
    Table table;
    initTable(&table);

    ObjString* key1 = copyString("tests", 5);

    tableSet(&table, key1, BOOL_VAL(false));
    tableDelete(&table, key1);

    Value result;
    bool found = tableGet(&table, key1, &result);

    if (found) {
        printf("testTable testDelete: expected tableGet to return false on deleted key but was found\n");
        exit(1);
    }
}

void testDifferentKeyCheck() {
    Table table;
    initTable(&table);

    ObjString* key1 = copyString("tests", 5);
    ObjString* key2 = copyString("bests", 5);

    tableSet(&table, key1, BOOL_VAL(false));

    Value result;
    bool found = tableGet(&table, key2, &result);

    if (found) {
        printf("testTable testDelete: expected tableGet to return false on deleted key but was found\n");
        exit(1);
    }
}

void testTable() {
    printf("testTable starting\n");
    testBasic();
    testLotsOfStuff();
    testOverwriteKey();
    testDelete();
    testDifferentKeyCheck();
    printf("testTable completed\n");
}
