#ifndef DICTTREE_H
#define DICTTREE_h
#define NUMOfCHARS 27 /* a-z plus ' */
#include <iostream>


using namespace std;

struct dictNode
{

    // isWord isTRUE if the node represents
    // the last character of a word
    bool isWord;

    // Collection of nodes that represent subsequent characters in
    // words. Each node in the next dictNode*
    // array corresponds to a particular character that continues
    // the word if the node at the array index is NOT NULL:
    // e.g., if next[0] is NOT NULL, it means ‘a’ would be
    // one of the next characters that continues the current word;
    // while next[0] being NULL means there are no further words
    // with the next letter as ‘a’ along this path.
    struct dictNode *next[NUMOfCHARS];

};

// Declare all functions needed


struct dictNode *createANewNode();

int indexOfChars(char);

void insertWords2Dictionary(struct dictNode *, string);

bool findEndingNodeOfAStr(struct dictNode *, string);

int countWordsStartingFromANode(int &, struct dictNode *);


#endif   // DICTTREE_H
