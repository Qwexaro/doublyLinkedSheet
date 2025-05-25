#include "DualList.h"

Node::Node(int value) : data{ std::make_shared<int>(value) }, next{ nullptr }, prev{ nullptr }
{
    //std::cout << "n" << value << " created\n";
}

Node::~Node() 
{
    std::cout << "\nn" << *data << " destroyed\n";
}

int& Node::getData() 
{
    if (data) return *data; throw std::exception("Data is empty");
}

std::shared_ptr<Node> Node::getNext() const 
{
    return next;
}

std::shared_ptr<Node> Node::getPrev() const 
{
    return prev;
}

Node& Node::setNext(std::shared_ptr<Node> _next) 
{
    this->next = _next; return *this;
}

Node& Node::setPrev(std::shared_ptr<Node> _prev)
{
    this->prev = _prev; return *this;
}

Node& Node::setData(int value) 
{
    *data = value; return *this;
}

List::List() : first{ nullptr }, last{ nullptr } {}

List::~List() 
{
    clear(); std::cout << "List destroyed\n";
}

List& List::add(int value) 
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

List& List::remove(unsigned int index) 
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

int& List::operator[](unsigned int index)
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

std::ostream& operator<<(std::ostream& out, const List& list)
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

List& List::clear() 
{
    while (first)
    {
        remove(0); // память нужно очищать.
    }
    last = nullptr;

    return *this;
}