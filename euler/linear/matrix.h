#ifndef LINEAR_MATRIX_H
#define LINEAR_MATRIX_H
#include <array>
#include <iostream>
#include <initializer_list>

template<typename E, int height, int width = height>
class Mat {
 public:
  Mat() {}

	// TODO(namiller): Make this work correctly.
  Mat(std::initializer_list<std::initializer_list<E>> lst) {
    static_assert(lst.size() == height, "incorrect initializer height");
    int x = 0;
    int y = 0;
    for (const auto & row : lst) {
      static_assert(row.size() == width, "incorrect initializer width");
      for (const auto & e : row) {
        data[y][x] = e;
        x++;
      }
      y++;
    }
  }

  static Mat Eye() {
    static_assert(height == width, "Identity only defined for square matrix");
    Mat ret;
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        ret.data[y][x] = static_cast<E>(x==y); // I may want a constructor...
      }
    }
    return ret;
  }

  static Mat Unif(E v) {
    Mat ret;
    for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
        ret.data[y][x] = v;
      }
    }
    return ret;
  }

  static Mat Zeros() {
    return Unif(0);
  }

  static Mat Ones() {
    return Unif(1);
  }

  Mat operator+(const Mat<E, height, width> &rhs) const {
    Mat ret = *this;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        ret.data[y][x] += rhs.data[y][x];
      }
    }
    return ret;
  }

  // Implement for other order.
  Mat operator*(const E &rhs) const {
    Mat ret = *this;
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        ret.data[y][x] *= rhs;
      }
    }
    return std::move(ret);
  }

  Mat operator-(const Mat<E, height, width> &rhs) const {
    return *this+(rhs*static_cast<E>(-1));
  }

  bool operator==(const Mat<E, height, width> &rhs) const {
    if (rhs.w != w || rhs.h != h) {
      return false;
    }
    for (int y = 0; y < h; y++) {
      for (int x = 0; x < w; x++) {
        if (this->data[y][x] != rhs.data[y][x]) {
          return false;
        }
      }
    }
    return true;
  }

  typedef E value_type;
 private:
  static constexpr int h = height;
  static constexpr int w = width;
  std::array<std::array<E, width>, height> data;
};
// TODO(namiller): Implement matrix multiplication as a friend for the appropriate sizes.

#endif //LINEAR_MATRIX_H
