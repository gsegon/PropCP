#ifndef PROPCP_BARHANDLER_H
#define PROPCP_BARHANDLER_H

// prop-cp/user adapter include
#include "adapter-header.h"

// user includes
#include <iostream>
#include "MyConfig.h"

// Specialization for T/BarProp/NoConfig
template <HasBar T>
struct PropCP::PropertyHandler<T, BarProp> {
    static void handle(PropCP::NoConfig& config) {
        std::cout << "Handling BarProp for type: " << typeid(T).name() << std::endl;
        // Example logic
    }
};

// // Specialization for T/BarProp/MyConfig
// template <HasBar T>
// struct PropCP::PropertyHandler<T, BarProp, MyConfig> {
//     static void handle(const MyConfig & config) {
//         std::cout << "Handling BarProp for type: " << typeid(T).name() << " with MyConfig." << std::endl;
//         std::cout << "parameter_1 is: " << config.parameter_1 << std::endl;
//         std::cout << "parameter_2 is: " << config.parameter_2 << std::endl;
//         // Example logic
//     }
// };

#endif // PROPCP_BARHANDLER_H
