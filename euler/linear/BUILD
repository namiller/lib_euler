cc_library(
  name = "linear",
  srcs = ["matrix.cpp"],
  hdrs = ["matrix.h", "vector.h"],
)

cc_test(
  name = "matrix_test",
  srcs = ["matrix_test.cpp"],
  deps = [
      "//external:gtest",
      ":linear"],
)

cc_binary(
  name = "demo",
  srcs = ["demo.cpp"],
  deps = [
      ":linear"
      ],
)
