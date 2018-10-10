#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#define GLM_ENABLE_EXPERIMENTAL // For glm::transform
#include <glm/gtx/transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>


#ifndef GLFW_TRUE
#define GLFW_TRUE  1
#define GLFW_FALSE 0
#endif

#include "GUI.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include <ctime>
#include <cstdlib>

#include <svData.h>
#include <random>
#include <svVoronoiCore.h>
#include <iostream>


namespace jq {
  
  struct Vertex {
    Vertex() = default;

   Vertex(float const x_, float const y_, float const z_) :
    x(x_), y(y_), z(z_) {};
    float x, y, z;
  };

  struct Color {
    Color() = default;
    ~Color() = default;

   Color(float r_, float g_, float b_, float a_=1.f) :
    r(r_), g(g_), b(b_), a(a_) {}
    GLfloat r,g,b,a;
  };

  using std::cout;
  using std::endl;


  class Application {
 public:
    Application() = default;

    int Init();
    int Exec(int argc, char* argv[]);
    void Update();
    void Render();
    void CleanUp();

    std::string ReadShaderSource(std::string const &fname);

    GLuint LoadAndCompileShader(std::string const &fname, GLenum shaderType);
    GLuint CreateShaderProgram(const char *path_vert_shader, const char *path_frag_shader);
    void static OpenGLKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    void OpenGLResizeCallback(GLFWwindow* window, int new_width, int new_height);
    bool OpenGLTestNVX();

 private:
    void CreateColors(int const count);

 private:
      void static  APIENTRY OpenGLDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userparam);
      void  __CheckForGLError(const char* filename, int line);


   private:

      GLFWwindow  *m_pWindow;
      GLFWmonitor *m_pMonitor;

      bool m_bFullscreen = false;
      bool m_bDebugcontext = true;

      int m_iWindowWidth;
      int m_iWindowHeight;


      GLuint m_vertexArrayID;
      GLuint m_vertexBuffer;

      GLuint m_vertexVertices;
   private:
      glm::quat quaternion;
      glm::mat4 myMatrix;
      glm::vec3 myVector;
   private:
      GUI m_GUI;

      sv::SphericalVoronoiCore *voronoi;
      std::vector<Color> _colors;
    };
    /* macro to detect where GL errors happens */
#define CHECK_GL_ERROR __CheckForGLError(__FILE__, __LINE__)


} // namespace jq
