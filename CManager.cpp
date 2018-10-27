#include "CManager.h"


CManager::CManager()
{
}

CManager::~CManager()
{
}

void CManager::CleanupDevice()
{
	device.ReleaseDevice();
	deviceContext.ReleaseDeviceContext();
	swapChain.ReleaseSwapChain();
}

/*
CTexture * CManager::CreateRenderTargeFromBackBuffer(UINT backBufferIndex)
{
	CTexture * texture = new CTexture();
	HRESULT hr = GetBuffer(
		backBufferIndex, __uuidof(ID3D11Texture2D),
		(LPVOID*)&texture->m_pTexure2D);
	if (FAILED(hr)) { return nullptr; }

	hr = CreateRenderTargetView(
		texture->m_pTexure2D, NULL, &texture->m_pRenderTargetView);
	if (FAILED(hr)) { return nullptr; }
	return texture;
}

CTexture * CManager::CreateDepthStencil(UINT width, UINT height)
{
	CTexture * texture = new CTexture();
	HRESULT hr;
	D3D11_TEXTURE2D_DESC descDepth;
	ZeroMemory(&descDepth, sizeof(descDepth));
	descDepth.Width = width;
	descDepth.Height = height;
	descDepth.MipLevels = 1;
	descDepth.ArraySize = 1;
	descDepth.Format = DXGI_FORMAT_D24_UNORM_S8_UINT;
	descDepth.SampleDesc.Count = 1;
	descDepth.SampleDesc.Quality = 0;
	descDepth.Usage = D3D11_USAGE_DEFAULT;
	descDepth.BindFlags = D3D11_BIND_DEPTH_STENCIL;
	descDepth.CPUAccessFlags = 0;
	descDepth.MiscFlags = 0;
	CreateTexture2D(&descDepth, NULL, &texture->m_pDepthStencil);
	if (FAILED(hr))
		return nullptr;

	D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
	ZeroMemory(&descDSV, sizeof(descDSV));
	descDSV.Format = descDepth.Format;
	descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
	descDSV.Texture2D.MipSlice = 0;

	CreateDepthStencilView(texture->m_pDepthStencil, &descDSV, &texture->m_pDepthStencilView);
	if (FAILED(hr))
		return nullptr;

	OMSetRenderTargets(1, &texture->m_pRenderTargetView, texture->m_pDepthStencilView);

	return texture;
}

CTexture * CManager::CreateTextureFromFile(
	ID3D11Device * pDevice,
	LPCWSTR pSrcFile)
{
	CTexture * texture = new CTexture();
	D3DX11CreateShaderResourceViewFromFile(pDevice, pSrcFile, NULL, NULL, &texture->m_pTextureRV, NULL);

}*/

/*
HRESULT CManager::InitDevice()
{
	HRESULT hr = S_OK;

	UINT createDeviceFlags = 0;
#ifdef _DEBUG
	createDeviceFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	D3D_DRIVER_TYPE driverTypes[] =
	{
		D3D_DRIVER_TYPE_HARDWARE,
		D3D_DRIVER_TYPE_WARP,
		D3D_DRIVER_TYPE_REFERENCE,
	};
	UINT numDriverTypes = ARRAYSIZE(driverTypes);

	D3D_FEATURE_LEVEL featureLevels[] =
	{
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
	};
	UINT numFeatureLevels = ARRAYSIZE(featureLevels);

	DXGI_SWAP_CHAIN_DESC sd;
	ZeroMemory(&sd, sizeof(sd));

	for (UINT driverTypeIndex = 0; driverTypeIndex < numDriverTypes; driverTypeIndex++)
	{
		m_driverType = driverTypes[driverTypeIndex];
		hr = D3D11CreateDeviceAndSwapChain(NULL, m_driverType, NULL, createDeviceFlags, featureLevels, numFeatureLevels,
			D3D11_SDK_VERSION, &sd, &swapChain.m_pSwapChain, &device.m_pd3dDevice, &m_featureLevel, &deviceContext.m_pImmediateContext);

		if (SUCCEEDED(hr))
			break;
	}
	if (FAILED(hr))
		return hr;

	 / * RenderTarget

	ID3D11Texture2D* pBackBuffer = NULL;
	hr = GetBuffer(0, __uuidof (ID3D11Texture2D), (LPVOID *)&pBackBuffer);
	if (FAILED(hr))
		return hr;

	* /

	/ * Depth Stencil Texture

	* /

	/ * Depth Stencil View

	* /


}*/

HRESULT CManager::CreateRenderTargetView(
	ID3D11Resource * pResource,
	const D3D11_RENDER_TARGET_VIEW_DESC * pDesc,
	ID3D11RenderTargetView ** ppRTView)
{
	return device.CreateRenderTargetView(pResource, pDesc, ppRTView);
}

HRESULT CManager::CreateTexture2D(
	const D3D11_TEXTURE2D_DESC * pDesc,
	const D3D11_SUBRESOURCE_DATA * pInitialData,
	ID3D11Texture2D ** ppTexture2D)
{
	return device.CreateTexture2D(pDesc, pInitialData, ppTexture2D);
}

HRESULT CManager::CreateDepthStencilView(
	ID3D11Resource * pResource,
	const D3D11_DEPTH_STENCIL_VIEW_DESC * pDesc,
	ID3D11DepthStencilView ** ppDepthStencilView)
{
	return device.CreateDepthStencilView(pResource, pDesc, ppDepthStencilView);
}

HRESULT CManager::CreateVertexShader(
	const void * pShaderBytecode,
	SIZE_T BytecodeLength,
	ID3D11ClassLinkage * pClassLinkage,
	ID3D11VertexShader ** ppVertexShader)
{
	return device.CreateVertexShader(
		pShaderBytecode,
		BytecodeLength,
		pClassLinkage,
		ppVertexShader);

}

HRESULT CManager::CreateInputLayout(
	const D3D11_INPUT_ELEMENT_DESC * pInputElementDescs,
	UINT NumElements,
	const void * pShaderBytecodeWithInputSignature,
	SIZE_T BytecodeLength,
	ID3D11InputLayout ** ppInputLayout)
{
	return device.CreateInputLayout(
		pInputElementDescs,
		NumElements,
		pShaderBytecodeWithInputSignature,
		BytecodeLength,
		ppInputLayout);
}

HRESULT CManager::CreatePixelShader(
	const void * pShaderBytecode,
	SIZE_T BytecodeLength,
	ID3D11ClassLinkage * pClassLinkage,
	ID3D11PixelShader ** ppPixelShader)
{
	return device.CreatePixelShader(
		pShaderBytecode,
		BytecodeLength,
		pClassLinkage,
		ppPixelShader);
}

HRESULT CManager::CreateBuffer(
	const D3D11_BUFFER_DESC * pDesc,
	const D3D11_SUBRESOURCE_DATA * pInitialData,
	ID3D11Buffer ** ppBuffer)
{
	return device.CreateBuffer(pDesc, pInitialData, ppBuffer);
}

HRESULT CManager::CreateSamplerState(
	const D3D11_SAMPLER_DESC * pSamplerDesc,
	ID3D11SamplerState ** ppSamplerState)
{
	return device.CreateSamplerState(pSamplerDesc, ppSamplerState);

}

HRESULT CManager::GetBuffer(
	UINT Buffer,
	REFIID riid,
	void ** ppSurface)
{
	return swapChain.GetBuffer(Buffer, riid, ppSurface);
}

HRESULT CManager::Present(UINT SyncInterval, UINT Flags)
{
	return swapChain.Present(SyncInterval, Flags);
}

void CManager::OMSetRenderTargets(
	UINT NumViews,
	ID3D11RenderTargetView * const * ppRenderTargetViews,
	ID3D11DepthStencilView * pDepthStencilView)
{
	deviceContext.OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
}

void CManager::RSSetViewports(
	UINT NumViewports,
	const D3D11_VIEWPORT * pViewports)
{
	deviceContext.RSSetViewports(NumViewports, pViewports);
}

void CManager::IASetInputLayout(ID3D11InputLayout * pInputLayout)
{
	deviceContext.IASetInputLayout(pInputLayout);
}

void CManager::IASetVertexBuffers(
	UINT StartSlot, UINT NumBuffers,
	ID3D11Buffer * const * ppVertexBuffers,
	const UINT * pStrides,
	const UINT * pOffsets)
{
	deviceContext.IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void CManager::IASetIndexBuffer(
	ID3D11Buffer * pIndexBuffer,
	DXGI_FORMAT Format,
	UINT Offset)
{
	deviceContext.IASetIndexBuffer(pIndexBuffer, Format, Offset);
}

void CManager::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology)
{
	deviceContext.IASetPrimitiveTopology(Topology);
}

void CManager::UpdateSubresource(
	ID3D11Resource * pDstResource,
	UINT DstSubresource,
	const D3D11_BOX * pDstBox,
	const void * pSrcData,
	UINT SrcRowPitch,
	UINT SrcDepthPitch)
{
	deviceContext.UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
}

void CManager::ClearRenderTargetView(
	ID3D11RenderTargetView * pRenderTargetView,
	const FLOAT ColorRGBA[4])
{
	deviceContext.ClearRenderTargetView(pRenderTargetView, ColorRGBA);
}

void CManager::ClearDepthStencilView(
	ID3D11DepthStencilView * pDepthStencilView,
	UINT ClearFlags,
	FLOAT Depth,
	UINT8 Stencil)
{
	deviceContext.ClearDepthStencilView(
		pDepthStencilView,
		ClearFlags,
		Depth,
		Stencil);
}

void CManager::VSSetShader(
	ID3D11VertexShader * pVertexShader,
	ID3D11ClassInstance * const * ppClassInstances,
	UINT NumClassInstances)
{
	deviceContext.VSSetShader(
		pVertexShader,
		ppClassInstances,
		NumClassInstances);
}

void CManager::VSSetConstantBuffers(
	UINT StartSlot,
	UINT NumBuffers,
	ID3D11Buffer * const * ppConstantBuffers)
{
	deviceContext.VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void CManager::PSSetShader(
	ID3D11PixelShader * pPixelShader,
	ID3D11ClassInstance * const * ppClassInstances,
	UINT NumClassInstances)
{
	deviceContext.PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
}

void CManager::PSSetConstantBuffers(
	UINT StartSlot,
	UINT NumBuffers,
	ID3D11Buffer * const * ppConstantBuffers)
{
	deviceContext.PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void CManager::PSSetShaderResources(
	UINT StartSlot,
	UINT NumViews,
	ID3D11ShaderResourceView * const * ppShaderResourceViews)
{
	deviceContext.PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void CManager::PSSetSamplers(
	UINT StartSlot,
	UINT NumSamplers,
	ID3D11SamplerState * const * ppSamplers)
{
	deviceContext.PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void CManager::DrawIndexed(
	UINT IndexCount,
	UINT StartIndexLocation,
	INT BaseVertexLocation)
{
	deviceContext.DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
}

HRESULT CManager::CreateDeviceAndSwapChain(
	IDXGIAdapter * pAdapter,
	D3D_DRIVER_TYPE DriverType,
	HMODULE Software,
	UINT Flags,
	const D3D_FEATURE_LEVEL * pFeatureLevels,
	UINT FeatureLevels,
	UINT SDKVersion,
	const DXGI_SWAP_CHAIN_DESC * pSwapChainDesc,
	IDXGISwapChain ** ppSwapChain,
	ID3D11Device ** ppDevice,
	D3D_FEATURE_LEVEL * pFeatureLevel
	//ID3D11DeviceContext ** ppImmediateContext
)
{
	return D3D11CreateDeviceAndSwapChain(
		pAdapter,
		DriverType,
		Software,
		Flags,
		pFeatureLevels,
		FeatureLevels,
		SDKVersion,
		pSwapChainDesc,
		ppSwapChain,
		ppDevice,
		pFeatureLevel,
		deviceContext.getDeviceContext());

}