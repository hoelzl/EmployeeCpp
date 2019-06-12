# Employee

This small example demonstrates the effect that bad architecture and in particular bad dependency management has on testability.

To get the initial version of the program, clone the master branch of the repository and its submodules (for Google Test):

    git clone --recurse-submodules https://gitlab.com/mhoelzl/EmployeeCpp.git

Then, either import the project into CLion or change into the `Employee` directory and manually build it with CMake:

    cd EmployeeCpp
    mkdir build
    cd build
    cmake .. 

Having configured the project, run `make` or launch Visual Studio with the generated solution file, depending on your platform.

When executing the `Main` target you will see that there are (at least) two problems: The list of Employees contains an invalid entry with id 4, and the salary of `Bill O'Rights` is not computed correctly.

The source resides in the folder `src` (duh).
Your job is to write unit tests for the `Employee` application that reproduce the bugs (and, if you're feeling particularly daring, other tests as well), and then fix the code. However, you will find that this is pretty difficult since the code has neither seams where you can gain control of the data to set up tests nor public methods that allow you to observe the state in enough detail to isolate the bugs.

Even after introducting seams and observers, writing tests remains tedious and you will probably have to work with mocks or stubs to isolate your system under test from the environment.

