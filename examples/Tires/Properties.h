#ifndef PROPCP_PROPERTIES_H
#define PROPCP_PROPERTIES_H

#include <concepts>
#include "ExternalTypes.h"
#include "PropCP/typelist.h"

// Properties
struct MyProp1 {};

struct MyProp2 {};

struct MyProp3 {};

struct MyProp4 {};

// A list to store properties
template<typename... Properties>
struct PropList {};

// Property list for T
template <typename T>
struct PropertyList {
    using type = PropList<MyProp1, MyProp2, MyProp3, MyProp4>;
};

template<typename T, typename PropertyList>
struct DispatchProperties;

// Base case: Empty property list
template<typename T>
struct DispatchProperties<T, PropList<>> {
    static void dispatch() {
        std::cout << "Empty typelist" << typeid(T).name() << std::endl;
    }
};


struct MyType {};


// PropCP::TypeList<int, double>;

struct WheelsProp {};  // Represents wheels property

struct MassProp {};   // Represents mass property

// Concepts
template<typename T>
concept HasWheels = std::is_base_of_v<ExLib1::Car, T> || std::is_same_v<T, ExLib2::TriCycle>;

template<typename T>
concept HasMass =
    requires(T item) {{item.mass()} -> std::convertible_to<double>; } ||
    requires(T item){{item.mass} -> std::convertible_to<double>;};

template<typename T>
concept HasWheelsAndMass = HasWheels<T> && HasMass<T>;


#endif // PROPCP_PROPERTIES_H
