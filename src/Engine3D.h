/** Vulkan App class header 
 *  Author:  Evan Newman
 *  December 2021
 */

// System Includes
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Project Includes

// Local Includes

namespace Engine3D {

    class Engine {

        public:
            void run();

        private:
            void initWindow();
            void initVulkan();
            void createInstance();
            void mainLoop();
            void cleanup();

        // Member variables
            GLFWwindow* m_window;

            const uint32_t m_windowWidth = 800;
            const uint32_t m_windowHeight = 600;
    
            VkInstance m_vulkanInstance;
    };

} // namespace Engine3D