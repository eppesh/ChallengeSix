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
    void DrawUI(const int window_width = 800, const int window_height = 600);  // ������Ϸ������
    void Play();    // ��Ϸ������

private:
    void DrawTitleAndTips();    // ���Ʊ��⼰��ʾ��Ϣ
    void DrawNumbers(const int first_num, const int second_num, const int third_num);  // ��������(����0:00)
    void HighPrecisionSleep(const int ms);  // �߾�����ʱ����,ʹ������ʾ���������ӽ�ʵ�ʵ�ʱ������(��ȷ��1ms)
};

} // namespace challengesix
#endif