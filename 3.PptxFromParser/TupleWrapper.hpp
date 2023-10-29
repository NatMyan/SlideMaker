#ifndef TUPLE_WRAPPER_HPP
#define TUPLE_WRAPPER_HPP

#include <tuple>

template <typename... Types>
class TupleWrapper {
    public:
        TupleWrapper() : data_(Types()...) {}
        TupleWrapper(Types... args) : data_(args...) {}

    public:
        template <size_t Index>
        auto get() {
            return std::get<index>(data_);
        }

        template <size_t Index>
        void set(typename std::tuple_element<Index, std::tuple<Types...>>::type value) {
            std::get<Index>(data_) = value;
        }

    private:
        std::tuple<Types...> data_;
};

#endif // TUPLE_WRAPPER_HPP