#ifndef PRINTING_H
#define PRINTING_H
#include <functional>
#include <string>
#include <sstream>
#include <iomanip>
#include <type_traits>


// adapted from: http://stackoverflow.com/a/7728728
template<typename T>
struct is_container {
private:
  template<typename C> static char test(typename C::const_iterator*);
  template<typename C> static int test(...);
public:
  enum {value = sizeof(test<T>(0)) == sizeof(char)};
};

template<typename T>
struct has_value_type {
private:
  template<typename C> static char test(typename C::value_type*);
  template<typename C> static int test(...);
public:
  enum {value = sizeof(test<T>(0)) == sizeof(char)};
};


template<typename C>
struct contained_type {
  typedef typename C::value_type type;
};

template<typename C>
struct pass_through {
  typedef C type;
};

template<typename C, typename D = void>
struct contained_type_or {
  typedef typename std::conditional<has_value_type<C>::value, contained_type<C>, pass_through<D> >::type::type type;
};
// extracts the first recursively contained type that is not a container.
template<typename C, bool is_container = has_value_type<C>::value>
struct bottom_type;

template<typename C>
struct bottom_type<C, true> {
  typedef typename bottom_type<typename C::value_type>::type type;
};

template<typename C>
struct bottom_type<C, false> {
  typedef C type;
};


template<typename Num>
std::string p_adapter(Num f, int prec) {
  std::ostringstream out;
  out << std::fixed << std::setprecision(prec) << f;
  return move(out.str());
}

template<typename Num>
std::string id_adapter(Num x) {
  std::ostringstream out;
  out << x;
  return std::move(out.str());
}

template<typename E>
//typename std::enable_if<!(is_container<E>::value && has_value_type<E>::value), std::string>::type
std::string
to_string(E elm, std::string(* adapter)(E) ) {
//to_string(E elm, std::function<std::string(E)> adapter) {
  return adapter(elm);
}

template<typename C, typename E = typename bottom_type<C>::type >
//typename std::enable_if<(is_container<C>::value && has_value_type<C>::value), std::string>::type
std::string
to_string(C container, std::string(*adapter)(E) = id_adapter<E>) {
//to_string(C container, std::function<std::string(E)> adapter = id_adapter<E>) {
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
/*
template<typename E>
typename std::enable_if<!(is_container<E>::value && has_value_type<E>::value), std::string>::type
to_string(E val, std::string(*adapter)(E)) {
//to_string(E val, std::function<std::string(E)> adapter = id_adapter<E>) {
  return adapter(val);
}


// we want to accept a container and a function that transforms the type contained in the container to a string.
template<typename C>
typename std::enable_if<is_container<C>::value && has_value_type<C>::value, std::string>::type
to_string(C container, std::string(*adapter)(contained_type<C>) = id_adapter<contained_type<C> >) {
//to_string(C container, std::function<std::string(contained_type<C>)>& adapter = id_adapter<contained_type<C> >) {
//to_string(C container, std::function<std::string(typename contained_type<C>::type)>& adapter = id_adapter<typename contained_type<C>::type>) {
  std::ostringstream out;
  out << '[';
  for (const auto & m : container) {
    out << to_string(m, adapter);
    out << ", ";
  }
  std::string ret = out.str();
  ret.pop_back();
  ret.back() = ']';
  return ret;
}
*/
//template<typename C, typename E>
//std::



#endif //PRINTING_H
