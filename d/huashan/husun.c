// Room: /d/huashan/husun.c
// Date: Look 99/03/25

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
ǰ������һ��ʮ�ֶ��͵�ɽ�룬��������ֻ��Գ���̾�̨�ϣ���˵��ǰ��
��ɽˮ����������Գ�ÿ�������Ҫ����ȥ��������Ҳ�е����ڳ�Խ������
���������
LONG
        );
	set("objects",([
	  __DIR__"npc/monkey" : 1,
]));
        set("exits", ([ 
	  "northdown" : __DIR__"laojun",
	  "southup" : __DIR__"canglong",
]));
        set("outdoors", "��ɽ" );

        set("coor/x",70);
  set("coor/y",60);
   set("coor/z",50);
   setup();
     
}
void init()
{
        add_action("do_look", "look");
        add_action("do_pa", ({ "climb", "pa" }));
} 
int do_look(string arg)
{
       if( !arg || arg == "" || arg !=  "tieyuan") return 0;
             write(
             "����ͷ��ϸ�ۿ��������Գ����Ȼ����ɽ�µĶ����ƺ���Щʲ�ᶫ����\n"
             );
             this_player()->set_temp("marks/look", 1);
             return 1;
}
int do_pa(string arg)
{
       object me;
       me = this_player(); 
        if (arg != "ya" ) return 0;
         if ( !arg ) return 0;

        if (!me->query_temp("marks/look"))
        return notify_fail("��Ҫ����������\n");
        
        if (!living(me)) return 0;
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 10) {
                message_vision("$N�������꣬�е��޷�����ȥ��ˤ��������\n", me);
                me->unconcious();
                return 1;
        } 
        if( (int)me->query_skill("dodge",1) < 80 ) {  
        message_vision(HIR"$N��Ҫ����ɽ���������Ṧ������ˤ��������\n"NOR, me);
        me->unconcious();
        return 1;     
        }  
        message_vision("$N��סͻ������ʯ��ʩչ�Ṧ������ȥ��\n", me);
        me->move(__DIR__"jinshe/biding");
        tell_room(environment(me), me->name() + "����������������\n", ({ me }));
        me->delete_temp("marks/look");
        return 1;
}
