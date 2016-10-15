#ifndef ITERABLES_SUBSET_H
#define ITERABLES_SUBSET_H
#include <set>
#include <vector>

void next_subset(int n, std::vector<int> &ss);
// TODO: remove data duplication... make reference pass through.
template<typename E>
class SubsetIterable {
 public:
  using value_type = std::set<E>;
  class iterator {
   public:
    iterator(std::set<E> s, int n, bool incremented = false) {
      universe = s;
      incred = incremented;
      for (int i = 0; i < n; i++) {
        idxs.push_back(i);
      }
    }
    iterator& operator++() {
      next_subset(universe.size() - 1, idxs);
      incred = true;
      return *this;
    }
    // behavior undefined if iterators are of differant sets.
    bool operator==(const iterator &rhs) const {
      return idxs == rhs.idxs && incred == rhs.incred;
    }
    bool operator!=(const iterator &rhs) const {
      return idxs != rhs.idxs || incred != rhs.incred;
    }
    std::set<E> operator*() {
      int i = 0;
      int j = 0;
      std::set<E> ret;
      for (const auto & v : universe) {
        if (idxs[j] == i) {
          ret.insert(v);
          j++;
        }
        if (j == idxs.size()) {
          break;
        }
        i++;
      }
      return ret;
    }
   private:
    std::set<E> universe;
    std::vector<int> idxs;
    bool incred;
  };
  using const_iterator = iterator;
  SubsetIterable() = delete;
  SubsetIterable(const std::set<E>& s, int n) {
    univ = s;
    size = n;
  }
  iterator cbegin() const {
    return const_iterator(univ, size);
  }
  iterator cend() const {
    return const_iterator(univ, size, true);
  }
  iterator begin() const {
    return iterator(univ, size);
  }
  iterator end() const {
    return iterator(univ, size, true);
  }
 private:
  std::set<E> univ;
  int size;
};

template<typename E>
SubsetIterable<E> subsets(const std::set<E>& v, int size) {
  return std::move(SubsetIterable<E>(v, size));
}

#endif //ITERABLES_SUBSET_H
