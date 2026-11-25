// Takes in a Vulkan version as three args, outputs the hexadecimal
// representation of that Vulkan version.
// Must be compiled with --std=c++20
//
// Example:
// $ vulkan-hex 1 1 0
// 0x00401000

#include <iostream>
#include <string>

#define VK_MAKE_VERSION(major, minor, patch)                                   \
  ((((uint32_t)(major)) << 22U) | (((uint32_t)(minor)) << 12U) |               \
   ((uint32_t)(patch)))

int main(int argc, char *argv[]) {
  const auto vulkan_version = VK_MAKE_VERSION(
      std::stoi(argv[1]), std::stoi(argv[2]), std::stoi(argv[3]));
  const auto vulkan_version_formatted = std::format("{:08x}", vulkan_version);
  std::cout << std::hex << "0x" << vulkan_version_formatted << "\n";
  return 0;
}
