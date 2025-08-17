#ifndef PROP_CP_DISPATCH_H
#define PROP_CP_DISPATCH_H

#include <PropCP/handler.h>
#include <PropCP/typelist.h>

namespace PropCP {

    template<typename T, typename PropertyList, typename Config = NoConfig, typename Op = DefaultOp>
    struct DispatchProperties;

    // Base case: Empty property list
    template<typename T, typename Config, typename Op>
    struct DispatchProperties<T, TypeList<>, Config, Op> {
        static void dispatch(const Config &) {
        // Do nothing
        }
    };

    // Specialization for a Non-Empty TypeList: Recursive Case
    template<typename T, typename FirstProperty, typename... RestProperties, typename Config, typename Op>
    struct DispatchProperties<T, TypeList<FirstProperty, RestProperties...>, Config, Op> {
        static void dispatch(Config &config) {
            static_assert(HasPropertyHandler<T, FirstProperty, Config, Op>,
                          "Missing PropertyHandler specialization for this T/Property/Config/Op");


            // Handle the first property
            PropertyHandler<T, FirstProperty, Config, Op>::handle(config);

            // Recursively handle the rest
            DispatchProperties<T, TypeList<RestProperties...>, Config, Op>::dispatch(config);
        }
    };

} // namespace PropCP

#endif // MAGASAPP_DISPATCH_H
