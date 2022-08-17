#pragma once

#include <vector>
#include "number_utils.hpp"
#include "opcodes.hpp"

Token* getToken(std::string s);
std::vector<Token*> getVectorTokens(std::string path);
