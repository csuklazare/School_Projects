#include "ll.h" 
#include <cstdlib>
#include<iostream>

using namespace std;

LinkedList::Link::Link(unsigned uiData, Link *pNext) : m_uiData(uiData), m_pNext(pNext) {}

LinkedList::LinkedList() : m_pHead(nullptr) {}

LinkedList::Link::Link() {}

bool LinkedList::insert(unsigned uiData) {
    Link* new_link = new Link;			// Get a new node.
    *new_link = Link(uiData, m_pHead);
    m_pHead = new_link;			// Put it at the head.
    return true;				// Indicate success.
}

bool LinkedList::remove(unsigned &pData) {
    if (!m_pHead)				// Empty list?
	return false;				// Indicate failure.

    Link *temp = m_pHead;			// Point to the first node.
    m_pHead = m_pHead->m_pNext;			// Remove the first node.
    pData = temp->m_uiData;			// Obtain first node’s data.
    delete(temp);				// delete the link temp to fix the memory leak created by insert
    return true;				// Indicate success.
}

void LinkedList::print() {
	if (m_pHead != nullptr) {
		Link* temp = m_pHead;
		cout << temp->m_uiData;
		while (temp->m_pNext != nullptr) {
			temp = temp->m_pNext;
			cout << " " << temp->m_uiData;
		}	
	}
	cout << "\n";
}

ostream& operator<<(ostream& os, LinkedList &list) {
	if (list.m_pHead != nullptr) {
		LinkedList::Link* temp = list.m_pHead;
		os << temp->m_uiData;
		while (temp->m_pNext != nullptr) {
			temp = temp->m_pNext;
			os << " " << temp->m_uiData;
		}
	}
	os << "\n";
	return os;
}

void clearMemory(LinkedList &list) {
	if (list.m_pHead != nullptr) {
		LinkedList::Link* temp = list.m_pHead;
		LinkedList::Link* next = temp;
		while (temp->m_pNext != nullptr) {
			if (temp->m_pNext == nullptr) {
				delete(temp);
				
			}
			else {
				next = temp->m_pNext;
				delete(temp);
				temp = next;
			}
		}
		delete(next);
	}
}
