#ifndef PROPCP_FOOHANDLER_H
#define PROPCP_FOOHANDLER_H

#include <iostream>
#include "adapter-header.h"

template <HasFoo T>
struct PropertyHandler<T, FooProp, int> {
    static void handle(int& command) {
        std::cout << "Handling FooProp for type: " << typeid(T).name() << std::endl;
        // Example logic
    }
};

#endif // PROPCP_FOOHANDLER_H
