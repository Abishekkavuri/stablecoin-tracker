#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>
#include <iostream>

using websocketpp::connection_hdl;
typedef websocketpp::client<websocketpp::config::asio_client> client;
client c;

void on_message(connection_hdl hdl, client::message_ptr msg) {
    std::cout << "[WS] " << msg->get_payload() << std::endl;
}

void connect_binance_ws() {
    std::string uri = "wss://stream.binance.com:9443/ws/usdcusdt@trade";
    try {
        c.set_access_channels(websocketpp::log::alevel::none);
        c.clear_access_channels(websocketpp::log::alevel::frame_payload);
        c.init_asio();
        c.set_message_handler(&on_message);

        websocketpp::lib::error_code ec;
        auto con = c.get_connection(uri, ec);
        if (ec) {
            std::cout << "Connect error: " << ec.message() << std::endl;
            return;
        }

        c.connect(con);
        c.run();
    } catch (std::exception& e) {
        std::cout << "WS Error: " << e.what() << std::endl;
    }
}