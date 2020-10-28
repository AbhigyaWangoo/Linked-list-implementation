// Copyright (c) 2020 [Your Name]. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include <cs126linkedlist/ll.h>


using cs126linkedlist::LinkedList;

// Read more on SECTIONs here:
// `https://github.com/catchorg/Catch2/tree/master/docs`
// in the "Test Cases and Sections" file.
TEST_CASE("Push functionality") {
  SECTION("Push Back") {
    LinkedList<int> list;

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty()); 

    SECTION("Push back one element") {
      list.push_back(1);

      REQUIRE(list.size() == 1);
    }

    SECTION("Push back two elements") {
      list.push_back(-1);
      list.push_back(10000);

      REQUIRE(list.size() == 2);
    }

    SECTION("Push back three elements") {
      list.push_back(-1);
      list.push_back(2);
      list.push_back(69420);

      REQUIRE(list.size() == 3);
    }
  }

  SECTION("Push Front") {
    LinkedList<int> list;

    REQUIRE(list.size() == 0);
    REQUIRE(list.empty());

    SECTION("Push forward one element") {
      list.push_front(1);

      REQUIRE(list.size() == 1);
    }

    SECTION("Push forward two elements") {
      list.push_front(-1);
      list.push_front(10000);
      
      bool passing_condition = list.size() == 2 && list.front() == 10000;
      REQUIRE(passing_condition);
    }

    SECTION("Push forward three elements") {
      list.push_front(1);
      list.push_front(-2);
      list.push_back(3);

      bool passing_condition = list.size() == 3 && list.front() == -2;
      REQUIRE(passing_condition);
    }
    
    SECTION("Push Forward non-int elements") {
      LinkedList<char> char_list;
      
      char_list.push_front('a');
      char_list.push_front('b');
      char_list.push_front('c');

      bool passing_condition = char_list.size() == 3 && char_list.front() == 'c';
      REQUIRE(passing_condition);
    }
  }
}

TEST_CASE("Pop functionality") {
  LinkedList<int> list;
  
  SECTION("Pop back values") {
    SECTION("Pop back from empty list") {
      list.pop_back();
      REQUIRE(list.size() == 0);
    }

    SECTION("Pop back 1 value") {
      list.push_front(1);
      list.pop_back();
      REQUIRE(list.size() == 0);
    }
     
    SECTION("Pop back 2 values") {
      list.push_back(1);
      list.push_front(2);
      list.pop_back();
      list.pop_back();
      REQUIRE(list.size() == 0);
    }

    SECTION("Pop front values") {
      SECTION("Pop front from empty list") {
        list.pop_front();
        REQUIRE(list.size() == 0);
      }

      SECTION("Pop front 1 value") {
        list.push_front(1);
        list.pop_front();
        
        REQUIRE(list.size() == 0);
      }

      SECTION("Pop front 2 values") {
        list.push_back(1);
        list.push_front(2);
        list.pop_front();
        list.pop_front();
        
        REQUIRE(list.size() == 0);
      }
      SECTION("Pop back non int values") {
        LinkedList<char> list_char;

        list_char.push_back('a');
        list_char.push_front('b');
        list_char.pop_front();
        list_char.pop_front();

        REQUIRE(list_char.size() == 0);
      }
    }
  }
}

TEST_CASE("Miscellaneous container functionality") { // TODO more of these
  LinkedList<int> list;

  SECTION("Check if LinkedList is empty") {
    REQUIRE(list.empty());
    
    SECTION("Check if manipulated LinkedList is empty") {
      list.push_back(2);
      list.push_back(3);
      list.push_back(4);
      list.pop_back();
      list.pop_back();
      list.pop_back();
      
      REQUIRE(list.empty());
    }
  }
  
  SECTION("Check Size") {
    list.push_back(1);
    list.push_back(1);
    list.push_back(1);
    list.push_back(1);
    
    REQUIRE(list.size() == 4);
  }
  
  SECTION("Clear LinkedList") {
    list.push_back(1);
    list.push_back(1);
    list.clear();

    REQUIRE(list.size() == 0);
  }

  SECTION("Clear Empty LinkedList") {
    list.clear();

    REQUIRE(list.size() == 0);
  }

  SECTION("Access front and end value") {
    list.push_front(1);
    list.push_back(2);
    list.push_front(3);
    
    SECTION("Front value") { 
      REQUIRE(list.front() == 3); 
    }
    
    SECTION("Back value") {
      REQUIRE(list.back() == 2);
    }
  }

  SECTION("Check if LinkedLists are equal") {
    LinkedList<int> first_list;
    LinkedList<int> second_list;
    
    first_list.push_back(1);
    first_list.push_back(2);
    first_list.push_back(3);
    
    second_list.push_back(1);
    second_list.push_back(2);
    second_list.push_back(3);
    
    bool condition = first_list == second_list;
    REQUIRE(condition); 
  }

  SECTION("Check if LinkedLists are not equal") {
    LinkedList<int> first_list;
    LinkedList<int> second_list;

    first_list.push_back(1);
    first_list.push_back(2);
    first_list.push_back(3);

    second_list.push_back(1);
    second_list.push_back(2);
    second_list.push_back(4);
  
    bool success = first_list != second_list;
    REQUIRE(success); 
  }
}

TEST_CASE("CS126 Custom functions testing") {
  SECTION("Vector to LinkedList constructor") {
    std::vector<int> values;
    
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    values.push_back(4);
    
    LinkedList<int> list = LinkedList(values);
    
    for(size_t i = 0; i < values.size();i++) {
      if(values[i] != list.front()) {
        REQUIRE(false);
      }
      list.pop_front();
    }
    
    REQUIRE(true);
  }
  
  SECTION("Empty Vector to LinkedList") {
    
  }
  
  SECTION("Remove nth node") {
    LinkedList<int> list;
    
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    
    list.RemoveNth(1);
    
    bool condition = list.front() == 1 && list.back() == 3 && list.size() == 2;
    REQUIRE(condition);
  }

  SECTION("Remove nonexistant node") {
    LinkedList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    list.RemoveNth(13);
    list.RemoveNth(-1);
    
    REQUIRE(list.size() == 3);
  }

  SECTION("Remove odd nodes") {
    LinkedList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    
    list.RemoveOdd();
    
    bool condition = list.front() == 0 && list.back() == 6 && list.size() == 4;
    REQUIRE(condition);
  }
}

TEST_CASE("Iterator functionality") {
  SECTION("Iterator") {
    LinkedList<int> list;
    bool success;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);

    LinkedList<int>::iterator it = list.begin();
    
    SECTION("Traverse list properly") {
      while(it != nullptr) {
        success = *it == list.front();
        list.pop_front();
        ++it;
      }
      
      REQUIRE(success);
    }

    SECTION("Traverse empty list properly") {
      success = list.size() == 0;
      
      while(it != nullptr) {
        success = *it == list.front();
        list.pop_front();
        ++it;
      }

      REQUIRE(success);
    }
    
  }
}

TEST_CASE("Big Five") {
  SECTION("Check Move Constructor") {
    cs126linkedlist::LinkedList<int> list_;

    list_.push_back(1);
    list_.push_back(2);
    list_.push_back(3);

    cs126linkedlist::LinkedList<int> list_2 = cs126linkedlist::LinkedList(std::move(list_));
    
    bool success = list_2.size() == 3 && list_.size() == 0;
    REQUIRE(success);
  }
  
  SECTION("Check Copy Constructor") {
    cs126linkedlist::LinkedList<int> list_;

    list_.push_back(1);
    list_.push_back(2);
    list_.push_back(3);

    cs126linkedlist::LinkedList<int> list_2 = cs126linkedlist::LinkedList(list_);

    bool success = (list_2.size() == 3) && (list_.size() == 3);
    REQUIRE(success);
  }
  
  SECTION("Check Move Assignment") {
    cs126linkedlist::LinkedList<int> list_;

    list_.push_back(1);
    list_.push_back(2);
    list_.push_back(3);

    cs126linkedlist::LinkedList<int> list_2;
    list_2 = std::move(list_);

    bool success = (list_2.size() == 3) && (list_.size() == 0);
    REQUIRE(success);
  }
  
  SECTION("Check Copy Assignment") {
    cs126linkedlist::LinkedList<int> list_;

    list_.push_back(1);
    list_.push_back(2);
    list_.push_back(3);

    cs126linkedlist::LinkedList<int> list_2;
    list_2 = list_;

    bool success = (list_2.size() == 3) && (list_.size() == 3);
    REQUIRE(success);
  }
}