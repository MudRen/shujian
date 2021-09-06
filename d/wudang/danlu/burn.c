// burn.h Cht@SJ 2000-3-12 �޸�
#include <ansi.h>
int do_burn(string arg)
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

        if( me->query("marks/open", 1) )
                return notify_fail("��¯�ĸ���û�и��ϡ�\n");

        if( !me->query("marks/fired", 1) )
                return notify_fail("��¯�ڻ�û����������ô�ܹ�ʹ���ȼ��������\n");

        if( me->query("marks/burned", 1))
                return notify_fail("��¯��Ļ����Ѿ��ܴ��ˣ������ټӴ�����ˡ�\n");

        if( !arg || arg =="" || arg != "coal")
                return notify_fail("��Ҫȼ��ʲô������\n"); 
                
        if( (int)ob->query("neili", 1)  <= 1000 )
                return notify_fail("������������������˻�Ҳ���������䡣\n");           
                
        if( (int)ob->query("max_neili", 1)  <= 1500 )
                return notify_fail("������������������˻�Ҳ���������䡣\n");                           

        if( arg =="coal") 
        {
                message_vision(HIC"\n$Nʹ�����������䣬��¯��ð���������̡�\n"NOR, ob);
                remove_call_out("do_ready");
                call_out("do_ready", 30, me);
                me->set("marks/burned", 1);
                ob->add("neili", -1000);
                ob->add("jingli", -500);
                ob->start_busy(15);
                return 1;
        }
}

void do_ready(object ob)
{
        object me = this_object();
        message_vision(HIW"\n���ƽ�������������һ��Ũ�صĲ�ҩζ���˱Ƕ�����Ӧ�ð�ҩ�ˡ�\n"NOR, ob);
        ob->start_busy(2);
        remove_call_out("do_confirm");
        call_out("do_confirm", 30+random(10), me);
        return;
}

void do_confirm(object ob)
{
        object me = this_object();

        if( me->query("marks/aoyao", 1) ) 
        {
                remove_call_out("confirm");
                remove_call_out("ready");
                message_vision(HIR"\nҩ�찾���ˣ��Ͻ����ɣ�\n"NOR, ob);
                remove_call_out("do_check");
                call_out("do_check", 70, me);
                me->delete("marks/burned");
                ob->set_temp("done", 1);
        }
        else 
        {
                write(HIY"һ�ɽ���ζ���˱Ƕ�����\n"NOR, ob);
                ob->start_busy(7);
                remove_call_out("do_failed"); 
                call_out("do_failed", 7, me);
        }
        return;
}

void do_failed(object ob)
{
        object me = this_object();
        object *obj;
        int i;

        obj = deep_inventory(me);
        if( !sizeof(obj) )      return;
        for(i=0; i<sizeof(obj); i++) {
        destruct(obj[i]);
        }
        message_vision("��¯����һƬ���ڣ�$Nʲô��ҩҲû��������\n", ob);
        if( userp(ob) ) log_file("LIAN_DAN",
        sprintf("%s %s(%s) ��Ϊ�����¯����ʧ�� �� %s\n", ob->query("title"), ob->name(1), geteuid(ob), ctime(time())[4..19] ) ); 
        remove_call_out("do_ready");
        remove_call_out("do_confirm");
        me->delete("marks/aoyao");
        me->delete("marks/open");
        me->delete("marks/fired");
        me->delete("marks/doing");
        me->delete("liquid/remaining");
        me->delete("liquid/name");
        me->delete("marks/burned");
        ob->delete_temp("doing");
        return;
}
