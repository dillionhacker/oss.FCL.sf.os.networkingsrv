/*
* Copyright (c) 2003 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of the License "Symbian Foundation License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.symbianfoundation.org/legal/sfl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:
*
*/


/**
 * @file ts_ipsec_crypto.h header file for main test code for IPsec
 */

#if (!defined  __TEF_IPSEC_COVERAGE_TEST_H__)
#define __TEF_IPSEC_COVERAGE_TEST_H__


//local includes here

#include "te_IPSec_Load_Policy_Base.h"

#include <ipsecpolapi.h>
#include <comms-infras\dbaccess.h>
#include <CommDbConnPref.h>
#include <featureuids.h>
#include <e32Debug.h>

/**
 * This class is to test the policy loading in the order of Bypasss policy,Drop Policy, Drop Policy
 * 
 */

class CT_CoverageTest : public CT_IPSec_Load_Policy_Base
	{
public:
	CT_CoverageTest();
	~CT_CoverageTest();
	
	static CT_CoverageTest* NewL();	
	virtual TBool	DoCommandL(const TTEFFunction& aCommand, const TTEFSectionName& aSection, const TInt aAsyncErrorIndex);
	virtual TCleanupOperation CleanupOperation()
		{
		return CleanupOperation;
		}
		
protected:
	void ConstructL();
	
private:
	static void CleanupOperation(TAny* aAny)
		{
		TInt* number = static_cast<TInt*>(aAny);
		delete number;
		}
	
	inline void DoCmdNewL(const TDesC& aEntry);
	void DoLoadBypassModePolicy(const TDesC& aSection);
	void DoCmdClose(const TDesC& /*aSection*/);	
	void DoUnloadBypassPolicy(const TDesC& /*aSection*/);
	void DoUnloadDropPolicy(const TDesC& /*aSection*/);
	void DoLoadDropModePolicy(const TDesC& /*aSection*/);
	void DoLoadNewBypassModePolicy(const TDesC& /*aSection*/);
	void DoUnloadNewBypassPolicy(const TDesC& /*aSection*/);
	
protected:
  
	TZoneInfoSet           iMyZoneInfoSet;
	RIpsecPolicyServ       iDrpPolicyServer;    
	TPolicyHandlePckg      iDrpPolicyHandle;
	RIpsecPolicyServ       iBypsPolicyServer;
	TPolicyHandlePckg      iBypsPolicyHandle;
	TPolicyHandlePckg      iNewBypsPolicyHandle;
	};

#endif //__TEF_IPSEC_COVERAGE_TEST_H__