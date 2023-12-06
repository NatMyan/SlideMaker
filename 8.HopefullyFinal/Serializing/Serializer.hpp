#ifndef SERIALIZERR_HPP
#define SERIALIZERR_HPP

class Serializer {
    public:
        void save(std::shared_ptr<Document> doc, JSONDocument jsonDoc);
};

#endif // SERIALIZERR_HPP