#ifndef VARIANT_WRAPPER_HPP
#define VARIANT_WRAPPER_HPP

#include <variant>
#include <type_traits>

template <typename... Types>
class VariantWrapper {
    public:
        template <typename T, typename = std::enable_if_t<(std::is_same_v<T, Types> || ...)>>
        explicit VariantWrapper(T value) : data_(value) {}

        // VariantWrapper(Types()...) : data_(Types()...) {}

        VariantWrapper() : data_() {}

        bool operator==(const VariantWrapper& other) const {
            return data_ == other.data_;
        }

        bool operator!=(const VariantWrapper& other) const {
            return data_ != other.data_;
        }

    public:
        template <typename T>
        T get() const {
            return std::get<T>(data_);
        }

    private:
        std::variant<Types...> data_;
};

#endif // VARIANT_WRAPPER_HPP