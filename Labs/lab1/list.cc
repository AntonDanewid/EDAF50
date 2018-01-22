#include <iostream>
#include "list.h"

List::List() {
	first = NULL;
}

List::~List() {

    Node *next = first;
    while(next) {
        Node *die = next;
        next=next-> next;
        delete die;
    }

}

bool List::exists(int d) const {
	Node *temp = first;
	while(temp!= NULL) {
        if(temp-> value == d) {
            return true;
		}
        temp= temp->next;
	}
	return false;
}

int List::size() const {
	if(first != NULL) {

        Node *temp = first;
        int size = 0;
        while (temp != NULL) {
            temp = temp->next;
            size++;
        }
        return size;

    }
    return 0;
}

bool List::empty() const {
	if(first == NULL) {
		return true;
	}
	return false;
}

void List::insertFirst(int d) {
	if(first == NULL) {
		first = new Node(d, NULL);
	} else {
		Node *temp = new Node(d, first);
		first = temp;
	}

}

void List::remove(int d, DeleteFlag df) {

    if(first == NULL) {
        return;
    }
    if(first->next == NULL) {
        if(df == DeleteFlag::LESS) {
            if(first->value < d) {
                delete first;
                return;
            }
        } else if(df == DeleteFlag::EQUAL) {
            if(first->value == d) {
                delete first;
                return;
            }
        } else if(df == DeleteFlag::GREATER) {
            if(first -> value > d) {
                delete first;
                return;
            }
        }
    }

    Node * current = first;
    Node *nextNode = first->next;

	while(nextNode != NULL) {



        if(df == DeleteFlag::LESS) {
			if(nextNode->value < d) {
                current -> next = nextNode->next;
                delete nextNode;
                return;
			}
		} else if(df == DeleteFlag::EQUAL) {
            if (nextNode->value == d) {
                current->next = nextNode->next;
                delete nextNode;
                return;
            }
        }

		 else if(df ==DeleteFlag::GREATER) {
            if(nextNode->value > d) {

                current->next = nextNode->next;
                delete nextNode;
                return;
            }
		}
        current = nextNode;
        nextNode = nextNode->next;
	}

}

void List::print() const {
	Node *temp = first;
	while(temp!= NULL) {
		std::cout << temp->value << ", ";
		temp = temp->next;
	}
}
