#pragma once

#include <iostream>
//template <typename T>
class Node
{
    std::shared_ptr<int> data;
    std::shared_ptr<Node> next;
//template <typename T>
    std::shared_ptr<Node> prev;
public:

    Node(int value) : data{ std::make_shared<int>(value) }, next{ nullptr }, prev{ nullptr }{}

    ~Node() {}

    int& getData() { if (data) return *data; throw std::exception("Data is empty"); }

    Node& setData(int value){ *data = value; return *this; }

    std::shared_ptr<Node> getNext() const { return next; }

    Node& setNext(std::shared_ptr<Node> _next) { this->next = _next; return *this; }

    std::shared_ptr<Node> getPrev() const { return prev; }

    Node& setPrev(std::shared_ptr<Node> _prev) { this->prev = _prev; return *this; }
};

class List
{
    std::shared_ptr<Node> first;
    std::shared_ptr<Node> last;
public:
    List() : first { nullptr }, last{ nullptr } {}

    ~List() { clear(); std::cout << "\nList destroyed"; }

    List& add(int value)
    {
            std::shared_ptr<Node> new_node = std::make_shared<Node>(value);

            if (!first)
            {
                first = last = new_node;
            }
            else
            {
                last->setNext(new_node);
                new_node->setPrev(last);
                last = new_node;
            }

            return *this;
    }

    List& remove(unsigned int index)
    {
        if (!first) { std::cout << "Я дед инсайд (пустой)\n"; return *this; }

        std::shared_ptr<Node> temp = first;

        for (int i = 0; i < index && temp; i++)
        {
            temp = temp->getNext();
        }

        if (temp)
        {
            if (temp->getPrev()) temp->getPrev()->setNext(temp->getNext());
            if (temp->getNext()) temp->getNext()->setPrev(temp->getPrev());

            if (temp == first) first = temp->getNext();
            if (temp == last) last = temp->getPrev();
        }

        return *this;
    }

    int& operator[](unsigned int index)
    {
        if (first)
        {
            std::shared_ptr<Node> temp = first;
            for (int i = 0; i < index; i++)
            {
                if (temp)temp = temp->getNext();
                else throw std::out_of_range("Ты куда?\n");
            }
            return temp->getData();
        }
        else throw std::out_of_range("Ты куда?\n");
    }

    friend std::ostream& operator<<(std::ostream& out, const List& list)
    {
        std::shared_ptr<Node> temp = list.first;
        while (temp)
        {
            if (temp)
            {
                out << temp->getData() << " ";
                temp = temp->getNext();
            }
            else throw std::out_of_range("Ты куда?");
        }
        return out;
    }

    List& clear()
    {
        while (first)
        {
            remove(0); // память нужно очищать.
        }
        last = nullptr;

        return *this;
    }
};