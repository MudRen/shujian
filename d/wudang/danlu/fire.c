// fire.h Cht@SJ 2000-3-12 �޸�
#include <ansi.h>
int do_fire(string arg)
{
        object obj;
        object me = this_object();
        object ob = this_player();
        object *inv;
        inv = deep_inventory(me);

        if( ob->is_busy() ) 
                return notify_fail("����æ���ء�\n");

        if( ob->is_fighting() )
                return notify_fail("������ս���С�\n");

        if( me->query("marks/open", 1) )
                return notify_fail("��¯�ĸ���û�и��ϡ�\n");
        
      if( !objectp( obj = present("fire", ob)))   // �ж���������Ƿ��л��ۡ�
                return notify_fail("����Ҫһ�����ۡ�\n");
                
        if( (int)ob->query("neili", 1)  <= 1000 )
                return notify_fail("������������������˻�Ҳ���������䡣\n");           
                
        if( (int)ob->query("max_neili", 1)  <= 1500 )
                return notify_fail("������������������˻�Ҳ���������䡣\n");                           

        if( me->query("marks/fired"))
                return notify_fail("����Ѿ��������ˡ�\n");   
                
        if( !me->query("liquid/name") )
                return notify_fail("��¯��û��ˮ��\n");  
        if( !sizeof(inv)) 
                return notify_fail("��¯����ʲô��û�С�\n");
        message_vision(HIR"\n$N��ȼһ�Ѳ�𣬻��罥���ش���������\n"NOR, ob);
//        destruct(obj);
        me->set("marks/fired", 1);
        me->set("marks/doing", 1);  
        ob->set_temp("doing", 1);
        remove_call_out("do_check");
        call_out("do_check", 70, me);
        return 1;
}
                                    
void do_check(object ob)
{
        object me = this_object();
        object *obj;
        int i;

        obj = deep_inventory(me);

        if ( (int)me->query("marks/doing", 1) > 0) 
        {
        message_vision("���罥����Ϩ���ˣ���¯����һƬ���ڣ�$Nʲô��ҩҲû��������\n", ob);      
        for(i=0; i<sizeof(obj); i++) {
        destruct(obj[i]);
        }
        if( userp(ob) ) log_file("LIAN_DAN",
        sprintf("%s %s(%s) ��Ϊ�����¯����ʧ�� �� %s\n", ob->query("title"), ob->name(1), geteuid(ob), ctime(time())[4..19] ) ); 
                remove_call_out("do_ready");
                remove_call_out("do_confirm");
                me->delete("marks/doing");
                me->delete("marks/aoyao");
                me->delete("liquid/remaining");
                me->delete("liquid/name");
                me->delete("marks/fired");
                me->delete("marks/burned");
                ob->delete_temp("doing");
        }
        return;
}
