// close.h 
#include <ansi.h>
int do_close(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();
        
        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���С�\n");

    if( !arg || arg == "" || arg != "lid")
                return notify_fail("��Ҫ��ʲô��\n");

        if( !me->query("marks/open") )      // �жϴ�ʱ��¯�ĸ����Ǵ򿪻��ǹ��ϵ�
                return notify_fail("��¯�ĸ���û�д򿪡�\n");

    if( arg == "lid" )
        {
        message_vision("$N������ŵĽ���¯�ĸ��Ӹ��ϡ�\n", ob);
        me->delete("marks/open");           // ������˰ѵ�¯�ĸ��ӹ��ϣ���ôȥ���˱�ǡ�
        return 1;
        }

}