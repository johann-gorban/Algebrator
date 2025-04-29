#pragma once

#include <string>
#include <vector>
#include "tokens.hpp"

class LexerContext;


class State {
public:
    virtual void handle_char(LexerContext &context, char c) = 0;

    virtual void emit_token_from_buffer(LexerContext &context) = 0;

    virtual ~State() = default;
};


class StartState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};


class NumberState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};


class IdentifierState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};


class OperatorState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};


class UnaryMinusState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};


class LeftParanthesisState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};


class RightParanthesisState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};


class CommaState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};


class EndState : public State {
public:
    void handle_char(LexerContext &context, char c) override;

    void emit_token_from_buffer(LexerContext &context) override;
};

