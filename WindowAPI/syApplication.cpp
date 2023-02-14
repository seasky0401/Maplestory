#include "syApplication.h"
#include "syTime.h"


namespace sy
{
	void Application::Initialize(WindowImplData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(mWindowData.hWnd);

		Time::Initialize();
	}
	void Application::Run()
	{
		Update();
		Render(mWindowData.hdc);
	}
	void Application::Update()
	{
		Time::Update();
	}
	void Application::Render(HDC hdc)
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{

			x -= (200.0f * Time::DeltaTime());
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			x += 200.0f * Time::DeltaTime();
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			y -= 200.0f * Time::DeltaTime();
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			y += 200.0f * Time::DeltaTime();
		}
		Rectangle(hdc, x+100, y+100, x+200, y+200);
		Time::Render(hdc);
	}
	void Application::Release()
	{

	}
}