#ifndef CHALLENGESIX_H_
#define CHALLENGESIX_H_

#include <time.h>
#include <conio.h>

#include <graphics.h>

#include "SevenSegmentDisplay.h"

namespace challengesix
{
class ChallengeSix
{
public:
    void DrawUI(const int window_width = 800, const int window_height = 600);  // 绘制游戏主界面
    void Play();    // 游戏主函数

private:
    void DrawTitleAndTips();    // 绘制标题及提示信息
    void DrawNumbers(const int first_num, const int second_num, const int third_num);  // 绘制数字(形如0:00)
    void HighPrecisionSleep(const int ms);  // 高精度延时函数,使程序显示的秒数更接近实际的时间流逝(精确到1ms)
};

} // namespace challengesix
#endif