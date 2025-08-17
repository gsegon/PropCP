#ifndef PROPCP_SOMEOTHERHANDLER_H
#define PROPCP_SOMEOTHERHANDLER_H

// prop-cp/user adapter include
#include "adapter-header.h"

// user includes
#include <iostream>
#include "MyConfig.h"

template <typename  T>
struct PropCP::PropertyHandler<T, SomeOtherProp> {
    static void handle(PropCP::NoConfig& config) {
        std::cout << "Handling SomeOtherProp for type: " << typeid(T).name() << " with NoConfig." << std::endl;
        // Example logic
    }
};

template <typename  T>
struct PropCP::PropertyHandler<T, SomeOtherProp, MyConfig, PropCP::DefaultOp> {
    static void handle(const MyConfig & config) {
        std::cout << "Handling SomeOtherProp for type: " << typeid(T).name() << " with MyConfig." << std::endl;
        // Example logic
        std::cout << "parameter_1 is: " << config.parameter_1 << std::endl;
        std::cout << "parameter_2 is: " << config.parameter_2 << std::endl;
    }
};


#endif // PROPCP_FOOHANDLER_H
