#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include<ostream>
class LinkedList {

  public:
    bool insert(unsigned uiData);
    bool remove(unsigned &pData);
    LinkedList();	// default ctor for LinkedList
    void print();	// print out linked list
    friend std::ostream& operator<<(std::ostream& os, LinkedList &list);		// overload << operator to print linked list
    friend void clearMemory(LinkedList &list);		// method to clear memory in case linked list is not fully removed when exit is called
  private:
    struct Link {
	unsigned m_uiData;
	Link *m_pNext;
	Link(unsigned uiData, Link *pNext);	// ctor
	Link();		// default ctor
    } *m_pHead;
};

#endif /* LINKED_LIST_H */ 
