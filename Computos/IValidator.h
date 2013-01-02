#ifndef IVALIDATOR_H
#define IVALIDATOR_H

namespace validations
{

struct IValidator
{
    virtual bool isValid() = 0;
};

}
#endif // IVALIDATOR_H
