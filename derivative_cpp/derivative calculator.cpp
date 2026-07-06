#include <iostream>
#include <cmath>
#include <iomanip>

template <typename Function>
long double derivative(Function f, long double x, long double h) {
    return (f(x + h) - f(x - h)) / (2 * h);
}

int main() {
    int select_function;
    std::cout << "select a function; 1 for logarithm, 2 for exponential, 3 for trigonometric, 4 for polynomial: ";
    std::cin >> select_function;
    if (select_function == 1){
        long double x;
        std::cout << "enter a value of x for log(x): ";
        std::cin >> x;
        long double h = 0.00001;
        long double result = derivative(static_cast<long double (*)(long double)>(std::log), x, h);
        std::cout << "The derivative of log at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
    }
    else if (select_function == 2){
        long double x;
        std::cout << "enter a value of x for exp(x): ";
        std::cin >> x;
        long double h = 0.00001;
        long double result = derivative(static_cast<long double (*)(long double)>(std::exp), x, h);
        std::cout << "The derivative of exp at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
    }
    else if (select_function == 3){
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
            std::cout << "The derivative of cos at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << -result << std::endl;
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
            
            
        
        default:
            std::cout << "Invalid trigonometric function." << std::endl;
            return 1;
    }

    }
    else if (select_function == 4){
        long double a, b, c, d, x;
        std::cout << "enter the coefficients a, for the polynomial ax^3 + bx^2 + cx + d: ";
        std::cin >> a;
        std::cout << "enter the coefficients b, for the polynomial ax^3 + bx^2 + cx + d: ";
        std::cin >> b;
        std::cout << "enter the coefficients c, for the polynomial ax^3 + bx^2 + cx + d: ";
        std::cin >> c;
        std::cout << "enter the coefficients d, for the polynomial ax^3 + bx^2 + cx + d: ";
        std::cin >> d;
        std::cout << "enter a value of x for the polynomial: ";
        std::cin >> x;
        long double h = 0.00001;
        long double result = derivative([a, b, c, d](long double x) { return a * x * x * x + b * x * x + c * x + d; }, x, h);
        std::cout << "The derivative of the polynomial at x = " << x << " is approximately: " << std::fixed << std::setprecision(10) << result << std::endl;
    }
    else{
        std::cout << "Invalid selection." << std::endl;
    }
    return 0;
}
