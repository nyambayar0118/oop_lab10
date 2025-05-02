#ifndef LIST_H
#define LIST_H

#include "lib.h"

template <typename T>
class linkedList
{
private:
    struct Node
    {
        T data;
        Node *pre;
        Node *next;
        Node(const T &t) : data(t), pre(nullptr), next(nullptr) {}
    };

    Node *head;
    Node *tail;
    int len;

public:
    linkedList() : head(nullptr), tail(nullptr), len(0) {};
    ~linkedList()
    {
        Node *current = head;
        while (current)
        {
            Node *deletingNode = current;
            current = current->next;
            delete deletingNode;
        }
    };

    void add(const T &t)
    {
        Node *newNode = new Node(t);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->pre = tail;
            tail = newNode;
        }
        len++;
    };

    void insert(const T &t, int index)
    {
        if (index < 0 || index > len)

        {
            throw std::out_of_range("Index buruu");
        }

        Node *newNode = new Node(t);

        if (index == 0)
        {
            newNode->next = head;
            if (head)
                head->pre = newNode;
            head = newNode;
            if (!tail)
                tail = head;
        }
        else if (index == len)
        {
            add(t);
            delete newNode;
            return;
        }
        else
        {
            Node *current = head;
            for (int i = 0; i < index; ++i)
                current = current->next;

            newNode->next = current;
            newNode->pre = current->pre;
            current->pre->next = newNode;
            current->pre = newNode;
        }
        len++;
    };

    T get(int index)
    {
        if (index < 0 || index >= len)
        {
            throw std::out_of_range("Index buruu");
        }

        Node *current = head;
        for (int i = 0; i < index; ++i)
            current = current->next;

        return current->data;
    };

    void deleteL(int index)
    {
        if (index < 0 || index >= len)
        {
            throw std::out_of_range("Index out of bounds");
        }

        Node* deletingNode;
        if (index == 0)
        {
            deletingNode = head;
            head = head->next;
            if (head)
                head->pre = nullptr;
            if (deletingNode == tail)
                tail = nullptr;
        }
        else if (index == len - 1)
        {
            deletingNode = tail;
            tail = tail->pre;
            if (tail)
                tail->next = nullptr;
            if (deletingNode == head)
                head = nullptr;
        }
        else
        {
            deletingNode = head;
            for (int i = 0; i < index; ++i)
                deletingNode = deletingNode->next;

            deletingNode->pre->next = deletingNode->next;
            deletingNode->next->pre = deletingNode->pre;
        }

        delete deletingNode;
        len--;
    };
    
    int length() {
        return len;
    };
};

#endif