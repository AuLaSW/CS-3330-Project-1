// Austin Swanlaw
#include "../include/Node.hpp"

template<typename E>
Node<E>::Node() {
    this->next = nullptr;
    this->prev = nullptr;
    this->element = nullptr;
}
// create a node with an eomployee
template<typename E>
Node<E>::Node(Employee& employee) : element(&employee) {
    this->next = nullptr;
    this->prev = nullptr;
}

// create a node with an employee, next node, and previous node
template<typename E>
Node<E>::Node(Employee& employee, Node<E>& next, Node<E>& prev) : 
    element(&employee), next(&next), prev(&prev) {
}

