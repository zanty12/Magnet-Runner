#pragma once
#include "vendor/ImGui/imgui.h"
#include "vendor/ImGui/imgui_impl_win32.h"
#include "vendor/ImGui/imgui_impl_dx11.h"
#include <d3d11.h>

void ImGuiInit(HWND hwnd, ID3D11Device* device, ID3D11DeviceContext* deviceContext);
void ImGuiUninit();
void ImGuiBeginDraw();
void ImGuiEndDraw();