
#ifndef __thread_data_h
#define __thread_data_h

#include "jni.h"
#include "stackTrace-impl.h"
#include "exception.h"
#include "jnirefs.h"
#include "ksem.h"

/*
 * Structure that defines any per-thread data needed by kaffe.
 */
typedef struct _threadData {
	JNIEnv		jniEnv;
	void		*jlThread;

	/* required by the jnireferences stuff */
#ifdef NEED_JNIREFS
	jnirefs		*jnireferences;
#endif


	/* things necessary for jvmpi */
#ifdef ENABLE_JVMPI
	struct		_exceptionFrame topFrame;
	void		*jvmpiData;
#endif

	/* things required by the locking subsystem */
	struct Ksem	sem;
	struct _jthread	*nextlk;


	/* things required for exception handling */
	VmExceptHandler	*exceptPtr;
	struct Hjava_lang_Throwable *exceptObj;
	int		needOnStack;
} threadData;

#endif
