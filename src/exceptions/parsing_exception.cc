//
// Created by Pierrick on 30/09/2020.
//

#include <exceptions/parsing_exception.hh>

ParsingException::ParsingException(const char* msg): msg(msg) {}

const char* ParsingException::what() const noexcept { return msg; }
