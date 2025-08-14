#ifndef PROPCP_BARHANDLER_H
#define PROPCP_BARHANDLER_H

#include <iostream>
#include "adapter-header.h"

template <HasBar T>
struct PropertyHandler<T, BarProp, int> {
    static void handle(int& command) {
        std::cout << "Handling BarProp for type: " << typeid(T).name() << std::endl;
        // Example logic
    }
};

#endif // PROPCP_BARHANDLER_H
