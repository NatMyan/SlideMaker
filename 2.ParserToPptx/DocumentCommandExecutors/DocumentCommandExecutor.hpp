#ifndef DOCUMENT_COMMAND_EXECUTOR_HPP
#define DOCUMENT_COMMAND_EXECUTOR_HPP

#include "../Parser4.hpp"
#include "../Document.hpp"

#include <memory>

class DocumentCommandExecutor {
    public:
        DocumentCommandExecutor() : doc_ (std::make_shared<Document>()) {}
        virtual void execute (CommandType parsedCmd) = 0;
        virtual ~DocumentCommandExecutor() = default;

    protected:
        std::shared_ptr<Document> doc_;
};

#endif // DOCUMENT_COMMAND_EXECUTOR_HPP