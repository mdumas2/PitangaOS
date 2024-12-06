#pragma once

template<typename... Types>
struct TypeList {};

template<typename... TypeLists>
struct ConcatTypeLists;

template<typename... Types1, typename... Types2>
struct ConcatTypeLists<TypeList<Types1...>, TypeList<Types2...>> {
    using type = TypeList<Types1..., Types2...>;
};
