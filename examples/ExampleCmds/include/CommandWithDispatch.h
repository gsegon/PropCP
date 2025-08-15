#ifndef PROPCP_COMMANDWITHDISPATCH_H
#define PROPCP_COMMANDWITHDISPATCH_H

// user includes
#include "Command.h"

// user/prop-cp includes
#include "FooPropertyHandler.h"
#include "BarPropertyHandler.h"
#include "SomeOtherPropertyHandler.h"


template<typename T, typename Config=PropCP::NoConfig>
class CommandWithDispatch : public Command {

public:

    CommandWithDispatch(Config config = Config()) : config(config) {}

    void execute() override {
        // Dispatch all applicable properties
        using Properties = typename TypeProperties<T>::Properties;
        PropCP::DispatchProperties<T, Properties, Config>::dispatch(getConfig());
    }

    virtual Config& getConfig() {
        return config;
    }

protected:
    Config config;


};

#endif // PROPCP_COMMANDWITHDISPATCH_H
