#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>

struct Vector2D {
    float x = 0.0f;
    float y = 0.0f;

    Vector2D operator+(const Vector2D& other) const {
        return {x + other.x, y + other.y};
    }

    Vector2D operator-(const Vector2D& other) const {
        return {x - other.x, y - other.y};
    }

    Vector2D operator*(float scalar) const {
        return {x * scalar, y * scalar};
    }

    float length() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2D normalize() const {
        float len = length();
        if (len == 0.0f) {
            return {0.0f, 0.0f};
        }
        return {x / len, y / len};
    }
};


std::string getCommand();
Vector2D getVectorInput(const std::string& prompt);
void printVector(const Vector2D& v);


int main() {
    std::string command;

    while (command != "quit") {
        command = getCommand();
        std::transform(command.begin(), command.end(), command.begin(), ::tolower); // In-place to lowercase

        if (command == "add") {
            std::cout << "Vector addition (A + B):\n";
            auto a = getVectorInput("Enter coordinates of vector A (x y): ");
            auto b = getVectorInput("Enter coordinates of vector B (x y): ");
            printVector(a + b);

        } else if (command == "sub") {
            std::cout << "Vector subtraction (A - B):\n";
            auto a = getVectorInput("Enter coordinates of vector A (x y): ");
            auto b = getVectorInput("Enter coordinates of vector B (x y): ");
            printVector(a - b);

        } else if (command == "scale") {
            std::cout << "Scalar multiplication (A * scalar):\n";
            auto a = getVectorInput("Enter coordinates of vector A (x y): ");
            float scalar;
            std::cout << "Enter scalar value: ";
            std::cin >> scalar;
            printVector(a * scalar);

        } else if (command == "length") {
            std::cout << "Vector length:\n";
            auto a = getVectorInput("Enter coordinates of vector A (x y): ");
            std::cout << "Length: " << a.length() << "\n";


        } else if (command == "normalize") {
            std::cout << "Vector normalization:\n";
            auto a = getVectorInput("Enter coordinates of vector A (x y): ");
            auto normalized = a.normalize();
            printVector(normalized);
        }
    }

    return 0;
}

std::string getCommand() {
    std::string command;
    std::cout << "\nEnter command (add | sub | scale | length | normalize | quit): ";
    std::cin >> command;
    return command;
}

Vector2D getVectorInput(const std::string& prompt) {
    Vector2D v;
    std::cout << prompt;
    std::cin >> v.x >> v.y;
    return v;
}

void printVector(const Vector2D& v) {
    std::cout << "Result: (" << v.x << ", " << v.y << ")\n";
}