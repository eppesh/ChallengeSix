#include "ChallengeSix.h"

namespace challengesix
{
void ChallengeSix::DrawUI(const int window_width /* = 800 */, const int window_height /* = 600 */)
{
    initgraph(window_width, window_height, EW_NOCLOSE | EW_NOMINIMIZE);  // ��ʼ�����壬ȥ����С�����رհ�ť
    SetWindowLong(GetHWnd(), GWL_STYLE, GetWindowLong(GetHWnd(), GWL_STYLE) & ~WS_CAPTION);  // ȥ��������
    int caption_height = GetSystemMetrics(SM_CYCAPTION);  // ��ȡ�������ĸ߶�
    SetWindowRgn(GetHWnd(), CreateRectRgn(0, caption_height, window_width, window_height - caption_height), true);  // ȥ����ɫ�߿�
    setbkcolor(RGB(6, 31, 62));
    cleardevice();

    DrawTitleAndTips();
}

void ChallengeSix::Play()
{
    while (true)
    {
        DrawNumbers(0, 0, 0);  // ��Ϸ��ʼǰ,��ʾ 0:00

        // TODO(Sean): δ�԰���������,�ϸ�������Ӧ��ֻ��"�ո��"������Ӧ
        // ��һ�ΰ��ո����ʼ��Ϸ
        if (_getch() != VK_SPACE)
        {
            continue;
        }

        bool isStopLoop = false;

        for (int i = 0; i <= 9; ++i)  // ��1��ѭ��,��ʾ��1������,��
        {
            if (isStopLoop)
            {
                break;
            }
            for (int j = 0; j <= 9; ++j)  // ��2��ѭ��,��ʾ��2������
            {
                if (isStopLoop)
                {
                    break;
                }
                for (int k = 0; k <= 9; ++k)  // ��3��ѭ��,��ʾ��3������
                {
                    if (_kbhit())  // ���а���,����true
                    {
                        isStopLoop = true;
                        break;
                    }
                    DrawNumbers(i, j, k);
                    HighPrecisionSleep(10);  // �ʵ��ӳ٣�ʹ�������нӽ�ʵ��ʱ�����ţ���Sleep(1)���ʵ�����ࣩܶ                    
                } // end of k
            } // end of j
        } // end of i
        _getch();  // �ڶ��ΰ�������Ϸ��ͣ        
        _getch();  // �����ΰ�����Ϸ���¿�ʼ
    }
}

void ChallengeSix::HighPrecisionSleep(const int ms)
{
    static clock_t last_clock = clock();  // ��̬����,��¼��һ��ʱ��
    last_clock += ms * CLOCKS_PER_SEC / 1000;  // ����ʱ��
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
    settextcolor(RGB(163, 212, 255));  // ǳ��ɫ
    settextstyle(80, 0, L"����");
    drawtext(L"��ս6��", &title_rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);  // ��ָ����������ָ����ʽ����ַ���

    settextcolor(RGB(254, 218, 168));  // ǳ��ɫ���׻�ɫ��
    settextstyle(20, 0, L"����");
    outtextxy(160, 450, L"��ʾ�������ո������ʼ���ٰ���ͣ�������������㣡");  // ��ָ��λ������ַ���

    settextcolor(RGB(252, 191, 116));  // ����ɫ
    outtextxy(160, 480, L"׼ȷ��ͣ��6��������ս�ɹ���");
}

// ����Ļ�ϻ���3�����֣�����0:00��������Ҳ��ԲȦ��ʽ��ʾ��
void ChallengeSix::DrawNumbers(const int first_num, const int second_num, const int third_num)
{
    // ��ʾ��1������
    SevenSegmentDisplay::DrawNumber(first_num, 80, 180, RGB(6, 31, 62));

    // ������������СԲȦ������ɫ��
    setfillcolor(RGB(64, 157, 254));  // ��ɫ
    solidcircle(320, 240, 15);  // ��Բ

    setfillcolor(RGB(163, 212, 255));  // ǳ��ɫ
    solidcircle(320, 360, 15);

    // ��ʾ��2��3������
    SevenSegmentDisplay::DrawNumber(second_num, 400, 180, RGB(6, 31, 62));
    SevenSegmentDisplay::DrawNumber(third_num, 560, 180, RGB(6, 31, 62));
}

} // namespace challengesix