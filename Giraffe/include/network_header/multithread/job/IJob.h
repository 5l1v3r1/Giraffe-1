#ifndef  __JOB_H__
#define  __JOB_H__

#include "common/Header.h"
//#include "GJobDef.h"

class NETWORK_EXPORT IJob 
{
public: 
	IJob(U32 jobId,U8 subType, U8 type /*= GJobDef::MY_MAJOR_JOB */);
	virtual ~IJob();
	virtual String					toString() const = 0;
	U32								toString(S8 * str)const;
	U32								getJobId()const;
	U8								getJobType()const;
	U8								getJobSubType()const;

protected:
	U8								m_cType;//����
	U8								m_cSubType;//������
	U32								m_iJobId;
};


#endif //__JOB_H__
