AUTOMAKE_OPTIONS = foreign -Wall -Werror

check_LTLIBRARIES = libgtest.la
libgtest_la_SOURCES = ../third_party/repos/googletest/googletest/src/gtest-all.cc
libgtest_la_CPPFLAGS = -I$(top_srcdir)/third_party/repos/googletest/googletest/include -I$(top_srcdir)/third_party/repos/googletest/googletest
libgtest_la_LDFLAGS = -pthread

check_PROGRAMS = gtest demo
gtest_SOURCES = gtest.cpp
gtest_LDADD = libgtest.la
gtest_LDFLAGS = -pthread
gtest_CPPFLAGS = -I$(top_srcdir)/third_party/repos/googletest/googletest/include\
	-I$(top_srcdir)/third_party/repos/googletest/googletest \
	-I$(top_srcdir)/src

demo_SOURCES = demo.cpp
demo_CPPFLAGS = -I$(top_srcdir)/src

TESTS = gtest
