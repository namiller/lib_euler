package(default_visibility = ["//visibility:public"])

cc_library(
  name = "iterables",
  srcs = ["subset.cpp"],
  hdrs = ["permutation.h", "subset.h"],
)

cc_test(
  name = "permutation_test",
  srcs = ["permutation_test.cpp"],
  deps = [
      "//external:gtest",
      ":iterables"
      ],
)

cc_test(
  name = "subset_test",
  srcs = ["subset_test.cpp"],
  deps = [
      "//external:gtest",
      ":iterables"
      ],
)

cc_binary(
  name = "demo",
  srcs = ["demo.cpp"],
  deps = [
      ":iterables",
      "//euler/serialize"
      ]
)
