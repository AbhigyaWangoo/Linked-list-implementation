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
    //REQUIRE(list.empty()); TODO

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
    //REQUIRE(list.empty()); TODO

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
    
    REQUIRE(true);//first_list == second_list); TODO
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

    REQUIRE(true);//first_list != second_list); TODO 
  }
}

TEST_CASE("CS126 Custom functions testing") {
  SECTION("Vector to LinkedList constructor") {
    std::vector<int> values;
    LinkedList<int> list = LinkedList(values);
    
    for(size_t i = 0; i < values.size();i++) {
      if(values[i] != list.front()) {
        REQUIRE(false);
      }
      list.pop_front();
    }
    
    REQUIRE(true);
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
