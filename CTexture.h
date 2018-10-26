#pragma once
#include <windows.h>
#include <d3d11.h>

                                                                               
class CManager;
class CTexture
{
public:
	CTexture();
	~CTexture();
	friend CManager;
	 
private:
	
	ID3D11Texture2D * m_pTexure2D = nullptr;
	ID3D11RenderTargetView * m_pRenderTargetView = nullptr;
	ID3D11DepthStencilView * m_pDepthStencilView = nullptr;
	ID3D11ShaderResourceView * m_pTextureRV = nullptr;
	ID3D11Texture2D * m_pDepthStencil = nullptr;
};

