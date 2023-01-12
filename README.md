The car model consists of the following components:
sprung_car_body
    contains the mass of all sprung components of the car, with suspension neglected components of the car
    is able to simulate the bahaviour of forces acted upon it
    represents the position of the car, all other components are attached by reference to some hardpoint
suspension
    contains the geometry and is able to simulate and exhibit the behaviour of the suspension of the car
tire
    contains parameters of the tire and simulates the behaviour of the tire under loads
accumulator
    contains parameters for the accumulator, power output, and temperature simulations
powertrain
    includes gearing, differential, and motor behaviour
aero
    contains parameters for the aero package and simulates downforce behaviour
driver_interface
    interacts with car model by allowing for control inputs, all changes in motion of the car must be given a DI input (even if neutral)

Coordinates:
Although somewhat contradictory to standard vd coordinates, this will use y as positive longitudinal, x as positive (right side) lateral, and z as positive vertical.