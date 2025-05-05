#include "sort_command_manager.hpp"

SortCommandManager::SortCommandManager() {
    this->commands["ADD"] = std::make_shared<SortOperatorCommand>();  
    this->commands["SUB"] = std::make_shared<SortOperatorCommand>();  
    this->commands["MUL"] = std::make_shared<SortOperatorCommand>();  
    this->commands["DIV"] = std::make_shared<SortOperatorCommand>();  
    this->commands["POW"] = std::make_shared<SortOperatorCommand>();

    this->commands["NUMBER"] = std::make_shared<SortNumberCommand>();
    this->commands["SEPARATOR"] = std::make_shared<SortSeparatorCommand>();
    this->commands["LEFT_PARANTHESIS"] = std::make_shared<SortLeftParenthesisCommand>();
    this->commands["RIGHT_PARANTHESIS"] = std::make_shared<SortRightParenthesisCommand>();  
}

const sort_command_ptr SortCommandManager::get_command(const token_ptr &token) const {
    sort_command_ptr command(nullptr);

    std::string token_name = token->get_name();

    if (this->has_command(token_name)) {
        command = this->commands.at(token_name);
    }
    
    return command;
}

bool SortCommandManager::has_command(const std::string &token_name) const {
    return (commands.find(token_name) != commands.end());
}