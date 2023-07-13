#include "text.h"


ID2D1RenderTarget * g_RT = NULL;
ID2D1SolidColorBrush * g_Brush = NULL;
IDWriteTextFormat * g_TextFormat = NULL;

void InitText() {
	g_RT = GetDWRenderTarget();
	g_Brush = GetDWSolidColorBrush();
	g_TextFormat = GetDWTextFormat();

}


void WriteText(const WCHAR* text,float X,float Y,float Width,float Height)
{
	g_RT->BeginDraw();
	g_RT->DrawText(text, wcslen(text), g_TextFormat, D2D1::RectF(X, Y, X + Width, Y + Height), g_Brush);
	g_RT->EndDraw();
}
