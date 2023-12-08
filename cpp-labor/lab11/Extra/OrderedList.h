//
// Created by asus on 12/8/2023.
//

#ifndef EXTRA_ORDEREDLIST_H
#define EXTRA_ORDEREDLIST_H

#include <functional>
#include <iostream>
#include <list>

using namespace std;

template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
public:
    struct Node{
        T data;
        Node *next;
        Node(const T &d) : data(d), next(nullptr) {}
    };

    Node *head;
    friend class Iterator<T, LessComp, Equal>;

    OrderedList() : head(nullptr) {}
    ~OrderedList(){
        Node *current = head;
        while (current)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }


    void insert(const T &value)
    {
        Node *newNode = new Node(value);

        if (!head || LessComp()(value, head->data))
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node *current = head;
        while (current->next && LessComp()(current->next->data, value))
        {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(const T &value)
    {
        Node *current = head;
        Node *prev = nullptr;

        while (current && !Equal()(current->data, value))
        {
            prev = current;
            current = current->next;
        }

        if (!current)
            return; // Element not found

        if (!prev)
            head = current->next;
        else
            prev->next = current->next;

        delete current;
    }

    void listItems(std::ostream &os) const
    {
        Node *current = head;
        while (current)
        {
            os << current->data << " ";
            current = current->next;
        }
    }

    Iterator<T, LessComp, Equal> begin() const
    {
        return Iterator<T, LessComp, Equal>(*this, head);
    }

    Iterator<T, LessComp, Equal> end() const
    {
        return Iterator<T, LessComp, Equal>(*this, nullptr);
    }

    bool find(const T &value) const
    {
        Node *current = head;
        while (current)
        {
            if (Equal()(current->data, value))
                return true;
            current = current->next;
        }
        return false;
    }


};

template< class T, class LessComp, class Equal >
class Iterator{
public:
    OrderedList<T, LessComp, Equal>& list;
    typename OrderedList<T, LessComp, Equal>::Node* act;

    Iterator(const OrderedList<T, LessComp, Equal> &lst, typename OrderedList<T, LessComp, Equal>::Node *start)
            : list(const_cast<OrderedList<T, LessComp, Equal> &>(lst)), act(start) {}



    bool hasNext() const
    {
        return act != nullptr;
    }

    T next()
    {
        if (!hasNext())
            throw std::out_of_range("Iterator reached the end");

        T value = act->data;
        act = act->next;
        return value;
    }
};


#endif //EXTRA_ORDEREDLIST_H
