# PropCP
A lightweight C++20, compile-time property-driven dispatch framework. 
PropCP lets you associate “properties” (tags) with a type and automatically 
run a sequence of property-specific handlers against a config — at compile time, with zero runtime overhead.

#### 1. Associating properties with types
A typical use case is to tag a type with `SomeProperty` depending on if it satisfies a concept, which might for example 
be a condition that the type provides a function `some_function()` returning a specific type `SpecificType` and the 
type is derived from a `BaseType`.

```C++
  // User code
  template <typename T>
  concept HasSomeProperty =
    requires(T item) {
    {item.some_function()} -> std::same_as<SpecificType>;}
    && std::is_base_of_v<BaseType, T>;
  
  // User code
  template <typename T>
  struct SomeProperty {};  // Tag representing the "SomeProperty" property
```

A type is tagged with one or more properties and collected into a `PropertyList`. Tagging doesn't have to be conditional, 
one can simply construct a property and tag a type with it.

```C++
  // User code
  template <typename T>
  struct PropertyList {
      using type = PropCP::TypeList<
          std::conditional_t<HasSomeProperty<T>, SomeProperty, void>,                   // Property 1
          std::conditional_t<HasSomeOtherProperty<T>, SomeOtherProperty, void>,         // Property 2
          SimpleNonConditionalProperty                                                  // Property 3
          ...                                                                           // ...
      >;
  };
```
`void`s are removed from `PropertyList` and the list is flattened.

```C++
// User code
  template<typename T>
  struct TypeProperties {
      using Raw = typename PropertyList<T>::type;
      using NoVoids = typename PropCP::RemoveVoids<Raw>::type;
      using Properties = typename PropCP::FlattenList<NoVoids>::type;
  };
```
The user has access to a list of all properties associated with a type `T` through `TypeProperties<T>::Properties`

#### 2. Property Handlers and Dispatch
Once a list of properties for a type `T` is available it can be used to invoke operations. For each `Property` in the list a corresponding _handler_ function can be associated with it. Handlers are implemented by specializing `PropertyHandler` for wanted combinations of T/Property/Config. `Config` is added as an extra specialization type to serve as a mechanism for passing arguments to handlers.

```C++
    template<typename T, typename Property, typename Config = NoConfig>
    struct PropertyHandler {
        static void handle(Config & /*command*/) = delete;
    };
```
For example, a simplistic handler for T(satisfying HasSomeProperty)/SomeProperty/NoConfig is implemated as:
```C++
  // User code
  // Specialization for T/SomeProperty/NoConfig
  template <HasSomeProperty T>
  struct PropCP::PropertyHandler<T, SomeProperty> {
      static void handle(PropCP::NoConfig& config) {
          std::cout << "Handling SomeProperty for type: " << typeid(T).name() << std::endl;
          // handler logic ...
      }
  };
```
The Config type is not written out explicitly as the default is `NoConfig`. Another example with but with a custom 
non-default Config type:
```C++
template <typename  T>
struct PropCP::PropertyHandler<T, SomeOtherProp, MyConfig> {
    static void handle(const MyConfig & config) {
        std::cout << "Handling SomeOtherProp for type: " << typeid(T).name() << " with MyConfig." << std::endl;
        // Example logic
        std::cout << "parameter_1 is: " << config.parameter_1 << std::endl;
        std::cout << "parameter_2 is: " << config.parameter_2 << std::endl;
    }
};
```
Note that in this example the template parameter is not constrained with a concept such as `HasSomeOtherProperty`, 
as we didn't construct it, so it accepts any type.

Finally, to invoke performing operations implemented by handlers `DispatchProperties` is used
```C++
  // User code
  struct MyConfig {
    int parameter_1 = 3;
    double parameter_2 = 3.14;
  };
  using Properties = typename TypeProperties<T>::Properties;
  PropCP::DispatchProperties<T, Properties, Config>::dispatch(config);
```
Handlers are called in order.

See [ExampleCmd](examples/ExampleCmds) for a more detailed application example.


## Features
- Compile-time property pipelines: build ordered lists of properties per type.
- Static safety: missing handlers are diagnosed at compile time.
- Zero-overhead: no virtual dispatch or RTTI; templates and concepts only.
## When to use
- Capability-based pipelines (run steps only for features a type supports).
- High-performance paths where dynamic polymorphism is too costly.
- Compile-time feature flags and product variants.
- Deterministic, ordered processing (serialization, validation, device features).

