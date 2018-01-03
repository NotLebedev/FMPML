//
// Created by leog on 03.01.2018.
//

#ifndef FMPML_UNIVERSALMODULEINTERFACE_H
#define FMPML_UNIVERSALMODULEINTERFACE_H

#include <string>

#define ERROR_TYPE std::int8_t
#define iWORD std::int32_t

class UniversalModuleInterface {

public:

    virtual ERROR_TYPE executeCommand(std::string& command) = 0;

    virtual ERROR_TYPE getStack(iWORD *data) = 0;

    virtual ERROR_TYPE getDictionary(iWORD *data, size_t startAdr, size_t endAdr) = 0;

};

#endif //FMPML_UNIVERSALMODULEINTERFACE_H
