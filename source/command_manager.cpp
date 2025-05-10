#include "command_manager.hpp"


CommandManager::CommandManager() {
    this->binary_operators["+"] = std::make_shared<AdditionCommand>();
    this->binary_operators["-"] = std::make_shared<SubstractCommand>();
    this->binary_operators["*"] = std::make_shared<MultiplyCommand>();
    this->binary_operators["/"] = std::make_shared<DivisionCommand>();
    this->binary_operators["^"] = std::make_shared<PowerCommand>();

    // this->functions["sin"] = std::make_shared<SinCommand>();
    // this->unary_operators["-"] = std::make_shared<UnaryMinusCommand>();
}

const command_ptr CommandManager::get_command(const token_ptr &token) const {
    command_ptr command(nullptr);
    
    TokenType token_type = token->get_type();
    if (token_type == TokenType::Number) {
        command = std::make_shared<NumberCommand>();
    }
    else {
        std::string token_name = token->get_data();

        if (token_type == TokenType::Function) {
            command = this->functions.at(token_name);
        }
        else if (token_type == TokenType::Operator) {
            auto operator_token = std::dynamic_pointer_cast<OperatorToken>(token);
            Arity token_arity = operator_token->get_arity();
            
            if (token_arity == Arity::Binary) {
                command = this->binary_operators.at(token_name);
            }
            else if (token_arity == Arity::Unary) {
                command = this->unary_operators.at(token_name);
            }
        }
    }
    
    return command;
}