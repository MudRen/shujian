// aoyao.h
#include <ansi.h>
int do_aoyao(string arg)
{
    object me, ob;
    me = this_object();
    ob = this_player();

    if( ob->is_busy() ) 
            return notify_fail("����æ���ء�\n");

    if( ob->is_fighting() )
            return notify_fail("������ս���С�\n");

    if( !ob->query_temp("doing", 1) )
            return notify_fail("��û�ڰ�ҩ��\n");

    if( me->query("marks/open")) 
            return notify_fail("��¯�ĸ���û�иǺá�\n");

    if( !me->query("marks/burned", 1) ) 
            return notify_fail("���ƻ�����ʢ��\n");               

    message_vision(HIY"\n$Nʹ��ȫ������������ϵĽ��赤¯�ڵ�ҩ�����۵������Ǻ���\n"NOR, ob);
    me->set("marks/aoyao", 1);
    ob->start_busy(10);
    return 1;
}