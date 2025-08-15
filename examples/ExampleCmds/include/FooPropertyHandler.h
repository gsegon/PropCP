#ifndef PROPCP_FOOHANDLER_H
#define PROPCP_FOOHANDLER_H

// prop-cp/user adapter include
#include "adapter-header.h"

// user includes
#include <iostream>
#include "MyConfig.h"

template <HasFoo T>
struct PropCP::PropertyHandler<T, FooProp> {
    static void handle(PropCP::NoConfig& config) {
        std::cout << "Handling FooProp for type: " << typeid(T).name() << " with NoConfig." << std::endl;
        // Example logic
    }
};

// Specialization for T/FooProp/MyConfig
template <HasFoo T>
struct PropCP::PropertyHandler<T, FooProp, MyConfig> {
    static void handle(const MyConfig & config) {
        std::cout << "Handling FooProp for type: " << typeid(T).name() << " with MyConfig." << std::endl;
        std::cout << "parameter_1 is: " << config.parameter_1 << std::endl;
        std::cout << "parameter_2 is: " << config.parameter_2 << std::endl;
        // Example logic
    }
};

#endif // PROPCP_FOOHANDLER_H
