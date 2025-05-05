#include "sort_commands.hpp"

#include <stdexcept>

void SortOperatorCommand::execute(std::vector<token_ptr> &tokens, std::vector<token_ptr> &output_tokens, const token_ptr &token) {
}

void SortNumberCommand::execute(std::vector<token_ptr> &tokens, std::vector<token_ptr> &output_tokens, const token_ptr &token) {
    output_tokens.push_back(token);
}

void SortFunctionCommand::execute(std::vector<token_ptr> &tokens, std::vector<token_ptr> &output_tokens, const token_ptr &token) {
    output_tokens.push_back(token);
}

void SortSeparatorCommand::execute(std::vector<token_ptr> &tokens, std::vector<token_ptr> &output_tokens, const token_ptr &token) {
    while (!tokens.empty()) {
        token_ptr token_in_stack = tokens.back();
    
        if (token_in_stack->get_name() == "LEFT_PARANTHESIS") {
            break;
        }
    
        output_tokens.push_back(token_in_stack);
        tokens.pop_back();
    }
    
    if (tokens.empty()) {
        throw std::runtime_error("Syntax error: missing parenthesis or function argument separator");
    }
    
}

void SortLeftParenthesisCommand::execute(std::vector<token_ptr> &tokens, std::vector<token_ptr> &output_tokens, const token_ptr &token) {
    output_tokens.push_back(token);
}

void SortRightParenthesisCommand::execute(std::vector<token_ptr> &tokens, std::vector<token_ptr> &output_tokens, const token_ptr &token) {
}
