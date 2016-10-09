package(default_visibility = ["//visibility:public"])

cc_library(
  name = "introspection",
  srcs = [],
  hdrs = ["containers.h"],
)

cc_test(
  name = "containers_test",
  srcs = ["containers_test.cpp"],
  deps = [
      "//external:gtest",
      ":introspection"
      ],
)

