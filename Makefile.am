AUTOMAKE_OPTIONS = foreign 
ACLOCAL_AMFLAGS = -I m4 --install
AM_CXXFLAGS = -fpic -Wall -Wextra -Werror -x c++ -isystem /usr/local/include -isystem /usr/include

# Windows
#AM_LDFLAGS = -lopengl32

if DEBUG
AM_CXXFLAGS +=-g3 -O0 -ggdb
else
AM_CXXFLAGS += -O2
endif

SUBDIRS = src doc examples man scripts tests
#SUBDIRS += third_party/repos/imgui

