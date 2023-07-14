#include "gui.h"
#include "main.h"

void ImGuiInit(HWND hwnd, ID3D11Device* device, ID3D11DeviceContext* deviceContext)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui_ImplWin32_Init(hwnd);
	ImGui_ImplDX11_Init(device, deviceContext);

	ImGui::StyleColorsDark();
	//ついでに日本語フォントも追加
	io.Fonts->AddFontFromFileTTF("data/TEXTURE/NotoSansJP-Bold.ttf", 20.0f, nullptr, io.Fonts->GetGlyphRangesJapanese());
	io.MouseDrawCursor = true;
	
}

void ImGuiUninit()
{
	ImGui_ImplDX11_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
}

void ImGuiBeginDraw()
{
	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
}

void ImGuiEndDraw()
{
	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
}

