#include <iostream>

#include "tokenization/tokens.hpp"
#include "tokenization/tokenizer.hpp"
#include "token_manager.hpp"

#include "parsing/parser.hpp"
#include "parsing/extended_tokens.hpp"
#include "sorting/sorter.hpp"
#include "translating/translator.hpp"
#include "computation/calculator.hpp"

class ExtendedTokenPrinter {
public:
    static void visit(const token_ptr token) noexcept {
        TokenManager manager;
        auto type = token->get_type();

        std::cout << "Token: " << manager.get_type_name(type) << " " << token->get_data();

        if (type == TokenType::Operator) {
            auto etoken = std::static_pointer_cast<OperatorToken>(token);
            if (etoken) {
                std::cout << " " << int(etoken->get_arity()) << " " << etoken->get_precedance();
            }
            else {
                std::cerr << " Cast failed! Actual type: " << typeid(*token).name() << std::endl;
            }
        }

        std::cout << std::endl;
    }
};

class Tester {
private:
    static long unsigned int test_number;
public:
    static void test(const std::string &expression_to_test) {
        static Tokenizer tokenizer;
        static Parser parser;
        static Sorter sorter;
        static Translator translator;
        static Calculator calculator;

        std::cout << "Test #" << test_number++ << std::endl;
        
        try {
            std::vector<token_ptr> tokens = tokenizer.tokenize(expression_to_test);
            std::vector<token_ptr> extended_tokens = parser.parse(tokens);
            std::vector<token_ptr> sorted_tokens = sorter.rpn_sort(extended_tokens);
            std::vector<command_ptr> commands = translator.translate_tokens(sorted_tokens);

            unsigned int counter = 1;
            for (const auto &token : sorted_tokens) {
                std::cout << counter++ << " ";
                ExtendedTokenPrinter::visit(token);
            }

            std::cout << "Result: " << calculator.calculate(commands) << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << std::endl;
    }
};

long unsigned int Tester::test_number = 1;

int main() {
    // Test 1 - Простое сложение
    {
        Tester::test("2+3");
    }
    // Test 2 - Приоритет операторов
    {
        Tester::test("2+3*4");
    }
    // Test 3 - Со скобками
    {
        Tester::test("(2+3)*4");
    }
    // Test 4 - Унарный минус
    {
        Tester::test("-2+3");
    }
    // Test 5 - Множественные операторы
    {
        Tester::test("2+3*4-5");
    }
    // Test 6 - Вложенные скобки
    {
        Tester::test("(2+(3*4))-5");
    }
    // Test 7 - Функция с одним аргументом
    {
        Tester::test("sin(30)");
    }
    // Test 8 - Функция с выражением
    {
        Tester::test("sin(30+45)");
    }
    // Test 9 - Несколько функций
    {
        Tester::test("sin(30)+cos(45)");
    }
    // Test 10 - Комплексное выражение
    {
        Tester::test("2+sin(30)*3");
    }
    // Test 11 - Много операций
    {
        Tester::test("2+3*4-5/6");
    }
    // Test 12 - Все базовые операторы
    {
        Tester::test("2+3*4/5-6");
    }
    // Test 13 - Глубоко вложенные скобки
    {
        Tester::test("((2+3)*4)-5");
    }
    // Test 14 - Множественное умножение
    {
        Tester::test("2*3*4");
    }
    // Test 15 - Смешанные операции
    {
        Tester::test("2+3*4/5-6");
    }
    // Test 16 - Функция от функции
    {
        Tester::test("sin(cos(45))");
    }
    // Test 17 - Тройная вложенность
    {
        Tester::test("sin(cos(tan(45)))");
    }
    // Test 18 - Комбинация всего
    {
        Tester::test("(2+sin(30))*3-4/5");
    }
    // Test 19 - Длинное выражение
    {
        Tester::test("1+2*3-4/5+6*7-8");
    }
    // Test 20 - Максимально комплексное
    {
        Tester::test("sin(30)*(2+cos(45))-tan(60)/4");
    }
    
    return 0;
}