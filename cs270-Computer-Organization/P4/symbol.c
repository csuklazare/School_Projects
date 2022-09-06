#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "Debug.h"
#include "symbol.h"

/** @file symbol.c
 *  @brief You will modify this file and implement the symbol.h interface
 *  @details Your implementation of the functions defined in symbol.h.
 *  You may add other functions if you find it helpful. Added functions
 *  should be declared <b>static</b> to indicate they are only used
 *  within this file. The reference implementation added approximately
 *  110 lines of code to this file. This count includes lines containing
 *  only a single closing bracket (}).
 * <p>
 * @author Brock Fisher goes here
 */

/** size of LC3 memory */
#define LC3_MEMORY_SIZE  (1 << 16)

/** Provide prototype for strdup() */
char *strdup(const char *s);

/** defines data structure used to store nodes in hash table */
typedef struct node {
  struct node* next;     /**< linked list of symbols at same index */
  int          hash;     /**< hash value - makes searching faster  */
  symbol_t     symbol;   /**< the data the user is interested in   */
} node_t;

/** defines the data structure for the hash table */
struct sym_table {
  int      capacity;    /**< length of hast_table array                  */
  int      size;        /**< number of symbols (may exceed capacity)     */
  node_t** hash_table;  /**< array of head of linked list for this index */
  char**   addr_table;  /**< look up symbols by addr                     */
};

/** djb hash - found at http://www.cse.yorku.ca/~oz/hash.html
 * tolower() call to make case insensitive.
 */

static int symbol_hash (const char* name) {
  unsigned char* str  = (unsigned char*) name;
  unsigned long  hash = 5381;
  int c;

  while ((c = *str++))
    hash = ((hash << 5) + hash) + tolower(c); /* hash * 33 + c */

  c = hash & 0x7FFFFFFF; /* keep 31 bits - avoid negative values */

  return c;
}

/** @todo implement this function */
sym_table_t* symbol_init (int capacity) {
  sym_table_t* symbolTable = calloc(sizeof(sym_table_t), 1);
  debug("made it inside function");
  symbolTable->capacity = capacity;
  debug("%d = symbolTable capacity", symbolTable->capacity);
  symbolTable->size = 0;
  debug("%d = initial size of symbol table", symbolTable->size);
  symbolTable->hash_table = calloc(capacity, sizeof(node_t*));
  symbolTable->addr_table = calloc(65536, sizeof(char*));
  debug("%d = end of function capacity", symbolTable->capacity);
  return symbolTable;
}

/** @todo implement this function */
void symbol_term (sym_table_t* symTab) {
  debug("testing terminate");
  symbol_reset(symTab);
  free(symTab->hash_table);
  free(symTab->addr_table);
  free(symTab);
}

/** @todo implement this function */
void symbol_reset(sym_table_t* symTab) {
  debug("testing reset");
  node_t* curr = symTab->hash_table[0];
  node_t* temp = curr;
  for (int i = 0; i < symTab->capacity; i++) {
      curr = symTab->hash_table[i];
      while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp->symbol.name);
        free(temp);
      }
  }
  free(curr);
}

/** @todo implement this function for Part A */
int symbol_add (sym_table_t* symTab, const char* name, int addr) {
// hash_table[*index] = head of linked list at each index in hash table
  int actualHash = symbol_hash(name);
  debug("%d = actual hash value", actualHash); 
  int actualIndex = actualHash % symTab->capacity;
  debug("%d = actual index value", actualIndex);
  int* hash = &actualHash;
  int* index = &actualIndex;
  debug("%d and %d = hash and index values", *hash, *index);

  if ((symTab->hash_table[*index]) == NULL) {
    node_t* newNode = calloc(sizeof(node_t), 1);  //create new node to be inserted
    debug("entered if stmnt where no symbols at current index");
    newNode->next = NULL;
    newNode->hash = *hash;
    debug("%d = hash value", newNode->hash);
    symbol_t newSymbol; // create new symbol
    newSymbol.name = strdup(name);
    debug("%s = name", newSymbol.name);
    newSymbol.addr = addr; // store addr
    debug("%d = address", newSymbol.addr);
    newNode->symbol = newSymbol; // insert symbol into new node
    symTab->hash_table[*index] = newNode; // insert new node at specified index
    symTab->size++; // increment size of symbol table
    symTab->addr_table[addr] = symTab->hash_table[*index]->symbol.name;  // update address table to point at the name
    debug("%s token at that address", symTab->addr_table[addr]);
    debug("%d = size of symbol table after add", symTab->size);
    debug("%s = current head of list at index. 1ST ADD", symTab->hash_table[*index]->symbol.name);
    debug("%d = current addr of head node at index", symTab->hash_table[*index]->symbol.addr);
    return 1;
  }
  else { 
    debug("%s = current head of list at index", symTab->hash_table[*index]->symbol.name);
    debug("%d = current addr of head node at index", symTab->hash_table[*index]->symbol.addr);
    debug("entered stmnt with symbols at current index");
    if (symbol_search(symTab, name, hash, index) == NULL) {
      debug("node w/ name does not exist, adding new one");
      node_t* newNode = calloc(sizeof(node_t),1);  //create new node to be inserted
      newNode->next = NULL;
      newNode->hash = *hash;
      debug("%d = hash value", *hash);
      symbol_t newSymbol; // create new symbol
      newSymbol.name = strdup(name);
      debug("%s = name", newSymbol.name);
      newSymbol.addr = addr;
      debug("%d = address", newSymbol.addr);
      newNode->symbol = newSymbol;
      newNode->next = symTab->hash_table[*index]; //reallocate head pointer to point at new node
      symTab->hash_table[*index] = newNode;
      symTab->addr_table[addr] = symTab->hash_table[*index]->symbol.name;  // update address table to point at the name
      symTab->size++;
      debug("%s token at that address", symTab->addr_table[addr]);
      debug("%d = size of symbol table after add", symTab->size);
      debug("%s = current head of list at index.", symTab->hash_table[*index]->symbol.name);
      return 1;
    }
  }
  return 0;
}

/** @todo implement this function for Part A*/
struct node* symbol_search (sym_table_t* symTab, const char* name, int* hash, int* index) {
  *hash = symbol_hash(name);
  debug("%d = hash value", *hash);
  debug("%d = capacity", symTab->capacity);
  *index = *hash % symTab->capacity;
  debug("%d = index value", *index);
  node_t* curr = symTab->hash_table[*index];
  debug("%s = curr", curr->symbol.name);
  char* temp = strdup(name);
  
  while (curr != NULL) { 
    debug("%s = name and %s = curr name to compare to already in linked list", temp, curr->symbol.name);
    if (compare_names(temp, curr->symbol.name) == 0) {
      debug("match found, returning original node with same name.");
      free(temp);
      return curr;
    }
    curr = curr->next;
  }
  free(temp);
  free(curr);
  return NULL;
}

/** @todo implement this function */
symbol_t* symbol_find_by_name (sym_table_t* symTab, const char* name) {
  int actualHash = symbol_hash(name);
  debug("%d = actual hash value", actualHash); 
  int actualIndex = actualHash % symTab->capacity;
  debug("%d = actual index value", actualIndex);
  int* hash = &actualHash;
  int* index = &actualIndex;
  debug("%d and %d = hash and index values", *hash, *index);
  struct node* temp = symbol_search(symTab, name, hash, index);
  symbol_t* returnSym = &temp->symbol;
  return returnSym;
  
}

/** @todo implement this function */
char* symbol_find_by_addr (sym_table_t* symTab, int addr) {
  return symTab->addr_table[addr];
}

/** @todo implement this function for Part A*/
void symbol_iterate (sym_table_t* symTab, iterate_fnc_t fnc, void* data) {
  node_t* curr = calloc(sizeof(node_t*),1);
  debug("testing iterate");
  for (int i = 0; i < symTab->capacity; i++) {
      curr = symTab->hash_table[i];
      while (curr != NULL) {
        (*fnc)(&(curr->symbol),data);
        curr = curr->next;
      }
  }
  free(curr);
}

/** @todo implement this function */
int symbol_size (sym_table_t* symTab) {
  return symTab->size;
}

/** @todo implement this function */
int compare_names (const void* vp1, const void* vp2) {
  const char* sym1 = vp1;
  const char* sym2 = vp2;
  debug("%s = first string", sym1);
  debug("%s = second string", sym2);
  debug("%d = return value", strcasecmp(sym1,sym2));
  return strcasecmp(sym1, sym2);
}

/** @todo implement this function */
int compare_addresses (const void* vp1, const void* vp2) {
  const int* sym1 = vp1;
  const int* sym2 = vp2;
  return sym1-sym2;
}

/** @todo implement this function */
symbol_t** symbol_order (sym_table_t* symTab, int order) {
  // will call qsort with either compare_names or compare_addresses
  symbol_t** returnArr = calloc(1, symbol_size(symTab));
  char str1[4];
  sprintf(str1, "%d", order);
  
  
  if (strcmp(str1,"HASH") == 0) {
    
    int smallestHash = symTab->hash_table[0]->hash;
    int intTemp = smallestHash;
    symbol_t** temp = NULL;
    for (int i = 0; i < symbol_size(symTab); i++) {
      returnArr[i] = &(symTab->hash_table[i]->symbol);
      for (int j = 0; j < sizeof(symTab->hash_table[i]); j++) {
        intTemp = symTab->hash_table[j]->hash;
        if (smallestHash > intTemp) {
          smallestHash = intTemp;
          temp = &returnArr[i];
          returnArr[i] = returnArr[j];
          returnArr[j] = *temp;
        }
      }
    }
  }
  else if (strcmp(str1,"ADDR") == 0) {
  
    int smallestAddr = symTab->hash_table[0]->symbol.addr;
    int intTemp = smallestAddr;
    symbol_t** temp = NULL;
    for (int i = 0; i < symbol_size(symTab); i++) {
      returnArr[i] = &(symTab->hash_table[i]->symbol);
      for (int j = 0; j < sizeof(symTab->hash_table[i]); j++) {
        intTemp = symTab->hash_table[j]->symbol.addr;
        if (smallestAddr > intTemp) {
          smallestAddr = intTemp;
          temp = &(returnArr[i]);
          returnArr[i]=returnArr[j];
          returnArr[j] = *temp;
        }
      }
    }   
  }
  else if (strcmp(str1,"NAME") == 0) {
    symbol_t** temp = NULL;
    for (int i = 0; i < symbol_size(symTab); i++) {
      returnArr[i] = &(symTab->hash_table[i]->symbol);
      for (int j = 1; j < sizeof(symTab->hash_table[i]); j++) {
        if (compare_names(returnArr[i], returnArr[j]) < 0) {
          temp = &(returnArr[i]);
          returnArr[i] = returnArr[j];
          returnArr[j] = *temp;
        }
      }
    }
  }
  else {
    printf("invalid input");
  }
  return returnArr;
}

