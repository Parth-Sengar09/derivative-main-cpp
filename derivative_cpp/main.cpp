#include <iostream>
#include <cmath>
#include <iomanip>
long double derivative(long double (*f)(long double), long double x, long double h);
int main() {
    long double pi = 3.14159265358979323846;
    long double n;
    long double x;
    int trig_coefficient;
    std::cout << "Enter a trigonometric function (1 for sin, 2 for cos, 3 for tan, 4 for cosec, 5 for sec, 6 for cot): ";
    std::cin >> trig_coefficient;
    std::cout << "enter a value of n for pi/n: ";
    std::cin >> n;
    if (0 < n){
        x=pi/n;
    }
    else{
        std::cout << "n must be greater than 0" << std::endl;
    }
    long double h = 0.00001;
    switch(trig_coefficient) {
        case 1: {
             long double result = derivative(static_cast<long double (*)(long double)>(std::sin), x, h);
            std::cout << "The derivative of sin at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
            break;
        }// sin
           
        case 2: {
           long double result = derivative(static_cast<long double (*)(long double)>(std::cos), x, h);
            std::cout << "The derivative of cos at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
            break;
        } // cos
            
        case 3: {
           long double result = derivative(static_cast<long double (*)(long double)>(std::tan), x, h);
            std::cout << "The derivative of tan at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
            break;
        }// tan
            
        case 4: {
           long double result = derivative(static_cast<long double (*)(long double)>([](long double x) { return 1.0 / std::sin(x); }), x, h);
            std::cout << "The derivative of cosec at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
            break;
        }// cosec
            
        case 5: {
            long double result = derivative(static_cast<long double (*)(long double)>([](long double x) { return 1.0 / std::cos(x); }), x, h);
            std::cout << "The derivative of sec at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
            break;
        }// sec
                  
        case 6: {
           long double result = derivative(static_cast<long double (*)(long double)>([](long double x) { return 1.0 / std::tan(x); }), x, h);
            std::cout << "The derivative of cot at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
            break;
        } // cot 
            
            
        // Add cases for other trigonometric functions
        default:
            std::cout << "Invalid trigonometric function." << std::endl;
            return 1;
    }
    return 0;
}
long double derivative(long double (*f)(long double), long double x, long double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}