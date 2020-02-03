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

#pragma once

typedef struct  
{
	HWND		hWnd;
	HANDLE		hEvent;
	BOOL		bRunning;

	const char* szProfile;
	BOOL		bShutdown;
	
	DWORD		lLastHearbeat;
	DWORD		lLastSyncAttempt;
	DWORD		lLastSyncSuccess;

	BOOL		bCredentialsChanged;
	BOOL		bRememberCredentials;
	char*		pszUser;
	char*		pszPassword;
	char*		pszSrcUlrForAuth;
}
WorkerThreadParms;

void WorkerThread(void* pVoid);