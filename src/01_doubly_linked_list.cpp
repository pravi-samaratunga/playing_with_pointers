#undef BREAK_THINGS

#include <iterator>
#include <string.h>
#include <iostream>

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
    dll.to_end();
    for (DoublyLinkedList d(dll); d.p->prev != nullptr; --d)
    {
        std::cout << d.p->value << std::endl;
    }

    return 0;
}