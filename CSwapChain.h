#pragma once
#include <windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>

class CSwapChain
{
public:
	CSwapChain();
	~CSwapChain();

	void ReleaseSwapChain();
	HRESULT GetBuffer(UINT Buffer, REFIID riid, void **ppSurface);
	HRESULT Present(UINT SyncInterval, UINT Flags);

private:
	IDXGISwapChain * m_pSwapChain = NULL;
};

