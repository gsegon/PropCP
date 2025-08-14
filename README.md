# PropCP
A lightweight C++20, compile-time property-driven dispatch framework. PropCP lets you associate “properties” (tags) with a type and automatically run a sequence of property-specific handlers against a config/command object—entirely at compile time, with zero runtime overhead.
## Features
- Compile-time property pipelines: build ordered lists of properties per type.
- Static safety: missing handlers are diagnosed at compile time.
- Zero-overhead: no virtual dispatch or RTTI; templates and concepts only.
## When to use
- Capability-based pipelines (run steps only for features a type supports).
- High-performance paths where dynamic polymorphism is too costly.
- Compile-time feature flags and product variants.
- Deterministic, ordered processing (serialization, validation, device features).

