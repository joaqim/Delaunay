#include "GUI.h"

namespace jq {

int GUI::Init(GLFWwindow *pWindow) {

  // Setup Dear ImGui binding
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  m_io = ImGui::GetIO(); (void)m_io;

  // Initialize ImGui
  ImGui_ImplGlfwGL3_Init(pWindow, true);

  ImGui::StyleColorsDark();
  return 0;
}

void GUI::Render() {
  ImGui_ImplGlfwGL3_NewFrame(); 
  {

    ImGui::Begin("simple");
    static float f = 0.0f;
    ImGui::Text("Hello, world!");
    ImGui::SliderFloat("float", &f, 0.0f, 1.0f);
    // ImGui::ColorEdit3("clear color", (float*)&clear_color);
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
  }
  if(false){
    ImGui::Begin("");
    ImGui::BulletText("Double-click on title bar to collapse window.");
    ImGui::BulletText("Click and drag on lower right corner to resize window\n(double-click to auto fit window to its contents).");
    ImGui::BulletText("Click and drag on any empty space to move window.");
    ImGui::BulletText("TAB/SHIFT+TAB to cycle through keyboard editable fields.");
    ImGui::BulletText("CTRL+Click on a slider or drag box to input value as text.");
    if (ImGui::GetIO().FontAllowUserScaling)
      ImGui::BulletText("CTRL+Mouse Wheel to zoom window contents.");
    ImGui::BulletText("Mouse Wheel to scroll.");
    ImGui::BulletText("While editing text:\n");
    ImGui::Indent();
    ImGui::BulletText("Hold SHIFT or use mouse to select text.");
    ImGui::BulletText("CTRL+Left/Right to word jump.");
    ImGui::BulletText("CTRL+A or double-click to select all.");
    ImGui::BulletText("CTRL+X,CTRL+C,CTRL+V to use clipboard.");
    ImGui::BulletText("CTRL+Z,CTRL+Y to undo/redo.");
    ImGui::BulletText("ESCAPE to revert.");
    ImGui::BulletText("You can apply arithmetic operators +,*,/ on numerical values.\nUse +- to subtract.");
    ImGui::Unindent();
    ImGui::End();
  }

  ImGui::Render();
  ImGui_ImplGlfwGL3_RenderDrawData(ImGui::GetDrawData());
}


}
