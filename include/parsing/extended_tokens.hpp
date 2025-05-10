#pragma once

#include "tokenization/tokens.hpp"

enum class Associativity {
    Left,
    Right
};

enum class Arity {
    Unary,
    Binary
};


class OperatorToken : public Token {
private:
    const unsigned int precedance;
    const Associativity associativity;
    const Arity arity;
public:
    explicit OperatorToken(
        const Token& token,
        unsigned int precedance, 
        Associativity associativity, 
        Arity arity
    );

    unsigned int get_precedance() const noexcept;

    Associativity get_associativity() const noexcept;

    Arity get_arity() const noexcept;
};


class FunctionToken : public Token {
    public:
        explicit FunctionToken(const Token& token) noexcept;
    };


class NumberToken : public Token {
public:
    explicit NumberToken(const Token& token) noexcept;
};


class ParenthesisToken : public Token {
public:
    explicit ParenthesisToken(const Token& token) noexcept;
};


class SeparatorToken : public Token {
public:
    explicit SeparatorToken(const Token& token) noexcept;
};