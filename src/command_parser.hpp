#pragma once
#include <string>

enum class CommandType {Exit, Move, Attack, Look, Talk, Inventory, Status, Undefined};



class CommandParser {
public:
    CommandParser() = default;

    void readCommand();
    CommandType getCommandType() const;
    std::string getString(uint16_t id) const;
    int16_t getInt(uint16_t id) const;
    size_t getArgumentsNum() const;

private:
    bool isWhitespace(const std::string& s) const;
    void calculateArgumentsNum();

    std::string last_command;
    size_t argumentsNum;
};
