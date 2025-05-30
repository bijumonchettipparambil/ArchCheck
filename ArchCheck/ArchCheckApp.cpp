//
// ArchCheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

//
// Type definition
//

struct OperatingSystem {

    enum class Name
    {
        WINDOWS,
        LINUX,
        MAC,
        UNKNOWN
    };

    static const char* getName(const Name name)  {

        switch (name)
        {
        case Name::WINDOWS:
            return "Windows";
        case Name::LINUX:
            return "Linux";
        case Name::MAC:
            return "macOS";
        default:
            return "Unknown operating system";
        }

    }

};

struct CpuArchitecture {

    enum class Name
    {
        X86_32,
        X86_64,
        ARM_32,
        ARM_64,
        UNKNOWN
    };

    static const char* getName(const Name name) {

        switch (name)
        {
        case Name::X86_32:
            return "x86 32-bit";
        case Name::X86_64:
            return "x86 64-bit";
        case Name::ARM_32:
            return "Arm 32-bit";
        case Name::ARM_64:
            return "Arm 64-bit";
        default:
            return "Unknown CPU";
        }

    }

};

//
// Prototype definitions
//
static OperatingSystem::Name checkOperatingSystem();
static CpuArchitecture::Name checkCpuArchitecture();
inline void printOsAndCpuNameToConsole(OperatingSystem::Name, CpuArchitecture::Name);

//
// Main method
//
int main()
{

    printOsAndCpuNameToConsole(checkOperatingSystem(), checkCpuArchitecture());
    return 0;
}

static OperatingSystem::Name checkOperatingSystem()
{
    #if defined(_WIN64) || defined(_WIN32)
        return OperatingSystem::Name::WINDOWS;
    #elif defined(__linux__)
        return OperatingSystem::Name::LINUX;
    #elif defined(__APPLE__)
        return OperatingSystem::Name::MAC;
    #endif

    return OperatingSystem::Name::UNKNOWN;
}

static CpuArchitecture::Name checkCpuArchitecture()
{

    #if defined(_M_IX86) || defined(__i386__)
        return CpuArchitecture::Name::X86_32;
    #elif defined(_M_X64) || defined(__x86_64__)
        return CpuArchitecture::Name::X86_64;
    #elif defined(_M_ARM) || defined(__ARM_ARCH) || defined(__arm__)
        return CpuArchitecture::Name::ARM_32;
    #elif defined(_M_ARM64) || defined(__aarch64__)
        return CpuArchitecture::Name::ARM_64;
    #endif

    return CpuArchitecture::Name::UNKNOWN;

}

inline void printOsAndCpuNameToConsole(const OperatingSystem::Name operatingSystem, const CpuArchitecture::Name cpuArchitecture)
{
    std::cout << "Running on OS: " << OperatingSystem::getName(operatingSystem) << " and CPU: " << CpuArchitecture::getName(cpuArchitecture) << '\n';
}