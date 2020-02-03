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
 *
 * @file sg_wc_tx__overwrite_file_from_file.c
 *
 * @details Replace the contents of an existing file
 * using the contents of the given file.
 *
 * And set the attrbits as directed.
 *
 */

//////////////////////////////////////////////////////////////////

#include <sg.h>

#include "sg_wc__public_typedefs.h"
#include "sg_wc__public_prototypes.h"
#include "sg_wc__private.h"

//////////////////////////////////////////////////////////////////

/**
 * WARNING 2012/01/30: I'm not sure that I want this
 * routine in the official public API.  I'm not sure
 * it matters one way or the other.
 * 
 * The intent of this API routine is to allow commands
 * like MERGE, UPDATE, and REVERT request/queue such a
 * change during the TX.
 *
 * For clutters sake, we probably don't want to have
 * a 'vv' command that exposes it; but it might be
 * nice to have a JS glue wrapper (at the sg_wc_tx api
 * layer) that does.
 *
 */
void SG_wc_tx__overwrite_file_from_file(SG_context * pCtx,
										SG_wc_tx * pWcTx,
										const char * pszInput_Src,
										const SG_pathname * pPathTemp,
										SG_int64 attrbits,
										SG_wc_status_flags xu_mask)
{
	SG_string * pStringRepoPath_Src = NULL;
	sg_wc_liveview_item * pLVI_Src;			// we do not own this
	char chDomain_Src;
	SG_bool bKnown_Src;

	SG_NULLARGCHECK_RETURN( pWcTx );
	SG_NULLARGCHECK_RETURN( pPathTemp );

	SG_ERR_CHECK(  sg_wc_db__path__anything_to_repopath(pCtx, pWcTx->pDb, pszInput_Src,
														SG_WC_DB__PATH__IMPORT_FLAGS__TREAT_NULL_AS_ERROR,
														&pStringRepoPath_Src, &chDomain_Src)  );

#if TRACE_WC_TX_SET
	SG_ERR_IGNORE(  SG_console(pCtx, SG_CS_STDERR,
							   "SG_wc_tx__overwrite_file_from_file: source '%s' normalized to [domain %c] '%s'\n",
							   pszInput_Src, chDomain_Src, SG_string__sz(pStringRepoPath_Src))  );
#endif
	
	SG_ERR_CHECK(  sg_wc_tx__liveview__fetch_item__domain(pCtx, pWcTx, pStringRepoPath_Src,
														  &bKnown_Src, &pLVI_Src)  );
	if (!bKnown_Src || (SG_WC_PRESCAN_FLAGS__IS_UNCONTROLLED_UNQUALIFIED(pLVI_Src->scan_flags_Live)))
		SG_ERR_THROW2(  SG_ERR_ITEM_NOT_UNDER_VERSION_CONTROL,
						(pCtx, "Source '%s' (%s)",
						 pszInput_Src, SG_string__sz(pStringRepoPath_Src))  );

	// TODO 2012/01/30 Verify that pPathTemp exists on disk.

	SG_ERR_CHECK(  sg_wc_tx__rp__overwrite_file_from_file__lvi(pCtx, pWcTx, pLVI_Src,
															   pPathTemp,
															   attrbits,
															   xu_mask)  );

fail:
	SG_STRING_NULLFREE(pCtx, pStringRepoPath_Src);
}

//////////////////////////////////////////////////////////////////

/**
 * Like the above routine (overwrite file content) but don't
 * change the attrbits.
 * 
 * Rather, the caller doesn't know what they are and doesn't
 * want to change them; they just want to replace the contents
 * of the file (and doesn't know/care if that can do an in-place
 * re-write or requires a delete/create).
 *
 */
void SG_wc_tx__overwrite_file_from_file2(SG_context * pCtx,
										 SG_wc_tx * pWcTx,
										 const char * pszInput_Src,
										 const SG_pathname * pPathTemp,
										 SG_wc_status_flags xu_mask)
{
	SG_string * pStringRepoPath_Src = NULL;
	sg_wc_liveview_item * pLVI_Src;			// we do not own this
	char chDomain_Src;
	SG_bool bKnown_Src;

	SG_NULLARGCHECK_RETURN( pWcTx );
	SG_NULLARGCHECK_RETURN( pPathTemp );

	SG_ERR_CHECK(  sg_wc_db__path__anything_to_repopath(pCtx, pWcTx->pDb, pszInput_Src,
														SG_WC_DB__PATH__IMPORT_FLAGS__TREAT_NULL_AS_ERROR,
														&pStringRepoPath_Src, &chDomain_Src)  );

#if TRACE_WC_TX_SET
	SG_ERR_IGNORE(  SG_console(pCtx, SG_CS_STDERR,
							   "SG_wc_tx__overwrite_file_from_file2: source '%s' normalized to [domain %c] '%s'\n",
							   pszInput_Src, chDomain_Src, SG_string__sz(pStringRepoPath_Src))  );
#endif
	
	SG_ERR_CHECK(  sg_wc_tx__liveview__fetch_item__domain(pCtx, pWcTx, pStringRepoPath_Src,
														  &bKnown_Src, &pLVI_Src)  );
	if (!bKnown_Src || (SG_WC_PRESCAN_FLAGS__IS_UNCONTROLLED_UNQUALIFIED(pLVI_Src->scan_flags_Live)))
		SG_ERR_THROW2(  SG_ERR_ITEM_NOT_UNDER_VERSION_CONTROL,
						(pCtx, "Source '%s' (%s)",
						 pszInput_Src, SG_string__sz(pStringRepoPath_Src))  );

	// TODO 2012/01/30 Verify that pPathTemp exists on disk.

	SG_ERR_CHECK(  sg_wc_tx__rp__overwrite_file_from_file2__lvi(pCtx, pWcTx, pLVI_Src,
																pPathTemp, xu_mask)  );

fail:
	SG_STRING_NULLFREE(pCtx, pStringRepoPath_Src);
}

