// open.h
#include <ansi.h>
int do_open(string arg)
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

        if( me->query("marks/open") )           // �жϵ�¯���Ӵ򿪻��ǹ��ϵġ�
                return notify_fail("��¯�ĸ����Ѿ��Ǵ򿪵��ˡ�\n");

        if( me->query("marks/doing") 
         || me->query("marks/aoyao")
         || me->query("marks/fired"))           // ��������������������ܿ����ӡ�
              {
                message_vision(RED"\n$NͻȻ�ּ�һ���ʹ����ָ��������һ�¡�\n"NOR,ob);
                return 1;
              }

    if( arg == "lid" )
        {
                message_vision("$N�ѵ�¯�ĸ��Ӵ򿪡�\n", ob);
                me->set("marks/open", 1);       // ����򿪸��ӼӴ˱�ǡ�
                return 1;
        }

}
