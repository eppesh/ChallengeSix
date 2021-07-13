// ���ƣ���ս6��
// ��Ȩ��
// ���ߣ�Sean (eppesh@163.com)
// ������VS2019;EasyX 2021
// ʱ�䣺2021/07/11
// ˵����׼ȷ��ͣ��6��������ս�ɹ����������� ��(2864292458@qq.com)ͬѧ����ս�������Ϊ�������������Ӧע�ͣ������˲����¹��ܡ�

// ��л����[2864292458@qq.com] (https://codebus.cn/luoyh/challenge)

#include <conio.h>
#include <time.h>
#include <thread>

#include <graphics.h>

#include "resource.h"
#include "ChallengeSix.h"

using namespace challengesix;

// �϶�����
void DragForm(const int form_width, const int form_height)
{
    MOUSEMSG mouse_msg;  // ���������Ϣ
    int caption_height = GetSystemMetrics(SM_CYCAPTION);  // �������߶�
    IMAGE close_image;
    loadimage(&close_image, _T("PNG"), MAKEINTRESOURCE(IDB_CLOSE));
    int close_width = close_image.getwidth();
    int close_height = close_image.getheight();

    while (true)
    {
        mouse_msg = GetMouseMsg();  // ��ȡһ�������Ϣ        

        // ���ͣ�ڹر���ͼ�Ϸ�ʱ
        if (mouse_msg.x >= (form_width - close_width - 1) && mouse_msg.x <= form_width && mouse_msg.y >= 0 && mouse_msg.y <= (caption_height + close_height))
        {
            putimage(form_width - close_width - 1, caption_height, &close_image, SRCPAINT);
        }
        else
        {
            setfillcolor(RGB(6, 31, 62));
            setlinecolor(RGB(6, 31, 62));
            fillrectangle(form_width - close_width - 1, caption_height, form_width, caption_height + close_height); // ������������ʵ�����"�ر�"��ͼ�Ĵ�С
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
                // ���������,����ƭwindows �����˱�������
                PostMessage(GetHWnd(), WM_NCLBUTTONDOWN, HTCAPTION, MAKELPARAM(mouse_msg.x, mouse_msg.y));
            }
            break;
        case WM_RBUTTONUP:
            // �رճ���
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

    // ��������һ���̼߳�������¼�,�����϶�����
    std::thread drag_form_thread(DragForm, width, height);
    drag_form_thread.detach();    

    challenge_six.Play();

    closegraph();
    return 0;
}