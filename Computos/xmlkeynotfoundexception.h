#ifndef XMLKEYNOTFOUNDEXCEPTION_H
#define XMLKEYNOTFOUNDEXCEPTION_H

#include <boost/exception/all.hpp>

namespace xml
{

class XMLKeyNotFoundException : public boost::exception
{
public:
    XMLKeyNotFoundException();
};

}
#endif // XMLKEYNOTFOUNDEXCEPTION_H
