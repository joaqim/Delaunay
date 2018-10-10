#define GLEW_STATIC

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#include "GUI.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

namespace jq {

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
 private:
    GUI m_GUI;
  };
  /* macro to detect where GL errors happens */
#define CHECK_GL_ERROR __CheckForGLError(__FILE__, __LINE__)


} // namespace jq
