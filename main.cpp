// 名称：挑战6秒
// 版权：
// 作者：Sean (eppesh@163.com)
// 环境：VS2019;EasyX 2021
// 时间：2021/07/11
// 说明：准确暂停到6秒整算挑战成功。本程序以 简单(2864292458@qq.com)同学的挑战六秒程序为基础，添加了相应注释，增加了部分新功能。

// 感谢：简单[2864292458@qq.com] (https://codebus.cn/luoyh/challenge)

#include <conio.h>
#include <time.h>
#include <thread>

#include <graphics.h>

#include "resource.h"
#include "ChallengeSix.h"

using namespace challengesix;

// 拖动窗体
void DragForm(const int form_width, const int form_height)
{
    MOUSEMSG mouse_msg;  // 定义鼠标消息
    int caption_height = GetSystemMetrics(SM_CYCAPTION);  // 标题栏高度
    IMAGE close_image;
    loadimage(&close_image, _T("PNG"), MAKEINTRESOURCE(IDB_CLOSE));
    int close_width = close_image.getwidth();
    int close_height = close_image.getheight();

    while (true)
    {
        mouse_msg = GetMouseMsg();  // 获取一条鼠标消息        

        // 鼠标停在关闭贴图上方时
        if (mouse_msg.x >= (form_width - close_width - 1) && mouse_msg.x <= form_width && mouse_msg.y >= 0 && mouse_msg.y <= (caption_height + close_height))
        {
            putimage(form_width - close_width - 1, caption_height, &close_image, SRCPAINT);
        }
        else
        {
            setfillcolor(RGB(6, 31, 62));
            setlinecolor(RGB(6, 31, 62));
            fillrectangle(form_width - close_width - 1, caption_height, form_width, caption_height + close_height); // 矩形区域可以适当大于"关闭"贴图的大小
        }

        switch (mouse_msg.uMsg)
        {
        case WM_LBUTTONDOWN:
            if (mouse_msg.x >= (form_width - close_width - 1) && mouse_msg.x <= form_width && mouse_msg.y >= 0 && mouse_msg.y <= (caption_height + close_height))
            {
                closegraph();
                exit(0);
            }
            else
            {
                // 若按下左键,则欺骗windows 点在了标题栏上
                PostMessage(GetHWnd(), WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(mouse_msg.x, mouse_msg.y));
            }
            break;
        case WM_RBUTTONUP:
            // 关闭程序
            closegraph();
            exit(0);
        }
    }
}

int main()
{
    int width = 800;
    int height = 600;    

    ChallengeSix challenge_six;
    challenge_six.DrawUI(width, height);

    // 单独开启一个线程监听鼠标事件,用于拖动窗体
    std::thread drag_form_thread(DragForm, width, height);
    drag_form_thread.detach();    

    challenge_six.Play();

    closegraph();
    return 0;
}