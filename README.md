# 🪙 Stablecoin Risk Monitoring System

**Real-time Depeg Detection with Email Alerts and Blockchain Transfer Tracker**  
Monitors the price of USDC stablecoin and its on-chain activity using Etherscan API. If a depeg is detected (price deviates from $1), it sends an email alert via SendGrid.

---

## 🚀 Features

- ✅ Real-time USDC price fetching via API
- 🧠 Risk score calculation to detect depeg
- 📬 Email notification system using SendGrid
- 🧾 SQLite database logging of prices
- 🔗 Etherscan API integration to monitor token transfers
- 🧱 C++ modular design (no external script language dependencies)
- 🧰 MSYS2 + CMake + MinGW compatible

---

## 📁 Project Structure

```bash
stablecoin-tracker/
│
├── build/                    # CMake build output
├── modules/                  # Logic modules
│   ├── email_notifier.cpp    # Email alerts
│   ├── price_fetcher.cpp     # Fetch current USDC price
│   ├── risk_model.cpp        # Calculate risk score
│   ├── sqlite_logger.cpp     # Insert price to DB
│   ├── websocket_client.cpp  # For WebSocket integrations (future)
│   └── etherscan_fetcher.cpp # Fetch USDC ERC20 transfers
├── main.cpp                  # Core loop
├── CMakeLists.txt            # CMake configuration
└── .env                      # Environment variables (API keys etc.)

## 1. Clone the repository
git clone https://github.com/Abishekkavuri/stablecoin-tracker.git
cd stablecoin-tracker

# 2. Create build directory
mkdir build && cd build

# 3. Generate Makefiles
cmake .. -G "MinGW Makefiles"

# 4. Compile
make

# 5. Run the executable
./tracker.exe

