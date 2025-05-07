#pragma once

#include <memory>
#include <string>

typedef enum {
    OPERATOR,
    FUNCTION,
    NUMBER,
    LEFT_PARANTHESIS,
    RIGHT_PARANTHESIS,
    SEPARATOR
} token_type;

class Token;

using token_ptr = std::shared_ptr<Token>;

class Token {
private:
    const std::string data;
    const token_type type;
public:
    explicit Token(const std::string &name, const token_type &type) noexcept;

    const std::string &get_data() const noexcept;

    const token_type get_type() const noexcept;
};