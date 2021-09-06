#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "˯��");
        set("long", @LONG
���˯������������������ׯ���������ˡ���һ��������������
���м����飬ȴ�ǡ��׾���֮�ࡣǽ����һ�����ӡ��������俴��ȥ��
Ϊ������
LONG);
        set("no_fight", "1");
        set("objects", ([
                    __DIR__"obj/book1" : 1,
        ]));
        set("book_count",1);
        set("exits", ([
              "west" : __DIR__"tangwu",
        ]));
        setup(); 
}

void init()
{
        add_action("do_shui", "sleep");
}

int do_shui(string arg)
{
        object me = this_player();
        object where = environment(me);  
        if (me->is_busy() || me->is_fighting() )
        	return notify_fail("����æ���ء�\n");      
        message_vision("\n$Nһ�������ڴ��ϣ���һ����������������������硣\n",me); 
        me->start_busy(3);       
        me->set_temp("block_msg/all",1);
        me->disable_player("<˯����>");
        call_out("wakeup", 40, me, where);
        return 1;
}

void wakeup(object me)
{
        int cost;
        
        if (!me) return;
        if (!cost = me->query_condition("sleep"))
                me->apply_condition("sleep", 9);
        cost++;        
        while( environment(me)->is_character() )
                me->move(environment(environment(me)));      
                
        me->add("qi",    (me->query("eff_qi") - me->query("qi"))/cost);
        me->add("jing",  (me->query("eff_jing") - me->query("jing"))/cost);
        me->add("neili", (me->query("max_neili") - me->query("neili"))/2/cost);
        me->add("jingli", (me->query("eff_jingli") - me->query("jingli"))/2/cost);
        me->enable_player();
        message_vision("$Nһ����������������ػ��һ�½�ǡ�\n",me);
        me->delete_temp("block_msg/all");       
        write("��һ�����������þ������棬�ûһ���ˡ�\n");
        if (random(me->query("kar")) > 15 
        && me->query("oyf_son")
        && me->query_skill("hamagong", 1)
        && query("book_count") >= 1){ 
             	write("�������ڴ���һ�ţ���Ȼ���ִ����¸���ʲô������\n");
             	write("�ƿ�����һ����ԭ����һ����������װ�顣\n");
             	new_ob(__DIR__"obj/book")->move(me);
             	if(!wizardp(me))
             		log_file("quest/hmg_book", me->query("name")+"("+me->query("id")+
             		") got hamagong book on " + ctime(time()) + "��\n" );
             	add("book_count", -1);
        }
        me->start_busy(2);
}
