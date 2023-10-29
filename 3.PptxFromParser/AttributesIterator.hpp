#ifndef ATTRIBUTE_ITERATOR_HPP
#define ATTRIBUTE_ITERATOR_HPP

#include "definitions.hpp"

#include <iterator> // std::bidirectional_iterator_tag;

template <typename Key, typename Value>
class AttributesIterator {
    public:
        using iterator_category = std::bidirectional_iterator_tag;
        using key_type = Key;
        using value_type = Value;
        using difference_type = ptrdiff_t;
        using pointer = value_type*;
        using const_pointer = const value_type*;
        using reference = value_type&;
        using const_reference = const value_type&;

    public:
        explicit AttributesIterator(typename MapPair<Key, Value>::iterator mapIter) : iter_(mapIter) {}

    public:
        reference operator*();
        const_reference operator*() const;
        pointer operator->();
        const_pointer operator->() const;
        AttributesIterator& operator++();
        AttributesIterator operator++(int);
        AttributesIterator& operator--();
        AttributesIterator operator--(int);
        bool operator==(const AttributesIterator& other) const;
        bool operator!=(const AttributesIterator& other) const;

    private:
        typename MapPair<Key, Value>::iterator iter_;
};

#endif // ATTRIBUTE_ITERATOR_HPP