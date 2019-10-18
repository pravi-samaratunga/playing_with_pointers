#define QUESTION_1_RESPONSE 0
#define QUESTION_2_RESPONSE 0
#define QUESTION_3_RESPONSE 0
#define DLL_P_VAL "Blue"

#undef BREAK_THINGS
//#define BREAK_THINGS

// This file is a little bit different than the previous one.
// This is an implementation of a doubly linked list. You've probably seen something like it before.
// Here's a reference in english: https://www.tutorialspoint.com/data_structures_algorithms/linked_list_algorithms.htm

// Multiple choice quiz:

// Question 1: What does the pointer p in the DoublyLinkedList class represent?
// (1) A pointer to the ll_node object at the beginning of the DoublyLinkedList.
// (2) A pointer to an ll_node object somewhere in the DoublyLinkedList.
// (3) A pointer to the DoublyLinkedList class itself.

// Question 2: What does the ++ operator do here?
// (1) Increments the value of pointer p to the next byte.
// (2) Makes p point to the next node in the list.
// (3) Adds 1 to the value of the DoublyLinkedList object.

// Question 3: What does line 127 (end->next = start;) do? Uncomment line 7 to learn more.
// (1) Sets the initial pointer to refer to itself, so the beginning of the list is unreachable.
// (2) Creates a circular bidirectional linked list, so the last element of the list refers to the first one and vice versa.
// (3) Creates a circular linked list going forward, but a terminating linked list going backwards.

// Run `make 01_doubly_linked_list` to compile and run this program.

#include <iterator>
#include <string.h>
#include <iostream>

int points = INITIAL_POINTS;

struct ll_node
{
    const char* value;
    ll_node* prev {0};
    ll_node* next {0};
};

class DoublyLinkedList : public std::iterator<std::bidirectional_iterator_tag, const char*>
{
public:
    ll_node* p;

    // http://www.cplusplus.com/reference/iterator/iterator/
    DoublyLinkedList(const DoublyLinkedList& dll) : p(dll.p) {}
    DoublyLinkedList& operator--() {if (p->prev != nullptr) p = p->prev; return *this;}
    DoublyLinkedList operator--(int) {DoublyLinkedList tmp(*this); operator--(); return tmp;}
    DoublyLinkedList& operator++() {if (p->next != nullptr) p = p->next; return *this;}
    DoublyLinkedList operator++(int) {DoublyLinkedList tmp(*this); operator++(); return tmp;}
    bool operator==(const DoublyLinkedList& rhs) const {return strcmp(p->value, rhs.p->value) == 0;}
    bool operator!=(const DoublyLinkedList& rhs) const {return strcmp(p->value, rhs.p->value) != 0;}
    const char* operator*() {return (*p).value;}

    DoublyLinkedList(const char* x) : p(new ll_node)
    {
        p->value = x;
        p->next = new ll_node;
        p->next->prev = p;
        p->prev = new ll_node;
        p->prev->next = p;
    }


    void to_start() {
        while (p->prev != nullptr) {
            p = p->prev;
        }
        p = p->next;
    }


    void to_end() {
        while (p->next != nullptr) {
            p = p->next;
        }
        p = p->prev;
    }

    void insert (const char* x) 
    // insert the value after the current node
    {
        ll_node* new_node = new ll_node;
        new_node->value = x;

        if ((*p).next == nullptr) {
            p->next = new_node;
            new_node->prev = p;
        } else {
            ll_node* next = p->next;
            p->next = new_node;
            new_node->prev = p;
            new_node->next = next;
            next->prev = new_node;
        }
        p = new_node;
    }

    void display()
    {
        ll_node* tmp = p;
        this->to_start();
        while (p->next != nullptr) {
            std::cout << p->value << std::endl;
            p = p->next;
        }
        p = tmp; // reset back to the way it was before
    }

};

int main(int argc, char const *argv[])
{
    DoublyLinkedList dll("\x1B[31mRed\x1B[0m");
    ll_node* start = dll.p;
    dll.insert("\x1B[33mYellow\x1B[0m");
    dll.insert("\x1B[32mGreen\x1B[0m");
    dll.insert("\x1B[34mBlue\x1B[0m");
    dll.insert("\x1B[35mPurple\x1B[0m");
    ll_node* end = dll.p;
#ifdef BREAK_THINGS
    end->next = start;
#endif
    dll.to_start();
    for (DoublyLinkedList d(dll); d.p->next != nullptr; ++d)
    {
        std::cout << d.p->value << std::endl;
    }

    // DLL_P_VAL: What is the value of dll.p->value (without color codes)?
    // The answer is "Red", "Yellow", "Green", "Blue", or "Purple"
    // Put the answer in line 4 of this file.
    if (DLL_P_VAL == DLL_P_VAL_ANS) {
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "DLL_P_VAL is correct!" << std::endl;
        std::cout << dll.p->value << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        points++;
    }
    dll.to_end();
    for (DoublyLinkedList d(dll); d.p->prev != nullptr; --d)
    {
        std::cout << d.p->value << std::endl;
    }

    std::cout << "You got " << points << " points out of 4." << std::endl;
    return 0;
}