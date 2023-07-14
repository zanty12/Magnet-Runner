#include "title.h"
#include "scenemngr.h"
#include "main.h"
#include "input.h"
#include "sprite.h"
#include "vendor/ImGui/imgui.h"
void Title::Init()
{
	titleTex_ = LoadTexture((char*)"data/TEXTURE/title.png");
	bgTex_ = LoadTexture((char*)"data/TEXTURE/title_bg.png");
}

void Title::Update()
{
	
}

void Title::Draw()
{
	DrawSprite(bgTex_,
		SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2,
		SCREEN_WIDTH, SCREEN_HEIGHT,
		0.0f, 0.0f,//UV値の始点
		1.0f, 1.0
	);
	DrawSprite(titleTex_,
		960, 264.0f,
		991.0f, 264.0f,
		0.0f, 0.0f,//UV値の始点
		1.0f, 1.0
	);
	ImGuiIO& io{ ::ImGui::GetIO() };
	io.DisplaySize.x = SCREEN_WIDTH;
	io.DisplaySize.y = SCREEN_HEIGHT;
	ImVec2 view = ImGui::GetContentRegionAvail();
	ImGui::Begin("123");
	//ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(1.0f, 1.0f, 1.0f, 0.0f));
	if (ImGui::Button(u8"ゲームスタート"))
	{
		mngr_->SetScene(SCENE_GAME);
	}
	if (ImGui::Button(u8"ゲーム終了"))
	{
		exit(1);
	}
	ImGui::End();
	
}