AUTOMAKE_OPTIONS = subdir-objects #foreign
#ACLOCAL_AMFLAGS = $(ACLOCAL_FLAGS)# $(AM_CXXFLAGS)
bin_PROGRAMS = main
main_SOURCES = main.cpp Application.cpp GUI.cpp

main_LDADD = $(DEPS_LIBS) libImgui.la "@x_libs@" libDelaunay.la $(BOOST_FILESYSTEM_LDFLAGS)
main_DEPENDENCIES =  libImgui.la libDelaunay.la $(BOOST_FILESYSTEM_LIBS)

#foo_LDFLAGS = $(BOOST_THREAD_LDFLAGS)
#foo_LIBS = $(BOOST_THREAD_LIBS)

main_CPPFLAGS = $(DEPS_CFLAGS) $(BOOST_CPPFLAGS) \
 -I$(top_srcdir)/third_party/repos/imgui \
 -I$(top_srcdir)/third_party/repos/imgui/examples/opengl3_example \
 -I$(top_srcdir)/third_party/repos/imgui/examples/opengl2_example \
 -I$(top_srcdir)/third_party/repos/cppdelaunay \
 -I$(top_srcdir)/third_party/include \
 -I$(top_srcdir)/include

# ImGui Library
noinst_LTLIBRARIES = libImgui.la
noinst_HEADERS = ../third_party/repos/imgui/imgui.h
libImgui_la_LDFLAGS = -static
libImgui_la_SOURCES = ../third_party/repos/imgui/imgui.cpp \
		      ../third_party/repos/imgui/imgui_draw.cpp \
		      ../third_party/include/imguifilesystem.cpp

if GL3
libImgui_la_SOURCES += ../third_party/repos/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.cpp
noinst_HEADERS += ../third_party/repos/imgui/examples/opengl3_example/imgui_impl_glfw_gl3.h
else
libImgui_la_SOURCES += ../third_party/repos/imgui/examples/opengl2_example/imgui_impl_glfw_gl2.cpp
noinst_HEADERS += ../third_party/repos/imgui/examples/opengl2_example/imgui_impl_glfw_gl2.h
endif

libImgui_la_CPPFLAGS = $(GL_CFLAGS) $(AM_CXXFLAGS)

libImgui_la_CPPFLAGS += -I$(top_srcdir)/third_party/repos/imgui -I$(top_srcdir)/third_party/repos/imgui/examples/libs/glfw/ -I$(top_srcdir)/third_party/repos/ #-std=c++17

# cppdelaunay https://github.com/SirAnthony/cppdelaunay

#libDelaunay_la_LDFLAGS = -static
noinst_LTLIBRARIES += libDelaunay.la

#libDelaunay_la_CPPFLAGS = -g -O0

main_CPPFLAGS += -I$(top_srcdir)/third_party/repos/cppdelaunay

libDelaunay_la_CPPFLAGS = -I$(top_srcdir)/third_party/repos/cppdelaunay

libDelaunay_la_SOURCES = \
../third_party/repos/cppdelaunay/delaunay/Edge.cpp \
../third_party/repos/cppdelaunay/delaunay/EdgeList.cpp \
../third_party/repos/cppdelaunay/delaunay/EdgeReorderer.cpp \
../third_party/repos/cppdelaunay/delaunay/Functions.cpp \
../third_party/repos/cppdelaunay/delaunay/Halfedge.cpp \
../third_party/repos/cppdelaunay/delaunay/HalfedgePriorityQueue.cpp \
../third_party/repos/cppdelaunay/delaunay/ICoord.cpp \
../third_party/repos/cppdelaunay/delaunay/kruskal.cpp \
../third_party/repos/cppdelaunay/delaunay/LR.cpp \
../third_party/repos/cppdelaunay/delaunay/Site.cpp \
../third_party/repos/cppdelaunay/delaunay/SiteList.cpp \
../third_party/repos/cppdelaunay/delaunay/Vertex.cpp \
../third_party/repos/cppdelaunay/delaunay/Voronoi.cpp \
../third_party/repos/cppdelaunay/geom/Circle.cpp \
../third_party/repos/cppdelaunay/geom/LineSegment.cpp \
../third_party/repos/cppdelaunay/geom/Point.cpp \
../third_party/repos/cppdelaunay/geom/Rectangle.cpp \
../third_party/repos/cppdelaunay/geom/Polygon.cpp \
../third_party/repos/cppdelaunay/geom/Triangle.cpp

noinst_HEADERS += \
../third_party/repos/cppdelaunay/delaunay/Edge.h \
../third_party/repos/cppdelaunay/delaunay/EdgeList.h \
../third_party/repos/cppdelaunay/delaunay/EdgeReorderer.h \
../third_party/repos/cppdelaunay/delaunay/Functions.h \
../third_party/repos/cppdelaunay/delaunay/Halfedge.h \
../third_party/repos/cppdelaunay/delaunay/HalfedgePriorityQueue.h \
../third_party/repos/cppdelaunay/delaunay/ICoord.h \
../third_party/repos/cppdelaunay/delaunay/kruskal.h \
../third_party/repos/cppdelaunay/delaunay/LR.h \
../third_party/repos/cppdelaunay/delaunay/Site.h \
../third_party/repos/cppdelaunay/delaunay/SiteList.h \
../third_party/repos/cppdelaunay/delaunay/Vertex.h \
../third_party/repos/cppdelaunay/delaunay/Voronoi.h \
../third_party/repos/cppdelaunay/geom/Circle.h \
../third_party/repos/cppdelaunay/geom/LineSegment.h \
../third_party/repos/cppdelaunay/geom/Point.h \
../third_party/repos/cppdelaunay/geom/Rectangle.h \
../third_party/repos/cppdelaunay/geom/Polygon.h \
../third_party/repos/cppdelaunay/geom/Triangle.h








