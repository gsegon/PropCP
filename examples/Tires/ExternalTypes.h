#ifndef PROPCP_EXTERNALTYPES_H
#define PROPCP_EXTERNALTYPES_H
#include <iostream>
#include <ostream>

namespace ExLib1{

    // Library 1
    struct Car {
        virtual ~Car() = default;

        virtual void drive(double speed) {
            std::cout << "Driving at " << speed << " km/h (" << speed / max_speed() * 100 << "%) of max speed."   << std::endl;
        }
        virtual double max_speed()  const =0;
        virtual double mass() const =0;

    };


    struct FordFiesta :  Car {
        double max_speed() const override {
            return 201;
        }
        double mass() const override {
            return 1044;
        }
    };


    struct ReliantRegalCar : Car {

        double max_speed() const override {
            return 113;
        }
        double mass() const override {
            return 455;
        }

    };
}


// Library 2
namespace ExLib2{

    struct TriCycle {
        double mass = 20;
    };

}

#endif // PROPCP_EXTERNALTYPES_H
