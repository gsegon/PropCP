#ifndef COMMAND_H
#define COMMAND_H

#include <PropCP/propcp.h>
#include "adapter-header.h"

class Command {

public:
    virtual void execute() = 0;
    virtual ~Command() = default;
};

template<typename T, typename Config>
class CommandWithDispatch : public Command {

public:
    void execute() override {
        // Dispatch all applicable properties
        using Properties = typename TypeProperties<T>::Properties;
        PropCP::DispatchProperties<T, Properties, Config>::dispatch(getConfig());
    }

    virtual Config &getConfig() = 0;
};

#endif // COMMAND_H
