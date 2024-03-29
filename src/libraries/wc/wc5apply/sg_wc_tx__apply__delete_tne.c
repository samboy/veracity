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
 * @file sg_wc_tx__apply__delete_tne.c
 *
 * @details 
 *
 */

//////////////////////////////////////////////////////////////////

#include <sg.h>

#include "sg_wc__public_typedefs.h"
#include "sg_wc__public_prototypes.h"
#include "sg_wc__private.h"

//////////////////////////////////////////////////////////////////

/**
 * Delete a TNE ROW from the tne_L0 table in the wc.db.
 * 
 * The existing row (if it exists) is a copy of the TNE
 * as it existed in the current baseline.  This item
 * will NOT be present in the future baseline.  So we
 * want the TNE ROW to be deleted as we transition the
 * tne_L0 table.
 *
 */
void sg_wc_tx__apply__delete_tne(SG_context * pCtx,
								 SG_wc_tx * pWcTx,
								 const SG_vhash * pvh)
{
#if TRACE_WC_TX_APPLY
	const char * pszRepoPath;

	SG_ERR_CHECK_RETURN(  SG_vhash__get__sz(pCtx, pvh, "src", &pszRepoPath)  );

	SG_ERR_IGNORE(  SG_console(pCtx, SG_CS_STDERR,
							   ("sg_wc_tx__apply__delete_tne: '%s'\n"),
							   pszRepoPath)  );
#else
	SG_UNUSED( pCtx );
	SG_UNUSED( pvh );
#endif

	SG_UNUSED( pWcTx );

	// we don't actually have anything here.
	// the journal record was more for the verbose log.
	// the actual work of updating the SQL will be done
	// in the parallel journal-stmt.

}
