#ifndef PROP_CP_DISPATCH_H
#define PROP_CP_DISPATCH_H

#include <PropCP/handler.h>
#include <PropCP/typelist.h>

namespace PropCP {

    template<typename T, typename PropertyList, typename Config>
    struct DispatchProperties;

    // Base case: Empty property list
    template<typename T, typename Config>
    struct DispatchProperties<T, TypeList<>, Config> {
        static void dispatch(const Config &) {
        // Do nothing
        }
    };

    // Specialization for a Non-Empty TypeList: Recursive Case
    template<typename T, typename FirstProperty, typename... RestProperties, typename Config>
    struct DispatchProperties<T, TypeList<FirstProperty, RestProperties...>, Config> {
        static void dispatch(Config &config) {
            static_assert(HasPropertyHandler<T, FirstProperty, Config>,
                          "Missing PropertyHandler specialization for this T/Property/Config");


            // Handle the first property
            PropertyHandler<T, FirstProperty, Config>::handle(config);

            // Recursively handle the rest
            DispatchProperties<T, TypeList<RestProperties...>, Config>::dispatch(config);
        }
    };

} // namespace PropCP

#endif // MAGASAPP_DISPATCH_H
