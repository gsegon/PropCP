#ifndef TAGDISPATCHEXAMPLE_FRAMEWORK_H
#define TAGDISPATCHEXAMPLE_FRAMEWORK_H

#include <iostream>

// A list type for property storage
template<typename...>
struct TypeList {};

// Property list
template<typename T>
struct TagList {
    using Tags = TypeList<>;
};

// Handler
template<typename T, typename Property>
struct Handler {
    static void handle() {
        std::cout << "Doing something with type: " << typeid(T).name() << " for Property: " << typeid(Property).name()
                  << std::endl;
    }
};


// Dispatcher
template<typename T, typename TypeList>
struct DispatchProperties;


// Base case: Empty property list
template<typename T>
struct DispatchProperties<T, TypeList<>> {
    static void dispatch() { std::cout << "We reached the empty case." << std::endl; }
};


// Recursive case: split the list into First and Rest...
template<typename T, typename PropertyAtHead, typename... Rest>
struct DispatchProperties<T, TypeList<PropertyAtHead, Rest...>> {
    static void dispatch() {

        // 1) Handle the head element
        Handler<T, PropertyAtHead>::handle();

        // 2) Recurse on the tail
        DispatchProperties<T, TypeList<Rest...>>::dispatch();
    }
};

#endif // TAGDISPATCHEXAMPLE_FRAMEWORK_H
