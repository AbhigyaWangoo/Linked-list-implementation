// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef CS126LINKEDLIST_LL_H_
#define CS126LINKEDLIST_LL_H_


#include <iostream>
#include <utility>
#include <vector>


namespace cs126linkedlist {

// Template for a linked list class.
template <typename ElementType>
class LinkedList {



  // Declare any struct, class, or anything you need to use here, as long as it
  // is private.

  // Here is a struct to get you started. You'll probably need more than this.
  struct Node { 
    ElementType node_value_;
    Node *next_;
  };




 // DO NOT CHANGE THE PUBLIC INTERFACE OF THIS CLASS!
 public:
  // Default Constructor.
  LinkedList();

  // Initialize from vector.
  explicit LinkedList(const std::vector<ElementType> &values);

  // --- Big 5 ---
  // Copy constructor.
  LinkedList(const LinkedList& source);
  // Move constructor.
  LinkedList(LinkedList&& source) noexcept;
  // Destructor.
  ~LinkedList();
  // Copy assignment operator.
  LinkedList<ElementType>& operator=(const LinkedList<ElementType>& source);
  // Move assignment operator.
  LinkedList<ElementType>& operator=(LinkedList<ElementType>&& source) noexcept;
  // --- End of Big 5 ---

  // --- Container Methods ---
  // Push value to front.
  void push_front(const ElementType& value);
  // Push value to back.
  void push_back(const ElementType& value);
  // Access the front value.
  ElementType front() const;
  // Access the back value.
  ElementType back() const;
  // Remove front element.
  void pop_front();
  // Remove back element.
  void pop_back();
  // Return number of elements.
  size_t size() const;
  // Check if empty.
  bool empty() const;
  // Clear the contents.
  void clear();
  // Equality operator.
  bool operator==(const LinkedList<ElementType>& rhs) const;
  // Inequality operator.
  bool operator!=(const LinkedList<ElementType>& rhs) const;
  // --- End Container Methods ---

  // --- CS126SP20 Custom Methods ---
  // Remove the Nth element from the front 0 indexed.
  void RemoveNth(size_t n);
  // remove the odd elements from the list 0 indexed.
  void RemoveOdd();
  // --- End CS126SP20 Custom Methods ---

  // iterator.
  class iterator : std::iterator<std::forward_iterator_tag, ElementType> {
    Node* current_;

   public:
     iterator() : current_(nullptr) {};
     iterator(Node* ptr) {current_ = ptr;};
     iterator& operator++();
     ElementType& operator*() const;
     bool operator!=(const iterator& other) const;
  };

  iterator begin();
  iterator end();

  // const_iterator.
  class const_iterator : std::iterator<std::forward_iterator_tag, ElementType> {
    const Node* current_;

   public:
     const_iterator() : current_(nullptr) {};
     const_iterator(Node* ptr) {current_ = ptr;};
     const_iterator& operator++();
     const ElementType& operator*() const;
     bool operator!=(const const_iterator& other) const;
  };

  const_iterator begin() const;
  const_iterator end() const;

  // --- End of Container Methods ---
 private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  size_t size_ = 0;
  
  /**
   * Creates a new Node with the specified element
   * 
   * @param elementType to instantiate new node with 
   * @return Node pointer to the new node
   */
  Node* CreateNode(const ElementType &elementType);
  
  /**
   * Copies linkedlist from source into this instance
   * 
   * @param source to copy from 
   */
  void CopySource(const LinkedList<ElementType> &source);
};

template<typename ElementType>
std::ostream& operator<<(std::ostream& os, const LinkedList<ElementType>& list);

}  // namespace cs126linkedlist

// Needed for template instantiation.
#include "ll.hpp"

#endif  // CS126LINKEDLIST_LL_H_
