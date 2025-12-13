#ifndef PROPCP_MYTYPEPROPERTIES_H
#define PROPCP_MYTYPEPROPERTIES_H

// prop-cp includes
#include <PropCP/propcp.h>

// User includes
#include <type_traits> // conditional_t

// Concepts
template<typename T>
concept HasFoo = true;

template<typename T>
concept HasBar = false;

// Property tags
struct FooProp {};

struct BarProp {};

struct SomeOtherProp {};

// User specialization point:
// Specialize PropertyList<T> and set 'using type = TypeList<...>;' with your raw properties.
template<typename T>
struct PropertyList {
    using type = PropCP::TypeList<
            std::conditional_t<HasFoo<T>, FooProp, void>, // Add property FooBar based on the HasFoo condition.
            std::conditional_t<HasBar<T>, BarProp, void>, // Add property HasBar based on the HasBar condition.
            SomeOtherProp // Add property SomeOtherProp, without conditional check.
            >;
};

// User customization point:
// Derive final Properties from PropertyList<T>, removing voids and flattening. Usually no need to modify.
template<typename T>
struct TypeProperties {
    using Raw = typename PropertyList<T>::type;
    using NoVoids = typename PropCP::RemoveVoids<Raw>::type;
    using Properties = typename PropCP::FlattenList<NoVoids>::type;
};


#endif // PROPCP_MYTYPEPROPERTIES_H
