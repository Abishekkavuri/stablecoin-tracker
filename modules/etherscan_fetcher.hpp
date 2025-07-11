#pragma once
#include <string>
#include <vector>

struct TokenTransaction {
    std::string from;
    std::string to;
    double value;
    std::string timestamp;
};

std::vector<TokenTransaction> fetch_token_transactions(const std::string& contract_address, const std::string& api_key);
