#ifndef TAGDISPATCHEXAMPLE_CUSTOM_H
#define TAGDISPATCHEXAMPLE_CUSTOM_H

#include "framework.h"

// Properties
struct MyProp1 {};

struct MyProp2 {};

struct MyProp3 {};

struct MyProp4 {};

// Custom type
struct MyType {};

// Full specialization of Handler
template<>
struct Handler<MyType, MyProp1> {
    static void handle() {
        std::cout << "Full specialization for"
                     " MyType/MyProp1 combination"
                  << std::endl;
    }
};

// Partial specialization of Handler
template<typename T>
struct Handler<T, MyProp1> {
    static void handle() {
        std::cout << "Partial specialization for"
                     " T/MyProp1 combination"
                  << std::endl;
    }
};


#endif // TAGDISPATCHEXAMPLE_CUSTOM_H
