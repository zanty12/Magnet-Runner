#include "text.h"
#include "texture.h"
#include "sprite.h"
#include "textprop.h"


std::vector<TEXT> textList;
static int texNo;

void InitText() {
	texNo = LoadTexture((char*)"data/TEXTURE/text.png");
}

void PrintText(std::string text, D3DXVECTOR2 pos) { //pos is the starting pos (top left)of the text
	D3DXVECTOR2 cur_Pos = pos;
	for(char word : text) {
		if (word != ' ' && word != '\n') {
			//get the width of the letter
			std::map<char, TEXTPROP>::iterator iter = textconversion.find(word);
			TEXTPROP textprop = iter->second;
			float width = textprop.size.x * 500.0f;
			//put text into textList
			TEXT text;
			text.content = word;
			text.pos = cur_Pos;
			text.scale = 1.0f;
			textList.push_back(text);
			//update cur_Pos
			cur_Pos.x += width + 8.0f;
		}
		else if (word == ' ') {
			cur_Pos.x += 80.0f;
		}
	}
}

void PrintText(std::string text, D3DXVECTOR2 pos, float scale) { //pos is the starting pos (top left)of the text
	D3DXVECTOR2 cur_Pos = pos;
	for (char word : text) {
		if (word != ' ' && word != '\n') {
			//get the width of the letter
			std::map<char, TEXTPROP>::iterator iter = textconversion.find(word);
			TEXTPROP textprop = iter->second;
			float width = textprop.size.x * 500.0f * scale;
			//put text into textList
			TEXT text;
			text.content = word;
			text.pos = cur_Pos;
			text.scale = scale;
			textList.push_back(text);
			//update cur_Pos
			cur_Pos.x += width + 8.0f * scale;
		}
		else if (word == ' ') {
			cur_Pos.x += 80.0f * scale;
		}
	}
}

float GetTextWidth(std::string text, float scale) {
	float x = 0.0f;
	for (char word : text) {
		if (word != ' ' && word != '\n') {
			//get the width of the letter
			std::map<char, TEXTPROP>::iterator iter = textconversion.find(word);
			TEXTPROP textprop = iter->second;
			float width = textprop.size.x * 500.0f * scale;
			//update cur_Pos
			x += width + 8.0f * scale;
		}
		else if (word == ' ') {
			x += 80.0f * scale;
		}
	}
	return x;
}

void DrawText() {
	for(TEXT text : textList) {
		//Draw text
		DrawSprite(texNo, text.pos.x + (textconversion[text.content].size.x * 500.0f * text.scale / 2), text.pos.y + (textconversion[text.content].size.y * 632.0f * text.scale / 2), textconversion[text.content].size.x * 500.0f * text.scale, textconversion[text.content].size.y * 632.0f * text.scale, textconversion[text.content].uv.x, textconversion[text.content].uv.y, textconversion[text.content].size.x, textconversion[text.content].size.y);
	}
}

void ClearText() {
	textList.clear();
}