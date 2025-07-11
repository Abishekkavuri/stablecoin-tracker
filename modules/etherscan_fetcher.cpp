#include "etherscan_fetcher.hpp"
#include <curl/curl.h>
#include <nlohmann/json.hpp>

static std::string response;

size_t callback(void* contents, size_t size, size_t nmemb, void*) {
    response.append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string fetch_token_transfers(const std::string& contract_address) {
    CURL* curl = curl_easy_init();
    response.clear();

    // std::string key = "W6WEMW99XX5M6EVRF99EJ9ER71HKZ92";  // 👈 Your API key
    std::string url = "https://api.etherscan.io/api?module=account&action=tokentx&contractaddress=" +
                      contract_address + "&startblock=0&endblock=99999999&page=1&offset=10&sort=desc&apikey=" + key;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);
    curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    return response;
}