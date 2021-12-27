/** Vulkan App class header 
 *  Author:  Evan Newman
 *  December 2021
 */

// System Includes
#include <iostream>
#include <stdexcept>

// Project Includes

// Local Includes
#include "Engine3D.h"

namespace Engine3D {

void Engine::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void Engine::initWindow() {
    std::cout << "Initializing Window\n";

    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    m_window = glfwCreateWindow(m_windowWidth, m_windowHeight, "Engine3D", nullptr, nullptr);

}

void Engine::initVulkan() {
    std::cout << "Initializing Vulkan\n";

    createInstance();
}

void Engine::createInstance() {
    // app info struct
    VkApplicationInfo appInfo{};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Engine3D";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // create info struct
    VkInstanceCreateInfo createInfo{};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // get the extensions, need this for platform specific window management
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    // add the extentions to the create info struct
    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    // validation layer count
    createInfo.enabledLayerCount = 0;

    // vkCreateInstance can throw if the required extensions are not available
    if(vkCreateInstance(&createInfo, nullptr, &m_vulkanInstance) != VK_SUCCESS) {
        throw std::runtime_error("Vulkan instance creation failed");
    }
}

void Engine::mainLoop() {
    std::cout << "Entering main loop\n";

    while (!glfwWindowShouldClose(m_window)) {
        glfwPollEvents();
    }
}

void Engine::cleanup() {
    std::cout << "Cleaning up\n";

    vkDestroyInstance(m_vulkanInstance, nullptr);

    glfwDestroyWindow(m_window);
    glfwTerminate();
}

} // namespace Engine3D