#include "library.h"

#include <iostream>
#include <w32api/vadefs.h>
#include <cstring>
#include <unordered_map>

UniversalModuleInterface *moduleInterface;

std::vector<std::string> __declspec(dllexport) __stdcall f_init(UniversalModuleInterface *universalModuleInterface) {

    moduleInterface = universalModuleInterface;

    std::vector<std::string> words = {"FLOAT", "F.", "F+", "F-", "F*", "F/"};

    return words;

}

void __declspec(dllexport) __stdcall f_delete() {

    delete moduleInterface;

}

void __declspec(dllexport) __stdcall f_execWord(char *word) {

    iWORD *tmp1;
    iWORD *tmp2;
    const char *str;

    if(strcmp("F.", word) == 0) {

        tmp1 = moduleInterface->getStack();

        printf("%f", *(float*)(tmp1));

    } else if(strcmp("FLOAT", word) == 0) {

        float f;

        str = moduleInterface->getInputString();

        f = std::strtof(str, nullptr);

        moduleInterface->setStack((iWORD*)(&f));

    } else if(strcmp("F+", word) == 0) {

        float f;

        tmp2 = moduleInterface->getStack();
        tmp1 = moduleInterface->getStack();

        f = *(float *)(tmp1) + *(float *)(tmp2);

        moduleInterface->setStack((iWORD*)(&f));

    } else if(strcmp("F-", word) == 0) {

        float f;

        tmp2 = moduleInterface->getStack();
        tmp1 = moduleInterface->getStack();

        f = *(float *)(tmp1) - *(float *)(tmp2);

        moduleInterface->setStack((iWORD*)(&f));

    } else if(strcmp("F*", word) == 0) {

        float f;

        tmp2 = moduleInterface->getStack();
        tmp1 = moduleInterface->getStack();

        f = *(float *)(tmp1) * *(float *)(tmp2);

        moduleInterface->setStack((iWORD*)(&f));

    } else if(strcmp("F/", word) == 0) {

        float f;

        tmp2 = moduleInterface->getStack();
        tmp1 = moduleInterface->getStack();

        f = *(float *)(tmp1) / *(float *)(tmp2);

        moduleInterface->setStack((iWORD*)(&f));

    }


}
