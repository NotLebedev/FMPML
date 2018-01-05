#ifndef FMPML_LIBRARY_H
#define FMPML_LIBRARY_H

#include <string>
#include <vector>
#include "UniversalModuleInterface.h"

std::vector<std::string> __declspec(dllexport) __stdcall f_init     (UniversalModuleInterface *universalModuleInterface);
void                     __declspec(dllexport) __stdcall f_delete   ();
void                     __declspec(dllexport) __stdcall f_execWord (char *word);

#endif