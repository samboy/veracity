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

/**
 * @file sg_libcurl_typedefs.h
 */

//////////////////////////////////////////////////////////////////

#ifndef H_SG_LIBCURL_TYPEDEFS_H
#define H_SG_LIBCURL_TYPEDEFS_H

BEGIN_EXTERN_C;

typedef struct _sg_curl_is_opaque SG_curl;

typedef void SG_curl__callback(
	SG_context* pCtx,
	SG_curl* pCurl,
	char *buffer,
	SG_uint32 bufLen,
	void *pVoidState,
	SG_uint32* pLenHandled);

typedef void SG_curl_progress_callback(
	SG_context* pCtx,
	double dltotal,
	double dlnow,
	double ultotal,
	double ulnow,
	void *pVoidState);

END_EXTERN_C;

#endif//H_SG_LIBCURL_TYPEDEFS_H

