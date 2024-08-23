#ifndef STACK_H
#define STACK_H

#include <string>

class Stack {
public:
    Stack();
    ~Stack();
    void push(const std::string& item);
    std::string pop();
    std::string peek() const;
    bool isFull() const;
    bool isEmpty() const;

private:
    struct Node {
        std::string value;
        Node* next;
    };

    Node* head;
    int top;
    static const int maxSize = 100;
};

#endif // STACK_H