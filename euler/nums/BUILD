package(default_visibility = ["//visibility:public"])

cc_library(
		name = "nums",
		srcs = [
				"primes.cpp",
				"theory.cpp",
		],
		hdrs = [
				"primes.h",
				"theory.h",
		],
)

cc_test(
		name = "theory_test",
		srcs = ["theory_test.cpp"],
		deps = [
				"//external:gtest",
				":nums",
		],
)

cc_test(
		name = "prime_test",
		srcs = ["prime_test.cpp"],
		deps = [
				"//external:gtest",
				":nums",
		],
)

