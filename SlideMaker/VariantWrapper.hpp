#ifndef VARIANT_WRAPPERR_HPP
#define VARIANT_WRAPPERR_HPP

#include <variant>
#include <type_traits>
#include <QString>
#include <string>

template <typename... Types>
class VariantWrapper {
    public:
        template <typename T, typename = std::enable_if_t<(std::is_same_v<T, Types> || ...)> >
        explicit VariantWrapper(T value) : data_(value) {}

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

        template <typename T>
        bool holdsAlternative() const {
            return std::holds_alternative<T>(data_);
        }

    private:
        std::variant<Types...> data_;
};

#endif // VARIANT_WRAPPERR_HPP