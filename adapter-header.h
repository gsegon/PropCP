#ifndef PROP_CP_ADAPTER_HEADER_H
#define PROP_CP_ADAPTER_HEADER_H

#include <PropCP/propcp.h>

// User specialization point:
// Specialize PropertyList<T> and set 'using type = TypeList<...>;' with your raw properties.
template<typename T>
struct PropertyList {
    using type = PropCP::TypeList<>;
};

// Public facade: derive final Properties from PropertyList<T>, removing voids and flattening.
template<typename T>
struct TypeProperties {
    using Raw = typename PropertyList<T>::type;
    using NoVoids = typename PropCP::RemoveVoids<Raw>::type;
    using Properties = typename PropCP::FlattenList<NoVoids>::type;
};


#endif // PROP_CP_ADAPTER_HEADER_H
