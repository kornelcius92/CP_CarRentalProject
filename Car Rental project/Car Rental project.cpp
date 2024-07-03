#include <iostream>
#include <vector>
#include <string>

//author: Wiktor Kordala

class Car {
public:
    Car(std::string model, float rentalPrice)
        : model(model), rentalPrice(rentalPrice), isRented(false) {}

    std::string getModel() const { return model; }
    float getRentalPrice() const { return rentalPrice; }
    bool getIsRented() const { return isRented; }

    void setRentalPrice(float newPrice) { rentalPrice = newPrice; }
    void rentCar() { isRented = true; }
    void returnCar() { isRented = false; }

private:
    std::string model;
    float rentalPrice;
    bool isRented;
};

class CarRental {
public:
    void addCar(const Car& car) {
        cars.push_back(car);
    }

    void listAvailableCars() const {
        std::cout << "Available cars:\n";
        for (const auto& car : cars) {
            if (!car.getIsRented()) {
                std::cout << "Model: " << car.getModel()
                    << ", Rental Price: $" << car.getRentalPrice() << "\n";
            }
        }
    }

    void listRentedCars() const {
        std::cout << "Rented cars:\n";
        for (const auto& car : cars) {
            if (car.getIsRented()) {
                std::cout << "Model: " << car.getModel()
                    << ", Rental Price: $" << car.getRentalPrice() << "\n";
            }
        }
    }

    void rentCar(const std::string& model) {
        for (auto& car : cars) {
            if (car.getModel() == model && !car.getIsRented()) {
                car.rentCar();
                std::cout << "Car " << model << " has been rented.\n";
                return;
            }
        }
        std::cout << "Car " << model << " is not available.\n";
    }

    void returnCar(const std::string& model) {
        for (auto& car : cars) {
            if (car.getModel() == model && car.getIsRented()) {
                car.returnCar();
                std::cout << "Car " << model << " has been returned.\n";
                return;
            }
        }
        std::cout << "Car " << model << " was not rented.\n";
    }

    void changeRentalPrice(const std::string& model, float newPrice) {
        for (auto& car : cars) {
            if (car.getModel() == model) {
                car.setRentalPrice(newPrice);
                std::cout << "Rental price for " << model << " has been changed to $" << newPrice << ".\n";
                return;
            }
        }
        std::cout << "Car " << model << " not found.\n";
    }

private:
    std::vector<Car> cars;
};

class CarRentalSystem {
public:
    CarRentalSystem() : rentalSystem() {}

    void start() {
        int choice;
        do {
            std::cout << "\nCar Rental System\n";
            std::cout << "1. Add Car\n";
            std::cout << "2. List Available Cars\n";
            std::cout << "3. List Rented Cars\n";
            std::cout << "4. Rent Car\n";
            std::cout << "5. Return Car\n";
            std::cout << "6. Change Rental Price\n";
            std::cout << "0. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                rentalSystem.listAvailableCars();
                break;
            case 3:
                rentalSystem.listRentedCars();
                break;
            case 4:
                rentCar();
                break;
            case 5:
                returnCar();
                break;
            case 6:
                changeRentalPrice();
                break;
            case 0:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 0);
    }

private:
    CarRental rentalSystem;

    void addCar() {
        std::string model;
        float price;
        std::cout << "Enter car model: ";
        std::cin >> model;
        std::cout << "Enter rental price: ";
        std::cin >> price;
        rentalSystem.addCar(Car(model, price));
        std::cout << "Car " << model << " added with rental price $" << price << ".\n";
    }

    void rentCar() {
        std::string model;
        std::cout << "Enter car model to rent: ";
        std::cin >> model;
        rentalSystem.rentCar(model);
    }

    void returnCar() {
        std::string model;
        std::cout << "Enter car model to return: ";
        std::cin >> model;
        rentalSystem.returnCar(model);
    }

    void changeRentalPrice() {
        std::string model;
        float newPrice;
        std::cout << "Enter car model to change price: ";
        std::cin >> model;
        std::cout << "Enter new rental price: ";
        std::cin >> newPrice;
        rentalSystem.changeRentalPrice(model, newPrice);
    }
};

int main() {
    CarRentalSystem system;
    system.start();
    return 0;
}
