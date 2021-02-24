/**
 * Document introduction and description
 * Service  Description
 */ 
#ifndef _DEMO_SERVICE_H
#define _DEMO_SERVICE_H

#include "nm_mgt.h"

/** 将该服务注册到指定的状态列表 */
lc_int32 demosrv_init(struct nm_mgt_services *nm_mgt_services);
/** 将该服务从指定的状态列表中移除 */
lc_int32 demosrv_exit(struct nm_mgt_services *nm_mgt_services);

#endif
