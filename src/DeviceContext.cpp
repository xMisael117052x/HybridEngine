﻿#include "DeviceContext.h"

void
DeviceContext::init() {
}

void
DeviceContext::update() {
}

void
DeviceContext::render() {
}

void
DeviceContext::destroy() {
    SAFE_RELEASE(m_deviceContext);
}

void
DeviceContext::RSSetViewports(unsigned int NumViewports,
                              const D3D11_VIEWPORT* pViewports) {
    if (NumViewports > 0 && pViewports == nullptr) {
        ERROR("DeviceContext", "RSSetViewports", "pViewports is nullptr");
        return;
    }
    m_deviceContext->RSSetViewports(NumViewports, pViewports);
}

void
DeviceContext::ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
                                     unsigned int ClearFlags,
                                     float Depth,
                                     UINT8 Stencil) {
    if (!pDepthStencilView) {
        ERROR("DeviceContext", "ClearDepthStencilView", "pDepthStencilView is nullptr");
        return;
    }
    m_deviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
}

void
DeviceContext::ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
                                     const float ColorRGBA[4]) {
    if (!pRenderTargetView) {
        ERROR("DeviceContext", "ClearRenderTargetView", "pRenderTargetView is nullptr");
        return;
    }
    m_deviceContext->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
}

void
DeviceContext::OMSetRenderTargets(unsigned int NumViews,
                                  ID3D11RenderTargetView* const* ppRenderTargetViews,
                                  ID3D11DepthStencilView* pDepthStencilView) {
    if (NumViews > 0 && !ppRenderTargetViews) {
        ERROR("DeviceContext", "OMSetRenderTargets", "ppRenderTargetViews is nullptr");
        return;
    }
    m_deviceContext->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
}

void
DeviceContext::IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology) {
    m_deviceContext->IASetPrimitiveTopology(Topology);
}

void
DeviceContext::PSSetShaderResources(unsigned int StartSlot,
                                    unsigned int NumViews,
                                    ID3D11ShaderResourceView* const* ppShaderResourceViews) {
    m_deviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
}

void
DeviceContext::PSSetSamplers(unsigned int StartSlot,
                             unsigned int NumSamplers,
                             ID3D11SamplerState* const* ppSamplers) {
    m_deviceContext->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
}

void
DeviceContext::DrawIndexed(unsigned int IndexCount,
                           unsigned int StartIndexLocation,
                           int BaseVertexLocation) {
    m_deviceContext->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
}

void
DeviceContext::OMSetDepthStencilState(ID3D11DepthStencilState* pDepthStencilState,
                                      unsigned int StencilRef) {
    m_deviceContext->OMSetDepthStencilState(pDepthStencilState, StencilRef);
}

void
DeviceContext::ClearState() {
    m_deviceContext->ClearState();
}

void
DeviceContext::IASetInputLayout(ID3D11InputLayout* pInputLayout) {
    m_deviceContext->IASetInputLayout(pInputLayout);
}

void
DeviceContext::VSSetShader(ID3D11VertexShader* pVertexShader, ID3D11ClassInstance* const* ppClassInstances,
                           unsigned int NumClassInstances) {
    m_deviceContext->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
}

void
DeviceContext::PSSetShader(ID3D11PixelShader* pPixelShader, ID3D11ClassInstance* const* ppClassInstances,
                           unsigned int NumClassInstances) {
    m_deviceContext->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
}

void
DeviceContext::UpdateSubresource(ID3D11Resource* pDstResource,
                                 unsigned int DstSubresource,
                                 const D3D11_BOX* pDstBox,
                                 const void* pSrcData,
                                 unsigned int SrcRowPitch,
                                 unsigned int SrcDepthPitch) {
    m_deviceContext->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
}

void
DeviceContext::IASetVertexBuffers(unsigned int StartSlot,
                                  unsigned int NumBuffers,
                                  ID3D11Buffer* const* ppVertexBuffers,
                                  const unsigned int* pStrides,
                                  const unsigned int* pOffsets) {
    m_deviceContext->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
}

void
DeviceContext::VSSetConstantBuffers(unsigned int StartSlot, unsigned int NumBuffers,
                                    ID3D11Buffer* const* ppConstantBuffers) {
    m_deviceContext->VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void
DeviceContext::PSSetConstantBuffers(unsigned int StartSlot, unsigned int NumBuffers,
                                    ID3D11Buffer* const* ppConstantBuffers) {
    m_deviceContext->PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
}

void
DeviceContext::IASetIndexBuffer(ID3D11Buffer* pIndexBuffer, DXGI_FORMAT Format, unsigned int Offset) {
    m_deviceContext->IASetIndexBuffer(pIndexBuffer, Format, Offset);
}

void
DeviceContext::OMSetBlendState(ID3D11BlendState* pBlendState, const float* BlendFactor, unsigned int SampleMask) {
    m_deviceContext->OMSetBlendState(pBlendState, BlendFactor, SampleMask);
}
