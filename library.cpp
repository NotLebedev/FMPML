#include "library.h"

#include <iostream>
#include <w32api/vadefs.h>

void hello() {
    std::cout << "Hello, World!" << std::endl;
}

std::vector<std::string> __declspec(dllexport) __stdcall f_init(UniversalModuleInterface *universalModuleInterface) {

    printf("Called f_init of FMPML");

    return std::vector<std::string>();

}

void __declspec(dllexport) __stdcall f_delete() {

    printf("Called f_delete of FMPML");

}

void __declspec(dllexport) __stdcall f_execWord(std::string word) {

    printf("Called f_execWord of FMPML");

}
