#include "pch.h"
#include "CTexture.h"
#include <d3dcompiler.h>
#include <D3DX11.h>

CTexture::CTexture()
{
}


CTexture::~CTexture()
{
	if (m_pTexure2D != nullptr)
	{
		m_pTexure2D->Release();
	}
	if (m_pRenderTargetView != nullptr)
	{
		m_pRenderTargetView->Release();
	}
	if (m_pDepthStencilView != nullptr)
	{
		m_pDepthStencilView->Release();
	}
	if (m_pTextureRV != nullptr)
	{
		m_pTextureRV->Release();
	}
	if (m_pDepthStencil != nullptr)
	{
		m_pDepthStencil->Release();
	}
}
