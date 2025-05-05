#pragma once

#include "sort_commands.hpp"

#include <unordered_map>
#include <string>

class SortCommandManager {
private:
    std::unordered_map<std::string, sort_command_ptr> commands;
public:
    SortCommandManager();

    const sort_command_ptr get_command(const token_ptr &token) const;

    bool has_command(const std::string &token_name) const;
};