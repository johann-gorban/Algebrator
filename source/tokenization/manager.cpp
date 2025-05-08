#include "tokenization/manager.hpp"

#include <stdexcept>

TokenManager::TokenManager() {
    this->available_tokens["-"] = "SUB";
    this->available_tokens["+"] = "ADD";
    this->available_tokens["*"] = "MUL";
    this->available_tokens["/"] = "DIV";
    this->available_tokens["^"] = "POW";

    // Functions
    this->available_tokens["sin"] = "SIN";
    // ...
}

bool TokenManager::is_available(const std::string &name) const noexcept {
    return (this->available_tokens.count(name) == 0) ? false : true;
}

const std::string &TokenManager::get_name(const std::string &name) const {
    if (this->is_available(name)) {
        return this->available_tokens.at(name);
    }
    else {
        throw std::runtime_error("Token error: no tokens with such symbols available");
    }
}