#include "custom.h"

template<>
struct TagList<MyType> {
    using Tags = TypeList<MyProp1, MyProp2, MyProp3, MyProp4>;
};

template<>
struct TagList<int> {
    using Tags = TypeList<MyProp1, MyProp2, MyProp3, MyProp4>;
};

template<>
struct TagList<std::string> {
    using Tags = TypeList<MyProp1, MyProp2>;
};

template<typename T, typename TypeList>
struct Printer;

// Base case: Empty property list
template<typename T>
struct Printer<T, TypeList<>> {
    static void print_tag_list() { std::cout << "We reached the empty case." << std::endl; }
};

template<typename T, typename TagListHead, typename... TagListTail>
struct Printer<T, TypeList<TagListHead, TagListTail...>> {
    static void print_tag_list() {
        std::cout << "Tag list for type " << typeid(T).name() << ": ";
        std::cout << typeid(TagListHead).name() << std::endl;

        Printer<T, TypeList<TagListTail...>>::print_tag_list();
    }
};

int main(int argc, char* argv[]) {

    // std::cout << "Dispatching for MyType" << std::endl;
    // DispatchProperties<MyType, TagList<MyType>::Tags>::dispatch();
    //
    //
    // std::cout << "Dispatching for int" << std::endl;
    // DispatchProperties<int, TagList<int>::Tags>::dispatch();
    // std::cout << std::endl;
    //
    // std::cout << "Dispatching for std::string" << std::endl;
    // DispatchProperties<std::string, TagList<std::string>::Tags>::dispatch();
    // std::cout << std::endl;

    Printer<MyType, TagList<MyType>::Tags>::print_tag_list();

    return 0;
}
