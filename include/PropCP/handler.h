#ifndef PROP_CP_HANDLER_H
#define PROP_CP_HANDLER_H

namespace PropCP {
    struct NoConfig {};

    struct DefaultOp {};

    template<typename T, typename Property, typename Config = NoConfig, typename Op = DefaultOp>
    struct PropertyHandler {
        static void handle(Config & /*command*/) = delete;
    };

    // Helper concept to check if a handler is callable for given T/Property/Config
    template<typename T, typename Property, typename Config, typename Op>
    concept HasPropertyHandler = requires(Config &c) {
        { PropertyHandler<T, Property, Config, Op>::handle(c) };
    };
}

#endif // PROP_CPO_HANDLER_H
