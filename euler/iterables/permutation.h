#ifndef ITERABLES_PERMUTATION_H
#define ITERABLES_PERMUTATION_H
#include <vector>
#include <algorithm>

template<typename E>
class PermutationIterable {
 public:
  using value_type = std::vector<E>;
  class const_iterator {
   public:
    const_iterator(std::vector<E> s, bool incremented = false) {
      state = s;
      incred = incremented;
    }
    const_iterator& operator++() {
      next_permutation(state.begin(), state.end());
      incred = true;
      return *this;
    }
    bool operator==(const const_iterator &rhs) const {
      return state == rhs.state && incred == rhs.incred;
    }
    bool operator!=(const const_iterator &rhs) const {
      return state != rhs.state || incred != rhs.incred;
    }
    const std::vector<E>& operator*() {
      return state;
    }
   private:
    std::vector<E> state;
    bool incred;
  };
  class iterator {
   public:
    iterator(std::vector<E> s, bool incremented = false) {
      state = s;
      incred = incremented;
    }
    iterator& operator++() {
      next_permutation(state.begin(), state.end());
      incred = true;
      return *this;
    }
    bool operator==(const iterator &rhs) const {
      return state == rhs.state && incred == rhs.incred;
    }
    bool operator!=(const iterator &rhs) const {
      return state != rhs.state || incred != rhs.incred;
    }
    std::vector<E>& operator*() {
      return state;
    }
   private:
    std::vector<E> state;
    bool incred;
  };
  PermutationIterable() = delete;
  PermutationIterable(const std::vector<E>& v) {
    start = v;
  }
  const_iterator cbegin() const {
    return const_iterator(start);
  }
  const_iterator cend() const {
    return const_iterator(start, true);
  }
  //THESE SHOULD NOT BE USED.
  iterator begin() const {
    return iterator(start);
  }
  iterator end() const {
    return iterator(start, true);
  }
 private:
  std::vector<E> start;
};

template<typename E>
PermutationIterable<E> permutations(const std::vector<E>& v) {
  return std::move(PermutationIterable<E>(v));
}

#endif //ITERABLES_PERMUTATION_H
