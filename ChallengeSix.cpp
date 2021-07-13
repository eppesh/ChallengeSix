#include "ChallengeSix.h"

namespace challengesix
{
void ChallengeSix::DrawUI(const int window_width /* = 800 */, const int window_height /* = 600 */)
{
    initgraph(window_width, window_height, EW_NOCLOSE | EW_NOMINIMIZE);  // 初始化窗体，去掉最小化及关闭按钮
    SetWindowLong(GetHWnd(), GWL_STYLE, GetWindowLong(GetHWnd(), GWL_STYLE) & ~WS_CAPTION);  // 去掉标题栏
    int caption_height = GetSystemMetrics(SM_CYCAPTION);  // 获取标题栏的高度
    SetWindowRgn(GetHWnd(), CreateRectRgn(0, caption_height, window_width, window_height - caption_height), true);  // 去掉黑色边框
    setbkcolor(RGB(6, 31, 62));
    cleardevice();

    DrawTitleAndTips();
}

void ChallengeSix::Play()
{
    while (true)
    {
        DrawNumbers(0, 0, 0);  // 游戏开始前,显示 0:00

        // TODO(Sean): 未对按键做限制,严格意义上应该只对"空格键"做出反应
        // 第一次按空格键开始游戏
        if (_getch() != VK_SPACE)
        {
            continue;
        }

        bool isStopLoop = false;

        for (int i = 0; i <= 9; ++i)  // 第1层循环,表示第1个数字,秒
        {
            if (isStopLoop)
            {
                break;
            }
            for (int j = 0; j <= 9; ++j)  // 第2层循环,表示第2个数字
            {
                if (isStopLoop)
                {
                    break;
                }
                for (int k = 0; k <= 9; ++k)  // 第3层循环,表示第3个数字
                {
                    if (_kbhit())  // 若有按键,返回true
                    {
                        isStopLoop = true;
                        break;
                    }
                    DrawNumbers(i, j, k);
                    HighPrecisionSleep(10);  // 适当延迟，使程序运行接近实际时间流逝（用Sleep(1)会比实际慢很多）                    
                } // end of k
            } // end of j
        } // end of i
        _getch();  // 第二次按键则游戏暂停        
        _getch();  // 第三次按键游戏重新开始
    }
}

void ChallengeSix::HighPrecisionSleep(const int ms)
{
    static clock_t last_clock = clock();  // 静态变量,记录上一个时钟
    last_clock += ms * CLOCKS_PER_SEC / 1000;  // 更新时钟
    if (clock() > last_clock)
    {
        last_clock = clock();
    }
    else
    {
        while (clock() < last_clock)
        {
            Sleep(1);
        }
    }
}

void ChallengeSix::DrawTitleAndTips()
{
    RECT title_rect = { 240,80,560,160 };
    settextcolor(RGB(163, 212, 255));  // 浅蓝色
    settextstyle(80, 0, L"楷体");
    drawtext(L"挑战6秒", &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);  // 在指定区域内以指定格式输出字符串

    settextcolor(RGB(254, 218, 168));  // 浅黄色（米黄色）
    settextstyle(20, 0, L"楷体");
    outtextxy(160, 450, L"提示：按“空格键”开始，再按暂停，继续按将置零！");  // 在指定位置输出字符串

    settextcolor(RGB(252, 191, 116));  // 暗黄色
    outtextxy(160, 480, L"准确暂停到6秒整则挑战成功！");
}

// 在屏幕上绘制3个数字，形如0:00（两个点也以圆圈方式显示）
void ChallengeSix::DrawNumbers(const int first_num, const int second_num, const int third_num)
{
    // 显示第1个数字
    SevenSegmentDisplay::DrawNumber(first_num, 80, 180, RGB(6, 31, 62));

    // 绘制上下两个小圆圈（渐变色）
    setfillcolor(RGB(64, 157, 254));  // 蓝色
    solidcircle(320, 240, 15);  // 画圆

    setfillcolor(RGB(163, 212, 255));  // 浅蓝色
    solidcircle(320, 360, 15);

    // 显示第2、3个数字
    SevenSegmentDisplay::DrawNumber(second_num, 400, 180, RGB(6, 31, 62));
    SevenSegmentDisplay::DrawNumber(third_num, 560, 180, RGB(6, 31, 62));
}

} // namespace challengesix