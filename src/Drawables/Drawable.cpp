#include "Drawables/Drawable.h"

std::ostream& Drawable::print(std::ostream &os) const {
    return os << "Drawable\n";
}

std::ostream& operator << (std::ostream& os, const Drawable& d){
    return d.print(os);
}