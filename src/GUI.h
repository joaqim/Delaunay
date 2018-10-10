#include <imgui.h>
#include <imgui_impl_glfw_gl3.h>

#include <imguifilesystem.h>

#include <stdio.h>

namespace jq {
  class GUI {
 public:
    GUI() = default;

    int Init(GLFWwindow *pWindow);
    void Render();

 private:
    ImGuiIO m_io;
  };

}
