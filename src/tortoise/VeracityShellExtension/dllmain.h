/*
Copyright 2010-2013 SourceGear, LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
// dllmain.h : Declaration of module class.
class CVeracityTortoiseModule : public ATL::CAtlDllModuleT< CVeracityTortoiseModule >
{
public :
	DECLARE_LIBID(LIBID_VeracityTortoiseLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_VERACITYTORTOISE, "{C29952AA-9937-412F-9333-3C33A089C922}")
};

extern class CVeracityTortoiseModule _AtlModule;
