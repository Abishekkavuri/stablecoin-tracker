#include "email_notifier.hpp"
#include <curl/curl.h>
#include <iostream>
#include <string>

bool send_email_alert(const std::string& subject, const std::string& body) {
    // std::string api_key = "SG.gD7U3VWESYa64qq_BVLtig.VQlinC-sQIO30HHJRfBFJNZ13eVBfdvIrlbUoy1UY";  // ⚠️ Your real API key
    std::string to_email = "abishekakavuri@gmail.com";
    std::string from_email = "abhiabishek3354@gmail.com";

    std::string json_payload =
        "{"
        "\"personalizations\":[{\"to\":[{\"email\":\"" + to_email + "\"}]}],"
        "\"from\":{\"email\":\"" + from_email + "\"},"
        "\"subject\":\"" + subject + "\","
        "\"content\":[{\"type\":\"text/plain\", \"value\":\"" + body + "\"}]"
        "}";

    CURL* curl = curl_easy_init();
    if (curl) {
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, ("Authorization: Bearer " + api_key).c_str());
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, "https://api.sendgrid.com/v3/mail/send");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json_payload.c_str());

        CURLcode res = curl_easy_perform(curl);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);

        if (res != CURLE_OK) {
            std::cerr << "❌ SendGrid API error: " << curl_easy_strerror(res) << std::endl;
            return false;
        }

        std::cout << "✅ Email sent successfully!" << std::endl;
        return true;
    }

    std::cerr << "❌ Failed to initialize CURL." << std::endl;
    return false;
}
