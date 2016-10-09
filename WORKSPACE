new_http_archive(
  name = "gtest_extern",
  url = "https://github.com/google/googletest/archive/release-1.8.0.zip",
  build_file = "gtest.BUILD",
  strip_prefix = "googletest-release-1.8.0",
)

bind(
  name = "gtest",
  actual = "@gtest_extern//:main",
)
