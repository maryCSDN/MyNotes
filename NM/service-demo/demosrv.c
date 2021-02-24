#include "demosrv.h"

/** 声明 demo service 的接口函数 */
lc_int32 demosrv_start(void);
lc_int32 demosrv_restart(void);
lc_int32 demosrv_stop(void);

/** 服务静态全局变量的初始化 (demo service 的控制节点) */
static const struct services_ops sg_demosrv_ops = 
{
    .name = "demo",
    .id = SERVICE_ID_DEMO, /* 需要自定义该宏 */
    .start = demosrv_start,
    .stop = demosrv_stop,
    .restart = demosrv_restart,
}


lc_int32 demosrv_init(struct nm_mgt_services *nm_mgt_service)
{
    return service_register(nm_mgt_service, sg_demosrv_ops.name, &sg_demosrv_ops);
}

lc_int32 demosrv_exit(struct nm_mgt_services *nm_mgt_service)
{
    return service_unregister(nm_mgt_service, sg_demosrv_ops.name, &sg_demosrv_ops);
}

lc_int32 demosrv_start(void)
{
    // TODO
    return 0;
}

lc_int32 demosrv_restart(void)
{
    // TODO
    return 0;
}

lc_int32 demosrv_stop(void)
{
    // TODO
    return 0;
}