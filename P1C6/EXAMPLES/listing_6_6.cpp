// Listing 6-6

// narrow_cast is a named conversion that checks for narrowing conversions at runtime. It uses static_cast to perform the conversion and then checks if the value can be converted back to the original type without loss of information. If the check fails, it throws a runtime error.

#include <stdexcept>
// narrow_cast function template takes two template parameters: the type you are casting To and the type you are casting From.
template <typename To, typename From>
// The return type of narrow_cast is the type of To, and the type of the parameter value is From.
To narrow_cast(From value) {
    // static_cast performs the actual conversion from From to To. The result is stored in a variable named converted.
    const auto converted = static_cast<To>(value);
    // The conversion in the opposite direction is performed to check if the original value can be recovered without loss of information. If the value after converting back to From is not equal to the original value, it means that a narrowing conversion has occurred, and a runtime error is thrown.
    const auto backwards = static_cast<From>(converted);
    if(value != backwards) throw std::runtime_error{"Narrowed!"};
    // If no narrowing has occurred, return the converted value.
    return converted;
}