package(default_visibility = ["//visibility:public"])

cc_library(
  name = "serialize",
  srcs = [],
  hdrs = ["printing.h"],
)

cc_test(
  name = "printing_test",
  srcs = ["printing_test.cpp"],
  deps = [
          "@gtest//:main",
          ":serialize",
          "//introspection",
          ],
)

