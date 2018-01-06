#include "library.h"

#include <cmath>
#include <iostream>
#include <w32api/vadefs.h>
#include <cstring>
#include <unordered_map>

UniversalModuleInterface *moduleInterface;

const char *FLOAT = "FLOAT";
const char *FOUT =  "F.";
const char *FADD =  "F+";
const char *FSUB =  "F-";
const char *FMUL =  "F*";
const char *FDIV =  "F/";
const char *FSQRT = "FSQRT";
const char *FTOI =  "FTOI";
const char *ITOF =  "ITOF";

std::unordered_map<std::string, size_t> commands = {
        {FLOAT, 0},
        {FOUT,  1},
        {FADD,  2},
        {FSUB,  3},
        {FMUL,  4},
        {FDIV,  5},
        {FSQRT, 6},
        {FTOI,  7},
        {ITOF,  8}
};

std::vector<std::string> __declspec(dllexport) __stdcall f_init(UniversalModuleInterface *universalModuleInterface) {

    moduleInterface = universalModuleInterface;

    std::vector<std::string> words = {FLOAT, FOUT, FADD, FSUB, FMUL, FDIV, FSQRT, FTOI, ITOF};

    return words;

}

void __declspec(dllexport) __stdcall f_delete() {

    delete moduleInterface;

}

void __declspec(dllexport) __stdcall f_execWord(char *word) {

    iWORD *tmp1;
    iWORD *tmp2;
    float f;
    const char *str;

    auto got = commands.find(word);

    if(got._M_cur) {

        switch (got->second) {
            case 0:

                str = moduleInterface->getInputString();

                f = std::strtof(str, nullptr);

                moduleInterface->setStack((iWORD*)(&f));

                break;
            case 1:

                tmp1 = moduleInterface->getStack();

                printf("%f", *(float*)(tmp1));

                break;
            case 2:

                tmp2 = moduleInterface->getStack();
                tmp1 = moduleInterface->getStack();

                f = *(float *)(tmp1) + *(float *)(tmp2);

                moduleInterface->setStack((iWORD*)(&f));

                break;
            case 3:

                tmp2 = moduleInterface->getStack();
                tmp1 = moduleInterface->getStack();

                f = *(float *)(tmp1) - *(float *)(tmp2);

                moduleInterface->setStack((iWORD*)(&f));

                break;
            case 4:

                tmp2 = moduleInterface->getStack();
                tmp1 = moduleInterface->getStack();

                f = *(float *)(tmp1) * *(float *)(tmp2);

                moduleInterface->setStack((iWORD*)(&f));

                break;
            case 5:

                tmp2 = moduleInterface->getStack();
                tmp1 = moduleInterface->getStack();

                f = *(float *)(tmp1) / *(float *)(tmp2);

                moduleInterface->setStack((iWORD*)(&f));

                break;
            case 6:

                tmp1 = moduleInterface->getStack();

                f = std::sqrt(*(float *)(tmp1));

                moduleInterface->setStack((iWORD*)(&f));

                break;
            case 7:

                tmp1 = moduleInterface->getStack();

                f = *(float *)(tmp1);
                *tmp1 = (iWORD)f;

                moduleInterface->setStack(tmp1);

                break;
            case 8:

                tmp1 = moduleInterface->getStack();

                f = (float)(*tmp1);

                moduleInterface->setStack((iWORD*)(&f));

                break;
            default:
                break;
        }

    }

}
