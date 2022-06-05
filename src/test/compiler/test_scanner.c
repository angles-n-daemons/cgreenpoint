#include <stdlib.h>

#include "../../common.h"
#include "../../compiler/scanner.h"

void runScannerTest(const char* source) {
    initScanner(source);
    int line = -1;
    for (;;) {
        Token token = scanToken();
        if (token.type == TOKEN_ERROR) {
            printf("error: '%.*s'\n", token.length, token.start);
            exit(1);
        }

        if (token.line != line) {
            line = token.line;
            printf("%4d ", token.line);
        } else {
            printf("   | ");
        }

        printf("%2d '%.*s'\n", token.type, token.length, token.start);

        if (token.type == TOKEN_EOF) break;
    }
}

void testSingleCharacter() {
    runScannerTest("(){},.-+;/*");
}

void testSingleOrDoubles() {
    runScannerTest(">>=<<====!!=");
}

void testScanStrings() {
    runScannerTest("\"hello\"\"world\"");
}

void testWhitespace() {
    runScannerTest("!    \r\n\t   !");
}

void testComments() {
    runScannerTest("!= // this is a bit of a comment *&!\n\"this is a string literal\"");
}

void testIllegalCharacters() {
    initScanner("~");
    Token token = scanToken();
    if (token.type != TOKEN_ERROR) {
        printf("Expected token error but got type: %d", token.type);
        exit(1);
    }
    printf("char '~' successfully generated a scanner error\n");
}

void testIdentifiers() {
    runScannerTest("and if else elsen ifin while hey");
}

void testKeywords() {
    runScannerTest("and class else if nil or print return super var while false for fun this true");
}

void testScanner() {
    printf("testScanner starting\n");
    testSingleCharacter();
    testSingleOrDoubles();
    testScanStrings();
    testWhitespace();
    testComments();
    testIllegalCharacters();
    testIdentifiers();
    testKeywords();
    printf("testScanner ran successfully\n");
}
