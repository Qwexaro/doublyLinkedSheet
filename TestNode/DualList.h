#pragma once

#include <iostream>

class Node
{
    std::shared_ptr<int> data;
    std::shared_ptr<Node> next;
    std::shared_ptr<Node> prev;
public:

    Node(int value);

    ~Node();

    int& getData();
    
    Node& setData(int value);

    std::shared_ptr<Node> getNext() const;

    Node& setNext(std::shared_ptr<Node> _next);

    std::shared_ptr<Node> getPrev() const;

    Node& setPrev(std::shared_ptr<Node> _prev);
};

class List
{
    std::shared_ptr<Node> first;
    std::shared_ptr<Node> last;
public:
    List();

    ~List();

    List& add(int value);

    List& remove(unsigned int index);

    int& operator[](unsigned int index);

    friend std::ostream& operator<<(std::ostream& out, const List& list);

    List& clear();
};