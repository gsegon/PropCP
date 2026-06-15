
#include "ExternalTypes.h"
#include "Properties.h"

int main(int argc, char* argv[]) {

    ExLib1::FordFiesta car;
    car.drive(50);

    ExLib1::ReliantRegalCar trotter_car;
    trotter_car.drive(50);

    if constexpr ( HasWheels<ExLib1::FordFiesta>) {
        std::cout << "FordFiesta  Has wheels" << std::endl;
    }

    if constexpr ( HasWheels<ExLib1::ReliantRegalCar>) {
        std::cout << "ReliantRegalCar  Has wheels" << std::endl;
    }

    if constexpr ( HasWheels<int>) {
        std::cout << "ReliantRegalCar  Has wheels" << std::endl;
    }


    if constexpr ( HasMass<ExLib1::FordFiesta>) {
        std::cout << "FordFiesta  Has mass" << std::endl;
    }
    if constexpr ( HasMass<ExLib1::ReliantRegalCar>) {
        std::cout << "ReliantRegalCar  Has mass" << std::endl;
    }
    if constexpr ( HasMass<ExLib2::TriCycle>) {
        std::cout << "TriCycle  Has mass" << std::endl;
    }
    if constexpr ( HasMass<int>) {
        std::cout << "FordFiesta  Has mass" << std::endl;
    }


    return 0;
}
