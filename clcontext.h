#ifndef CLCONTEXT_H
#define CLCONTEXT_H

#ifdef __APPLE__
#include <OpenCL/opencl.h>
#else
#include <CL/cl.h>
#endif

#define CLCONTEXT_MAX_DEVICES (16)
#define MAX_PLATFORMS (8)
#define MAX_KERNELS (18)
//#define MAX_PROGRAMS (18)
#define MAX_BUFFERS (18)

enum cl_flag_t {
	CLCURL_SUCCESS,
	CLCURL_FAIL
};

typedef struct {
	size_t size;
	cl_mem_flags flags;
	int local;
} BufferInfo;

typedef struct {
	BufferInfo buffer[MAX_BUFFERS];
	size_t num_buffers;
	size_t num_kernels;
	size_t num_src;
} KernelInfo;

typedef struct {
	cl_uint num_devices;
	cl_command_queue clcmdq[CLCONTEXT_MAX_DEVICES];
	cl_mem buffers[CLCONTEXT_MAX_DEVICES][MAX_BUFFERS];
	cl_kernel clkernel[CLCONTEXT_MAX_DEVICES][MAX_KERNELS];
	cl_program programs[CLCONTEXT_MAX_DEVICES];
	cl_context clctx[CLCONTEXT_MAX_DEVICES];
	KernelInfo kernel;
} CLContext;



void init_cl(CLContext *ctx);
//void pd_init_cl(CLContext *ctx, unsigned char *const *src, size_t *size,const char **names);
void pd_init_cl(CLContext *ctx, unsigned char **src, size_t *size,char **names);
//void pd_init_cl(CLContext *ctx, const char **src, size_t *size,const char **names) ;
//int init_kernel(CLContext *ctx, char **names) ;
void destroy_cl(CLContext *ctx);
void finalize_cl(CLContext *ctx);
void check_clerror(cl_int err, char *comment, ...);

#endif
