#ifndef CFT_WITHIN_EXCEPTION
#define CFT_WITHIN_EXCEPTION 1

#include <exception>

namespace cft
{
class WithinException : public std::exception
{
};
}

#endif //CFT_WITHIN_EXCEPTION

