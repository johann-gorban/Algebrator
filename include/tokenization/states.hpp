#pragma once

#include <memory>

#include "context.hpp"


using state_ptr = std::shared_ptr<State>;

class State {
public:
    virtual void handle_char(TokenizerContext &context, char c) = 0;

    virtual void emit_token_from_buffer(TokenizerContext &context) = 0;

    virtual ~State() = default;
};


class StartState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};


class NumberState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};


class IdentifierState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};


class OperatorState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};


class UnaryOperatorState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};


class LeftParanthesisState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};


class RightParanthesisState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};


class SeparatorState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};


class EndState : public State {
public:
    void handle_char(TokenizerContext &context, char c) override;

    void emit_token_from_buffer(TokenizerContext &context) override;
};