// 名称：七段展示类
// 版权：仅供学习交流
// 作者：Sean (eppesh@163.com)
// 环境：VS2019; EasyX 2021
// 时间：2021/07/12
// 说明："七段"按顺时针由内到外依次标记为A～G; 即A-上面短横,B-右边上侧短竖,C-右边下侧短竖,
//       D-下面短横短横,E-左边下侧短竖,F-左边上侧短竖,G-中间短横;

// 感谢：简单[2864292458@qq.com]; 本类以@简单同学制件的电子数字字体7模块为基础,进行了适当修改与整理。

#ifndef SEVEN_SEGMENT_DISPALY_H_
#define SEVEN_SEGMENT_DISPALY_H_

#include <graphics.h>

namespace challengesix
{
class SevenSegmentDisplay
{
public:
    // 在指定位置(x,y)处绘制“七段展示”样式的数字number; background_color建议设置成跟主窗体的背景色一致
    static void DrawNumber(const int number, const int x, const int y, const COLORREF background_color);

private:

    // 在指定位置(x,y)处绘制七段中的A段
    static void DrawSevenSegmentA(const int x, const int y);
    // 在指定位置(x,y)处绘制七段中的B段
    static void DrawSevenSegmentB(const int x, const int y);
    // 在指定位置(x,y)处绘制七段中的C段
    static void DrawSevenSegmentC(const int x, const int y);
    // 在指定位置(x,y)处绘制七段中的D段
    static void DrawSevenSegmentD(const int x, const int y);
    // 在指定位置(x,y)处绘制七段中的E段
    static void DrawSevenSegmentE(const int x, const int y);
    // 在指定位置(x,y)处绘制七段中的F段
    static void DrawSevenSegmentF(const int x, const int y);
    // 在指定位置(x,y)处绘制七段中的G段
    static void DrawSevenSegmentG(const int x, const int y);
};
} // namespace challengesix
#endif