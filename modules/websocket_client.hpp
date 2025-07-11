#pragma once
#include <string>
#include <functional>

class WebSocketClient {
public:
    void connect(const std::string& url, std::function<void(const std::string&)> on_message);
    void disconnect();
};
