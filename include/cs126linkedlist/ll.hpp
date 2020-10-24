// Copyright (c) 2020 CS126SP20. All rights reserved.

#include "ll.h"

#include <cassert>
#include <utility>
#include <vector>

// TODO(you): Implement these methods.

namespace cs126linkedlist {

template <typename ElementType>
LinkedList<ElementType>::LinkedList() : head_(NULL) {}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {}

// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {

}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {}

// Move assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  Node *new_node = CreateNode(value);

  if (head_ == NULL) {
    head_ = new_node;
    return;
  }
  
  Node *saved_node = head_;
  new_node->next_ = saved_node;
  head_ = new_node;
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
  Node *new_node = CreateNode(value);
  
  if (head_ == NULL) {
    head_ = new_node;
    return;
  }
  
  Node *node_ptr = head_;
  while(node_ptr->next_ != NULL) { 
    node_ptr = node_ptr->next_;
  }
  
  node_ptr->next_ = new_node;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {}

template <typename ElementType>
size_t LinkedList<ElementType>::size() const {}

template <typename ElementType>
bool LinkedList<ElementType>::empty() const {}

template <typename ElementType>
void LinkedList<ElementType>::clear() {}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(size_t n) {}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
bool LinkedList<ElementType>::operator!=(
    const LinkedList<ElementType>& rhs) const {}

template <typename ElementType>
typename LinkedList<ElementType>::iterator& LinkedList<ElementType>::iterator::
operator++() {
  if(current_ != NULL) {
    current_ = current_->next_;  
  }
  
  return *this;
}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const LinkedList<ElementType>::iterator& other) const {
  return current_
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
  return LinkedList<ElementType>::iterator(head_);
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const LinkedList<ElementType>::const_iterator& other) const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {}
template <typename ElementType>

typename LinkedList<ElementType>::Node* LinkedList<ElementType>::CreateNode(const ElementType& elementType) {
  Node *node = new Node();
  node->node_value_ = elementType;
  node->next_ = nullptr;
  
  return node;
}

}  // namespace cs126linkedlist
