#include "tokenization/tokens.hpp"

Token::Token(const std::string &name, const token_type &type) : data(data), type(type) {

}

const std::string &Token::get_data() const noexcept {
    return this->data;
}

const token_type Token::get_type() const noexcept {
    return this->type;
}