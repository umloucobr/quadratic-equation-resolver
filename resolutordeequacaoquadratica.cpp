#include <iostream>
#include <cmath>

class Fraction {
    protected:
        double numerator{};
        double denominator{};
    public:
        Fraction() {
            numerator = 0;
            denominator = 1;
        }

        Fraction(double num, double den) : numerator{ num }, denominator{ den }{

        }
};

class RootToFraction : Fraction{
    public:
        RootToFraction(double num, double den){
            numerator = num;
            denominator = den;
        }

        void setRoots(double root1, double root2) {
            numerator = root1;
            denominator = root2;
        }

        void transformRootInFraction() {
            numerator = numerator * 100;
        }

        void printFraction() {
            std::cout << numerator << "/" << 100 << ".\n";
        }
};

void transformInFraction(double x1, double x2) {
    std::string input{};
    while (input != "yes" && input != "y" && input != "no" && input != "n")
    {
        std::cout << "Transform in fraction?(y/n)\n";
        std::cin >> input;
    }
    if (input == "yes" || input == "y")
    {
        RootToFraction root1{ x1, 1};
        RootToFraction root2{ x2, 1 };

        root1.transformRootInFraction();
        root1.printFraction();

        root2.transformRootInFraction();
        root2.printFraction();
    }
}

double resolutor() {
    double a{};
    double b{};
    double c{};
    std::string input{};

    std::cout << "Enter the equation (only decimal).\n";

    std::cout << "Enter A (without the variable):\n";
    std::cin >> a;
    std::cout << "Enter B (without the variable):\n";
    std::cin >> b;
    std::cout << "Enter C:\n";
    std::cin >> c;
    std::cout << "Equation: " << a << "x^2" << std::showpos << b << "x" << c << "=0.\n";
    
    double delta{ (b * b) - 4 * a * c };
    if (delta > 0)
    {
        double result1{ (-b + sqrt(delta)) / 2 * a };
        double result2{ (-b - sqrt(delta)) / 2 * a };

        std::cout << std::noshowpos << "Root 1: " << result1 << ".\n";
        std::cout << std::noshowpos << "Root 2: " << result2 << ".\n";
        transformInFraction(result1, result2);

        while (input != "yes" && input != "y" && input != "no" && input != "n")
        {
            std::cout << "Go again?(y/n)\n";
            std::cin >> input;
        }
        if (input == "yes" || input == "y")
        {
            resolutor();
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            return 0;
        }
    }
    else
    {
        std::cout << "Negative delta.\n";
        std::cout << "Delta value: " << delta << ".\n";
        while (input != "yes" && input != "y" && input != "no" && input != "n")
        {
            std::cout << "Go again?(y/n)\n";
            std::cin >> input;
        }
        if (input == "yes" || input == "y")
        {
            resolutor();
        }
        else
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin.get();
            return 0;
        }
    }
}

int main() {
    resolutor();

    return 0;
}