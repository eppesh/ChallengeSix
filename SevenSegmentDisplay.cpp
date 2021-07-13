#include "SevenSegmentDisplay.h"

namespace challengesix
{
// 利用7段组合成0~9各数字
void SevenSegmentDisplay::DrawNumber(const int number, const int x, const int y, const COLORREF background_color)
{
    // 设置数字外包矩形区域,用于清除之前显示的数字,否则一直显示8
    setfillcolor(background_color);
    solidrectangle(x, y, x + 160, y + 240);

    switch (number)
    {
    case 0:
        DrawSevenSegmentA(x, y);
        DrawSevenSegmentB(x, y);
        DrawSevenSegmentC(x, y);
        DrawSevenSegmentD(x, y);
        DrawSevenSegmentE(x, y);
        DrawSevenSegmentF(x, y);
        break;
    case 1:
        DrawSevenSegmentB(x, y);
        DrawSevenSegmentC(x, y);
        break;
    case 2:
        DrawSevenSegmentA(x, y);
        DrawSevenSegmentB(x, y);
        DrawSevenSegmentG(x, y);
        DrawSevenSegmentE(x, y);
        DrawSevenSegmentD(x, y);
        break;
    case 3:
        DrawSevenSegmentA(x, y);
        DrawSevenSegmentB(x, y);
        DrawSevenSegmentG(x, y);
        DrawSevenSegmentC(x, y);
        DrawSevenSegmentD(x, y);
        break;
    case 4:
        DrawSevenSegmentF(x, y);
        DrawSevenSegmentG(x, y);
        DrawSevenSegmentB(x, y);        
        DrawSevenSegmentC(x, y);
        break;
    case 5:
        DrawSevenSegmentA(x, y);
        DrawSevenSegmentF(x, y);
        DrawSevenSegmentG(x, y);
        DrawSevenSegmentC(x, y);
        DrawSevenSegmentD(x, y);
        break;
    case 6:
        DrawSevenSegmentA(x, y);
        DrawSevenSegmentF(x, y);
        DrawSevenSegmentG(x, y);
        DrawSevenSegmentC(x, y);
        DrawSevenSegmentD(x, y);
        DrawSevenSegmentE(x, y);
        break;
    case 7:
        DrawSevenSegmentA(x, y);
        DrawSevenSegmentB(x, y);
        DrawSevenSegmentC(x, y);
        break;
    case 8:
        DrawSevenSegmentA(x, y);
        DrawSevenSegmentB(x, y);
        DrawSevenSegmentC(x, y);
        DrawSevenSegmentD(x, y);
        DrawSevenSegmentE(x, y);
        DrawSevenSegmentF(x, y);
        DrawSevenSegmentG(x, y);
        break;
    case 9:
        DrawSevenSegmentA(x, y);
        DrawSevenSegmentB(x, y);
        DrawSevenSegmentC(x, y);
        DrawSevenSegmentD(x, y);
        DrawSevenSegmentF(x, y);
        DrawSevenSegmentG(x, y);
        break;
    }
}

// 目前数字的大小是固定的
void SevenSegmentDisplay::DrawSevenSegmentA(const int x, const int y)
{
    // 两种方式:一是int points[],对应solidpolygon((POINT*)points, 6);二是下面的方式
    //int points[] = { 36 + x, 14 + y, 59 + x, 39 + y, 118 + x, 39 + y, 138 + x, 15 + y, 131 + x, 9 + y, 41 + x, 9 + y };
    POINT points[] = { {36 + x, 14 + y}, {59 + x, 39 + y}, {118 + x, 39 + y},
        {138 + x,15 + y},{131 + x, 9 + y}, {41 + x, 9 + y} };
    setfillcolor(RGB(176, 215, 254));  // 设置该分段的颜色为浅蓝色
    solidpolygon(points, 6);  // 使用当前线形和当前填充样式绘制无边框的填充6边形
}

void SevenSegmentDisplay::DrawSevenSegmentB(const int x, const int y)
{
    int points[] = { 143 + x, 20 + y, 152 + x, 31 + y, 144 + x, 105 + y,
        132 + x, 115 + y, 115 + x, 98 + y, 122 + x, 41 + y, };
    setfillcolor(RGB(187, 250, 255));  // 更浅的蓝色
    solidpolygon((POINT *)points, 6);
}

void SevenSegmentDisplay::DrawSevenSegmentC(const int x, const int y)
{
    int points[] = { 132 + x, 119 + y, 144 + x, 128 + y, 136 + x, 213 + y,
        129 + x, 222 + y, 107 + x, 201 + y, 115 + x, 134 + y };
    setfillcolor(RGB(245, 255, 190));
    solidpolygon((POINT *)points, 6);
}

void SevenSegmentDisplay::DrawSevenSegmentD(const int x, const int y)
{
    int points[] = { 40 + x, 203 + y, 104 + x, 203 + y, 126 + x, 226 + y,
        120 + x, 231 + y, 24 + x, 231 + y, 18 + x, 226 + y };
    setfillcolor(RGB(251, 221, 185));  // 暗黄色
    solidpolygon((POINT *)points, 6);
}

void SevenSegmentDisplay::DrawSevenSegmentE(const int x, const int y)
{
    int points[] = { 25 + x, 120 + y, 43 + x, 136 + y, 38 + x, 199 + y,
        15 + x, 223 + y, 6 + x, 209 + y, 15 + x, 127 + y };
    setfillcolor(RGB(245, 255, 192));  // 浅黄色
    solidpolygon((POINT *)points, 6);
}

void SevenSegmentDisplay::DrawSevenSegmentF(const int x, const int y)
{
    int points[] = { 32 + x, 17 + y, 53 + x, 40 + y, 47 + x, 96 + y,
        26 + x, 113 + y, 18 + x, 102 + y, 25 + x, 27 + y };
    setfillcolor(RGB(184, 249, 251));  // 更浅的蓝色
    solidpolygon((POINT *)points, 6);
}

void SevenSegmentDisplay::DrawSevenSegmentG(const int x, const int y)
{
    int points[] = { 46 + x, 101 + y, 113 + x, 101 + y, 127 + x, 116 + y,
        111 + x, 131 + y, 45 + x, 131 + y, 29 + x, 117 + y };
    setfillcolor(RGB(187, 254, 219));  // 很浅的绿色
    solidpolygon((POINT *)points, 6);
}


} // namespace challengesix