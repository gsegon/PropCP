#include "Command.h"

#include <PropCP/propcp.h>

#include "FooPropertyHandler.h"
#include "BarPropertyHandler.h"

template<typename T>
class SomeCommand : public CommandWithDispatch<T, int> {

public:

    int& getConfig() override {
        return m_config;
    }

private:
    int m_config=1;;
};




int main(int argc, char* argv[]) {

    SomeCommand<double>  a;
    a.execute();

    return 0;
}
