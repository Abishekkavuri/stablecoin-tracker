#include <iostream>
#include <thread>
#include <chrono>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "modules/price_fetcher.hpp"
#include "modules/risk_model.hpp"
#include "modules/email_notifier.hpp"
#include "modules/sqlite_logger.hpp"

int main() {
    // ✅ Hardcoded email config (instead of loading from .env)
    std::string api_key = "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";  // Your SendGrid API Key
    std::string sender_email = "abhiabishek3354@gmail.com";   // Your verified sender email
    std::string receiver_email = "abishekakavuri@gmail.com";   // Receiver email

    SQLiteLogger logger("../data/stablecoin_history.db");

    while (true) {
        double price = get_price_usdc();
        double score = calculate_risk_score(price);

        logger.insert_price(price);

        std::cout << "[USDC] Price: $" << price << " | Risk Score: " << score << std::endl;

        if (score > 0.01) {
            send_email_alert(
                "Stablecoin Depeg Alert",
                "USDC risk score: " + std::to_string(score)
            );
        }


        std::this_thread::sleep_for(std::chrono::seconds(10));
    }

    return 0;
}



// ZFmkahx8KehFpQChwfgNlVtsVHGOQXkL