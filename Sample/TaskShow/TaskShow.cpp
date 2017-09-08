// TaskShow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "./src/MainWindow.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    suic::InitUIWgxs(true);
    suic::InitUILogLevel(suic::LogLevel::Trace);

    suic::WindowPtr wnd(new MainWindow());

    try
    {
        // ������Դ�ļ�
        suic::ThemeOp::SetSystemTheme("default.sres", "wr");
        suic::String strApp = _T("TaskShow/Layout/Application.xml");

        // ���벼����Դ������ϵͳ
        suic::Application::RunApp(wnd.get(), strApp.c_str());
    }
    catch(suic::Exception& e)
    {
        suic::String err = e.GetErrorMsg();
    }

    wnd = NULL;
    
    suic::ExitUIWgx();

    return 0;
}
