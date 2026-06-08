#include <iostream>
#include <iomanip>

int main() {
    double p1, p2, p3;
    std::cin >> p1 >> p2 >> p3;
    
    double q1 = 1 - p1;
    double q2 = 1 - p2;
    double q3 = 1 - p3;
    
    double allCorrect = p1 * p2 * p3;
    double twoCorrect1 = p1 * p2 * q3;
    double twoCorrect2 = p1 * q2 * p3;
    double twoCorrect3 = q1 * p2 * p3;
    
    double result = allCorrect + twoCorrect1 + twoCorrect2 + twoCorrect3;
    
    std::cout << std::fixed << std::setprecision(3) << result << std::endl;
    
    return 0;
}