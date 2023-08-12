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
			float width = textprop.size.x * 632.0f;
			//put text into textList
			TEXT text;
			text.content = word;
			text.pos = cur_Pos;
			textList.push_back(text);
			//update cur_Pos
			cur_Pos.x += width + 8.0f;
		}
		else if (word == ' ') {
			cur_Pos.x += 80.0f;
		}
	}
}

void DrawText() {
	for(TEXT text : textList) {
		//Draw text
		DrawSprite(texNo, text.pos.x, text.pos.y, textconversion[text.content].size.x * 632.0f, textconversion[text.content].size.y * 632.0f, textconversion[text.content].uv.x, textconversion[text.content].uv.y, textconversion[text.content].size.x, textconversion[text.content].size.y);
	}
}

void ClearText() {
	textList.clear();
}