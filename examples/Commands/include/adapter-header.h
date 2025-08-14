#ifndef PROPCP_MYTYPEPROPERTIES_H
#define PROPCP_MYTYPEPROPERTIES_H

#include <PropCP/propcp.h>
#include <type_traits> // conditional_t

// Concepts
template <typename T>
concept HasFoo = true;

template <typename T>
concept HasBar = false;

// Property tags
struct FooProp {};

struct BarProp {};


// User specialization point:
// Specialize PropertyList<T> and set 'using type = TypeList<...>;' with your raw properties.
template <typename T>
struct PropertyList {
    using type = PropCP::TypeList<
        std::conditional_t<HasFoo<T>, FooProp, void>,
        std::conditional_t<HasBar<T>, BarProp, void>
    >;
};

// Public facade: derive final Properties from PropertyList<T>, removing voids and flattening.
template<typename T>
struct TypeProperties {
    using Raw = typename PropertyList<T>::type;
    using NoVoids = typename PropCP::RemoveVoids<Raw>::type;
    using Properties = typename PropCP::FlattenList<NoVoids>::type;
};


#endif // PROPCP_MYTYPEPROPERTIES_H
