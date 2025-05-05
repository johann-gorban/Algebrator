#include "sorter.hpp"
#include "sort_command_manager.hpp"

#include <stack>
#include <stdexcept>

std::vector<token_ptr> Sorter::rpn_sort(const std::vector<token_ptr> &tokens) {
    // "Stack" for storing tokens in reverse polnish notation order
    std::vector<token_ptr> token_stack;

    // Create command manager to get command by token
    // Command executes the corresponding step of the algorithm
    SortCommandManager command_manager;

    for (const auto &token : tokens) {
        auto command = command_manager.get_command(token);
        if (command) {
            command->execute(token_stack, token);
        }
        else {
            throw std::runtime_error("Syntax error: unknown token name");
        }
    }

    return token_stack;
}