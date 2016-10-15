#ifndef SERIALIZE_PRINTING_H
#define SERIALIZE_PRINTING_H
#include <string>
#include <sstream>
#include <iomanip>
#include <utility>
#include "euler/introspection/containers.h"

namespace eul {

  template<int prec, typename Num>
  std::string p_adapter(Num f) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(prec) << f;
    return out.str();
  }

  template<typename Num>
  std::string p_adapter(Num f, int prec) {
    std::ostringstream out;
    out << std::fixed << std::setprecision(prec) << f;
    return out.str();
  }

  template<typename Num>
  std::string id_adapter(Num x) {
    std::ostringstream out;
    out << x;
    return out.str();
  }

  template<typename T, typename U, std::string(*adapter1)(T) = id_adapter<T>, std::string(* adapter2)(U) = id_adapter<U> >
  std::string pair_adapter(std::pair<T, U> x) {
    return "<"+adapter1(x.first) + ", " + adapter2(x.second) + ">";
  }

  template<typename E>
  std::string to_string(E elm, std::string(* adapter)(E) ) {
    return adapter(elm);
  }

  template<typename C, typename E = typename bottom_type<C>::type >
  std::string to_string(C container, std::string(*adapter)(E) = id_adapter<E>) {
    std::ostringstream out;
    out << "[";
    for (const auto & m : container) {
      out << to_string(m, adapter);
      out << ", ";
    }
    std::string ret = out.str();
    ret.pop_back();
    ret.back() = ']';
    return ret;
  }

  template<typename C>
  contained_type<C> test(C cont) {
    contained_type<C> t;
    return t;
  }

}

#endif //SERIALIZE_PRINTING_H
