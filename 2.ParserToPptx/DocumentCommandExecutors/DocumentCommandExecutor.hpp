#ifndef DOCUMENT_COMMAND_EXECUTOR_HPP
#define DOCUMENT_COMMAND_EXECUTOR_HPP

#include "../Parser4.hpp"
#include "../Document.hpp"


class DocumentCommandExecutor : public Document {
    public:
        virtual void execute (CommandType parsedCmd) = 0;
        virtual ~DocumentCommandExecutor() = default;
};

#endif // DOCUMENT_COMMAND_EXECUTOR_HPP