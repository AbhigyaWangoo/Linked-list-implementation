// Copyright (c) 2020 CS126SP20. All rights reserved.

#include <cassert>
#include <utility>
#include <vector>

#include "ll.h"

// TODO(you): Implement these methods.

namespace cs126linkedlist {

template <typename ElementType>
LinkedList<ElementType>::LinkedList() : head_(NULL) {}

template <typename ElementType>
LinkedList<ElementType>::LinkedList(const std::vector<ElementType>& values) {
  size_ = values.size();

  for (ElementType element : values) {
    push_back(element);
  }
}

// Copy constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(const LinkedList<ElementType>& source) {
  CopySource(source);
}

// Move constructor
template <typename ElementType>
LinkedList<ElementType>::LinkedList(LinkedList<ElementType>&& source) noexcept {
  head_ = source.head_;
  tail_ = source.tail_;
  size_ = source.size_;

  source.head_ = nullptr;
  source.tail_ = nullptr;
  source.size_ = 0;
}

// Destructor
template <typename ElementType>
LinkedList<ElementType>::~LinkedList() {
  clear();
}

// Copy assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    const LinkedList<ElementType>& source) {
  if (&source == this) {
    return *this;
  }

  clear();
  CopySource(source);

  return *this;
}

// Move assignment operator
template <typename ElementType>
LinkedList<ElementType>& LinkedList<ElementType>::operator=(
    LinkedList<ElementType>&& source) noexcept {
  if (&source == this) {
    return *this;
  }

  head_ = source.head_;
  tail_ = source.tail_;
  size_ = source.size_;

  source.head_ = nullptr;
  source.tail_ = nullptr;
  source.size_ = 0;
  
  return *this;
}

template <typename ElementType>
void LinkedList<ElementType>::push_front(const ElementType& value) {
  size_++;
  Node* new_node = CreateNode(value);

  if (head_ == NULL) {
    head_ = new_node;
    tail_ = head_;
    return;
  }

  Node* saved_node = head_;
  new_node->next_ = saved_node;
  head_ = new_node;
}

template <typename ElementType>
void LinkedList<ElementType>::push_back(const ElementType& value) {
  Node* new_node = CreateNode(value);
  tail_ = new_node;

  size_++;
  if (head_ == NULL) {
    head_ = new_node;
    return;
  }

  Node* node_ptr = head_;
  while (node_ptr->next_ != NULL) {
    node_ptr = node_ptr->next_;
  }

  node_ptr->next_ = new_node;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::front() const {
  return head_->node_value_;
}

template <typename ElementType>
ElementType LinkedList<ElementType>::back() const {
  return tail_->node_value_;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_front() {
  if (head_ == nullptr) {
    return;
  } else if (head_ == tail_) {
    delete head_;

    head_ = nullptr;
    tail_ = nullptr;

    size_ = 0;
    return;
  }

  size_--;
  Node* saved_head = head_;
  head_ = head_->next_;

  delete saved_head;
  saved_head = nullptr;
}

template <typename ElementType>
void LinkedList<ElementType>::pop_back() {
  if (tail_ == nullptr) {
    return;
  } else if (head_ == tail_) {
    delete tail_;

    head_ = nullptr;
    tail_ = nullptr;

    size_ = 0;
    return;
  }

  size_--;
  Node* current_node = head_;

  while (current_node->next_ != tail_) {
    current_node = current_node->next_;
  }

  delete current_node->next_;
  current_node->next_ = nullptr;

  tail_ = current_node;
}

template <typename ElementType>
size_t LinkedList<ElementType>::size() const {
  return size_;
}

template <typename ElementType>
bool LinkedList<ElementType>::empty() const {
  return size_ == 0;
}

template <typename ElementType>
void LinkedList<ElementType>::clear() {
  size_ = 0;

  if (head_ != nullptr) {
    while (size_ != 0) {
      pop_back();
    }
  }
}

template <typename ElementType>
std::ostream& operator<<(std::ostream& os,
                         const LinkedList<ElementType>& list) {
//  LinkedList<char>::iterator it = list.begin();
  
  
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveNth(size_t n) {
  if (n == size_) {
    pop_back();
  } else if (n == 0) {
    pop_front();
  } else if (n > size() || n < 0) {
    return;
  } else {
    size_--;

    Node* current_node = head_;
    Node* node_after;
    Node* node_after_next;

    size_t i = 0;
    while (i < size()) {
      if (i == n - 1) {
        node_after = current_node->next_;
        node_after_next = node_after->next_;

        current_node->next_ = node_after_next;
        delete node_after;
        node_after = nullptr;
      }

      i++;
      current_node = current_node->next_;
    }
  }
}

template <typename ElementType>
void LinkedList<ElementType>::RemoveOdd() {
  for (size_t i = 1; i < size(); i++) {
    RemoveNth(i);
  }
}

template <typename ElementType>
bool LinkedList<ElementType>::operator==(
    const LinkedList<ElementType>& rhs) const {
  if (size() == 0 && rhs.size() == 0) {
    return true;
  }

  Node* this_current_node = head_;
  Node* rhs_current_node = rhs.head_;

  while (this_current_node->next_ != nullptr ||
         rhs_current_node->next_ != nullptr) {
    if (this_current_node->node_value_ != rhs_current_node->node_value_) {
      return false;
    }
    this_current_node = this_current_node->next_;
    rhs_current_node = rhs_current_node->next_;
  }

  return true;
}

template <typename ElementType>
bool LinkedList<ElementType>::operator!=(
    const LinkedList<ElementType>& rhs) const {
  if (size() == 0 && rhs.size() == 0) {
    return false;
  }

  Node* this_current_node = head_;
  Node* rhs_current_node = rhs.head_;

  while (this_current_node != nullptr || rhs_current_node != nullptr) {
    if (this_current_node->node_value_ != rhs_current_node->node_value_) {
      return true;
    }
    this_current_node = this_current_node->next_;
    rhs_current_node = rhs_current_node->next_;
  }

  return false;
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator&
LinkedList<ElementType>::iterator::operator++() {
  if (current_ != nullptr) {
    current_ = current_->next_;
  }
  return *this;
}

template <typename ElementType>
ElementType& LinkedList<ElementType>::iterator::operator*() const {
  return current_->node_value_;
}

template <typename ElementType>
bool LinkedList<ElementType>::iterator::operator!=(
    const LinkedList<ElementType>::iterator& other) const {
  return current_ != other.current_;
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::begin() {
  return LinkedList<ElementType>::iterator(head_);
}

template <typename ElementType>
typename LinkedList<ElementType>::iterator LinkedList<ElementType>::end() {
  return LinkedList<ElementType>::iterator(nullptr);
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator&
LinkedList<ElementType>::const_iterator::operator++() {
  if (current_ != nullptr) {
    current_ = current_->next_;
  }
  return *this;
}

template <typename ElementType>
const ElementType& LinkedList<ElementType>::const_iterator::operator*() const {
  return current_->node_value_;
}

template <typename ElementType>
bool LinkedList<ElementType>::const_iterator::operator!=(
    const LinkedList<ElementType>::const_iterator& other) const {
  return current_ != other.current_;
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator
LinkedList<ElementType>::begin() const {
  return LinkedList<ElementType>::const_iterator(head_);
}

template <typename ElementType>
typename LinkedList<ElementType>::const_iterator LinkedList<ElementType>::end()
    const {
  return LinkedList<ElementType>::const_iterator(nullptr);
}
template <typename ElementType>

typename LinkedList<ElementType>::Node* LinkedList<ElementType>::CreateNode(
    const ElementType& elementType) {
  Node* node = new Node();
  node->node_value_ = elementType;
  node->next_ = nullptr;

  return node;
}
template <typename ElementType>
void LinkedList<ElementType>::CopySource(
    const LinkedList<ElementType>& source) {
  if (source.head_ == nullptr) {
    return;
  }

  for (const_iterator iterator = source.begin(); iterator != source.end();
       ++iterator) {
    push_back(*iterator);
  }
}

}  // namespace cs126linkedlist
