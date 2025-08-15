#ifndef PROP_CP_HANDLER_H
#define PROP_CP_HANDLER_H

namespace PropCP {
    struct NoConfig {};

    template<typename T, typename Property, typename Config = NoConfig>
    struct PropertyHandler {
        static void handle(Config & /*command*/) = delete;
    };

    // Helper concept to check if a handler is callable for given T/Property/Config
    template<typename T, typename Property, typename Config>
    concept HasPropertyHandler = requires(Config &c) {
        { PropertyHandler<T, Property, Config>::handle(c) };
    };
}

#endif // PROP_CPO_HANDLER_H
