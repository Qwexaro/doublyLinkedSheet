#pragma once

#include <iostream>

template <typename T>
class Node
{
    std::shared_ptr<T> data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;
public:

    Node(T value) : data{ std::make_shared<T>(value) }, next{ nullptr }, prev{ nullptr } {}

    ~Node() {}

    T& getData() { if (data) return *data; throw std::exception("Data is empty"); }

    Node<T>& setData(T value) { *data = value; return *this; }

    std::shared_ptr<Node<T>> getNext() const { return next; }

    Node<T>& setNext(std::shared_ptr<Node<T>> _next) { this->next = _next; return *this; }

    std::shared_ptr<Node<T>> getPrev() const { return prev; }

    Node<T>& setPrev(std::shared_ptr<Node<T>> _prev) { this->prev = _prev; return *this; }
};

template <typename T>
class List
{
    std::shared_ptr<Node<T>> first;
    std::shared_ptr<Node<T>> last;
public:
    List() : first{ nullptr }, last{ nullptr } {}

    ~List() { clear(); std::cout << "\nList destroyed"; }

    List<T>& add(T value)
    {
        std::shared_ptr<Node<T>> new_node = std::make_shared<Node<T>>(value);

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

    List<T>& remove(unsigned int index)
    {
        if (!first) { std::cout << "Я дед инсайд (пустой)\n"; return *this; }

        std::shared_ptr<Node<T>> temp = first;

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

    T& operator[](unsigned int index)
    {
        if (first)
        {
            std::shared_ptr<Node<T>> temp = first;
            for (int i = 0; i < index; i++)
            {
                if (temp)temp = temp->getNext();
                else throw std::out_of_range("Ты куда?\n");
            }
            return temp->getData();
        }
        else throw std::out_of_range("Ты куда ?\n");
    }

    friend std::ostream& operator<<(std::ostream& out, const List<T>& list)
    {
        std::shared_ptr<Node<T>> temp = list.first;
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

    List<T>& clear()
    {
        while (first)
        {
            remove(0); // память надо очищать.
        }
        last = nullptr;

        return *this;
    }
};