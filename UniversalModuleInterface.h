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

    virtual ERROR_TYPE executeCommand(char *command);

    virtual iWORD * getStack();

    virtual iWORD * getDictionary(size_t startAdr, size_t size);

    virtual void setStack(iWORD *data);

    virtual void setDictionary(iWORD *data, size_t startAdr, size_t size);

    virtual const char * getInputString();

    virtual const char * getInputChar();

};

#endif //FMPML_UNIVERSALMODULEINTERFACE_H
