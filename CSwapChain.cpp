#include "CSwapChain.h"


CSwapChain::CSwapChain()
{
}


CSwapChain::~CSwapChain()
{
}

void CSwapChain::ReleaseSwapChain()
{
	m_pSwapChain->Release();
}

HRESULT CSwapChain::GetBuffer(UINT Buffer, REFIID riid, void ** ppSurface)
{
	return m_pSwapChain->GetBuffer(Buffer, riid, ppSurface);
}

HRESULT CSwapChain::Present(UINT SyncInterval, UINT Flags)
{
	return m_pSwapChain->Present(SyncInterval, Flags);
}