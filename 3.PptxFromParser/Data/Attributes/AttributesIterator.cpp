#include "AttributesIterator.hpp"

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator*() -> reference {
    return iter_->second;
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator*() const -> const_reference {
    return iter_->second;
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator->() -> pointer {
    return &(iter_->second);
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>:: operator->() const -> const_pointer {
    return &(iter_->second);
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator++() -> AttributesIterator& {
    ++iter_;
    return *this;
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator++(int) -> AttributesIterator {
    AttributesIterator temp = *this;
    ++iter_;
    return temp;
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator--() -> AttributesIterator& {
    --iter_;
    return *this;
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator--(int) -> AttributesIterator {
    AttributesIterator temp = *this;
    --iter_;
    return temp;
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator==(const AttributesIterator& rhs) const -> bool {
    return iter_ == rhs.iter_;
}

template <typename Key, typename Value>
auto AttributesIterator<Key, Value>::operator!=(const AttributesIterator& rhs) const -> bool {
    return iter_ != rhs.iter_;
}