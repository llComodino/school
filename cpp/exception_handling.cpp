#include <iostream>
#include <stdexcept>

// Define a custom exception class
class MyException : public std::exception {
public:
    MyException(const char* message) : message_(message) {}

    // Override the what() method to provide a description of the exception
    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

int main() {
    try {
        int age;
        std::cout << "Enter your age: ";
        std::cin >> age;

        if (age < 0) {
            // Throw a custom exception if the age is negative
            throw MyException("Age cannot be negative.");
        }

        std::cout << "Your age is: " << age << std::endl;
    }
    catch (const MyException& e) {
        // Handle the custom exception
        std::cerr << "Custom Exception: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        // Handle other standard exceptions
        std::cerr << "Standard Exception: " << e.what() << std::endl;
    }
    catch (...) {
        // Handle any other unexpected exceptions
        std::cerr << "An unknown exception occurred." << std::endl;
    }

    return 0;
}
