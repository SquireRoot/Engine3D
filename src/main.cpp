/** Main Function for Engine3D
 *  Author:  Evan Newman
 *  December 2021
 */

// System Includes
#include <iostream>
#include <stdexcept>
#include <cstdlib>

// Project Includes

// Local Includes
#include "Engine3D.h"

int main() {
    Engine3D::Engine engine;

    try {
        engine.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}