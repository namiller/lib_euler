#ifndef CONTAINERS_H
#define CONTAINERS_H
#include <type_traits>

namespace eul {

  template<typename T>
  struct has_citerator {
   private:
    template<typename C> static char check(typename C::const_iterator*);
    template<typename C> static int check(...);
   public:
    static const bool value = sizeof(check<T>(0)) == sizeof(char);
  };

  template<typename T>
  struct has_value_type {
   private:
    template<typename C> static char check(typename C::value_type*);
    template<typename C> static int check(...);
   public:
    static const bool value = sizeof(check<T>(0)) == sizeof(char);
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
  template<typename C, bool is_container = has_value_type<C>::value && has_citerator<C>::value>
  struct bottom_type;

  template<typename C>
  struct bottom_type<C, true> {
    typedef typename bottom_type<typename C::value_type>::type type;
  };

  template<typename C>
  struct bottom_type<C, false> {
    typedef C type;
  };

}
#endif //CONTAINERS_H
