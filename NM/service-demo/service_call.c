/**
 * services 初始化入口 (reload)
 * nm_api.c -> void nm_service_init(void)
 */ 
void nm_service_init(void)
{
    /* init_services -> 是INIT状态FSM的服务链表
     * 将demo service 注册到FSM INIT状态的服务链表
     */
    demosrv_init(&init_services);
    /* ready_services -> 是READY状态FSM的服务链表 
     * 将demo service 注册到FSM READY状态的服务链表
     */
    demosrv_init(&ready_services);
    /* up_services -> 是UP状态FSM的服务链表 
     * 将demo service 注册到FSM UP状态的服务链表
     */
    demosrv_init(&up_services);
    /* dowm_services -> 是初始化状态FSM的服务链表 
     * 将demo service 注册到FSM DOWN状态的服务链表
     */
    // demosrv_init(&down_services);
}


/**
 * 调用demo service
 */ 
lc_int32 nm_demosrv_call(void *msg)
{
    // TODO
    return do_service_action("demosrv", "restart");

}