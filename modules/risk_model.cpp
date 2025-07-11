#include "risk_model.hpp"
#include <cmath> 

// Simple model: score is based on how far price deviates from $1
double calculate_risk_score(double price) {
    double deviation = std::abs(1.0 - price);
    double score = deviation * 100;  // convert to percentage
    return score;
}
