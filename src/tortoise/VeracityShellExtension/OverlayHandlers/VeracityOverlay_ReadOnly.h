// VeracityOverlay_ReadOnly.h : Declaration of the CVeracityOverlay_ReadOnly

#pragma once
#include "../stdafx.h"
#include "../resource.h"       // main symbols
#include <comsvcs.h>
#include "VeracityTortoise_i.h"
#include "VeracityOverlay_Base.h"

using namespace ATL;



// CVeracityOverlay_ReadOnly

class ATL_NO_VTABLE CVeracityOverlay_ReadOnly :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVeracityOverlay_ReadOnly, &CLSID_VeracityOverlay_ReadOnly>,
	public IDispatchImpl<IVeracityOverlay_ReadOnly, &IID_IVeracityOverlay_ReadOnly, &LIBID_VeracityTortoiseLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IShellIconOverlayIdentifier,
	public VeracityOverlay_Base
{
public:
	CVeracityOverlay_ReadOnly()
	{
	}

	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_VERACITYOVERLAY_READONLY)

DECLARE_NOT_AGGREGATABLE(CVeracityOverlay_ReadOnly)

BEGIN_COM_MAP(CVeracityOverlay_ReadOnly)
	COM_INTERFACE_ENTRY(IVeracityOverlay_ReadOnly)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IShellIconOverlayIdentifier)
END_COM_MAP()

	//IShellIconOverlayIdentifier
	STDMETHODIMP GetOverlayInfo(LPWSTR pwszIconFile, int cchMax, int *pIndex, DWORD *pdwFlags);
    STDMETHODIMP GetPriority(int *pPriority);
    STDMETHODIMP IsMemberOf(LPCWSTR pwszPath, DWORD dwAttrib);



// IVeracityOverlay_ReadOnly
public:
};

OBJECT_ENTRY_AUTO(__uuidof(VeracityOverlay_ReadOnly), CVeracityOverlay_ReadOnly)
