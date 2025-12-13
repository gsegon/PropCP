
#include "CommandWithDispatch.h"

int main(int argc, char *argv[]) {

    // Example with default NoConfig
    CommandWithDispatch<double> a;
    a.execute();

    // Example with MyConfig
    MyConfig someConfig{2, 1.23456789};
    CommandWithDispatch<double, MyConfig> b(someConfig);
    b.execute();

    return 0;
}
