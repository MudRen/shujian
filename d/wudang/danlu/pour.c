// pour.h
#include <ansi.h>

int do_pour(string arg)
{
        string hehe, what;
object me, ob, obj;
        me = this_object();
        ob = this_player();
        if( !arg
        ||  sscanf(arg, "%s in %s", hehe, what) != 2
               )
                return notify_fail("��Ҫ��ʲô��\n");

        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���У�\n");

        if( !me->query("marks/open", 1) )
                return notify_fail("��¯�ĸ���û�д򿪡�\n");

        if( !objectp( obj = present(hehe, ob)))   // ��������ϵ���Ʒ��ID���ԣ���������¯���ˮ��
                return notify_fail("������û��"+hehe+"���������¯���ˮ��\n");
                
        if( !obj->query("liquid/type"))           // ��������ϵ���Ʒ����ʢˮ�����󣬲�������¯���ˮ��
                return notify_fail(obj->name()+"����ʢˮ������\n");

        if( !obj->query("liquid/remaining") )     // �ж�������ʢˮ���������Ƿ���ˮ��
                return notify_fail(obj->name() + "�����Ѿ�һ�β�ʣ�ˡ�\n");

        message_vision("$N��һЩ"+ obj->query("liquid/name") +"��"+ obj->name() +"������¯��\n", ob);
        obj->add("liquid/remaining", -1);
        me->add("liquid/remaining", 1);
        me->set("liquid/name", obj->query("liquid/name"));
        return 1;
}
