#include "AttributesIterator.hpp"

// template <typename Key, typename Value>
auto AttributesIterator::operator*() -> reference { // undefined
    return iter_->second;
}

// template <typename Key, typename Value>
auto AttributesIterator::operator*() const -> const_reference {
    return iter_->second;
}

// template <typename Key, typename Value>
auto AttributesIterator::operator->() -> pointer {
    return &(iter_->second);
}

// template <typename Key, typename Value>
auto AttributesIterator:: operator->() const -> const_pointer {
    return &(iter_->second);
}

// template <typename Key, typename Value>
auto AttributesIterator::operator++() -> AttributesIterator& { // undefined
    ++iter_;
    return *this;
}

// template <typename Key, typename Value>
auto AttributesIterator::operator++(int) -> AttributesIterator {
    AttributesIterator temp = *this;
    ++iter_;
    return temp;
}

// template <typename Key, typename Value>
/*auto AttributesIterator::operator--() -> AttributesIterator& {
    --iter_;
    return *this;
}

// template <typename Key, typename Value>
auto AttributesIterator::operator--(int) -> AttributesIterator {
    AttributesIterator temp = *this;
    --iter_;
    return temp;
}*/

// template <typename Key, typename Value>
auto AttributesIterator::operator==(const AttributesIterator& rhs) const -> bool {
    return iter_ == rhs.iter_;
}

// template <typename Key, typename Value>
auto AttributesIterator::operator!=(const AttributesIterator& rhs) const -> bool { // undefined
    return iter_ != rhs.iter_;
}
