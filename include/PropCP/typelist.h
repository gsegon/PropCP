#ifndef PROP_CP_TYPELIST_H
#define PROP_CP_TYPELIST_H

namespace PropCP {

    template<typename... Properties>
    struct TypeList {};

    // Concat two TypeLists
    template<typename L1, typename L2>
    struct Concat;

    template<typename... A, typename... B>
    struct Concat<TypeList<A...>, TypeList<B...>> {
        using type = TypeList<A..., B...>;
    };

    // Flatten a TypeList into a single level
    template<typename List>
    struct FlattenList;

    template<>
    struct FlattenList<TypeList<>> {
        using type = TypeList<>;
    };

    // Head is itself a TypeList: flatten head and tail, then concat
    template<typename... Hs, typename... Tail>
    struct FlattenList<TypeList<TypeList<Hs...>, Tail...>> {
        using type = typename Concat<typename FlattenList<TypeList<Hs...>>::type,
                                     typename FlattenList<TypeList<Tail...>>::type>::type;
    };

    // Head is a single type: keep head, flatten tail, then concat
    template<typename H, typename... Tail>
    struct FlattenList<TypeList<H, Tail...>> {
        using type = typename Concat<TypeList<H>, typename FlattenList<TypeList<Tail...>>::type>::type;
    };

    // Remove voids from a TypeList
    template<typename List>
    struct RemoveVoids;

    template<>
    struct RemoveVoids<TypeList<>> {
        using type = TypeList<>;
    };

    template<typename... Tail>
    struct RemoveVoids<TypeList<void, Tail...>> {
        using type = typename RemoveVoids<TypeList<Tail...>>::type;
    };

    template<typename H, typename... Tail>
    struct RemoveVoids<TypeList<H, Tail...>> {
        using type = typename Concat<TypeList<H>, typename RemoveVoids<TypeList<Tail...>>::type>::type;
    };


} // namespace PropCP

#endif // PROP_CP_TYPELIST_H
