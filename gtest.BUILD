cc_library(
    visibility = ["//visibility:public"],
    name = "main",
    srcs = glob(
        ["googletest/src/*.cc", "googlemock/src/*.cc"],
        exclude = ["googletest/src/gtest-all.cc", "googlemock/src/gmock-all.cc",
                   "googletest/src/gtest_main.cc"]
    ),
    hdrs = glob([
        "googletest/include/**/*.h",
        "googletest/src/*.h",
        "googlemock/include/**/*.h"
    ]),
    copts = [
        "-Iexternal/gtest_extern/googletest/include",
        "-Iexternal/gtest_extern/googlemock/include",
        "-Iexternal/gtest_extern/googlemock",
        "-Iexternal/gtest_extern/googletest"
    ],
    linkopts = ["-pthread", "-lgtest"],
)
