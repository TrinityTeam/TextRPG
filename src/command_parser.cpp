#include "command_parser.hpp"
#include <iostream>
#include <sstream>



void CommandParser::readCommand() {
    do {
        std::getline(std::cin, last_command);
    } while(isWhitespace(last_command));
    calculateArgumentsNum();
}



CommandType CommandParser::getCommandType() const {
    std::stringstream command(last_command);
    std::string type;
    command >> type;

    if(type == "exit") {
        return CommandType::Exit;

    } else if(type == "look") {
        return CommandType::Look;
    }
    return CommandType::Undefined;
}



std::string CommandParser::getString(uint16_t id) const {
    std::stringstream command(last_command);
    std::string s {};
    for(uint16_t c = 0; c <= id; c++) {
        command >> s;
    }
    return s;
}



int16_t CommandParser::getInt(uint16_t id) const {
    return std::stoi(getString(id));
}



size_t CommandParser::getArgumentsNum() const {
    return argumentsNum;
}



void CommandParser::calculateArgumentsNum() {
    std::stringstream command(last_command);
    std::string s {};
    argumentsNum = 0;
    while(command >> s) {
        argumentsNum++;
    }
}



bool CommandParser::isWhitespace(const std::string& s) const {
    for(auto& c: s) {
        if(not isspace(c)) {
            return false;
        }
    }
    return true;
}
