// Room: /d/huashan/v-road-5.c
// Date: Look 99/03/25

inherit ROOM;
#include <ansi.h>
#include <wanted.h>

void create()
{
       set("short", "ɽ��");
       set("long",@long
ɽ���������û��·�ˣ�����ͷ��ȥ��һƬ���������ͷ���ϣ�����û��
��ȥ�Ŀ��ܣ�����ԼĪ���ɸߵĵط���һ��������(Songshu)�������ҡ�ڡ�
ǰ����ǻ�ɽ��������Ԩ��
long);
       set("outdoors", "��ɽ");
       set("item_desc",([
       "songshu" : "���̵�����֦���ҡ�ڣ���ʱ����������ɸߣ��������ӻ������ʵ���ȥ��\n",
]));
       set("exits",([
       "northwest" : __DIR__"v-road-1",
]));
       set("coor/x",50);
  set("coor/y",70);
   set("coor/z",-10);
   setup();
}

void init()
{
	if (is_wanted(this_player()))
		return;
        add_action("do_pa", ({ "climb", "pa" }));
        add_action("do_bang",({ "ji", "bang" }));
}

int do_bang(string arg)
{
       object me;
       me = this_player();
       if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
       return notify_fail("����æ���ģ�\n");

       if ( arg=="" || arg!="shengzi"|| !arg) 
       return notify_fail("��Ҫ��ʲô��\n");

       if( me->query_temp("marks/��") > 0 )
       return notify_fail("���Ѿ��������ϰ��������ˡ�\n");

       if( !present("sheng zi", me))
       return notify_fail("��Ҫ��ʲô��\n");

       if( arg=="shengzi") {
       message_vision("$Nʹ��ȫ�������������е����Ӵ�������֦���ϣ�ʹ����ק��ק
���ӣ������Ѿ����ʵ�ˡ�\n", me);
       me->set_temp("marks/��", 1);
       destruct(present("sheng zi", me));
       return 1; }
}
int do_pa(string arg)
{
        object me;
       me = this_player();
       if(!living(me) ) return 0;

        if (me->is_busy() || me->is_fighting())
       return notify_fail("����æ���ģ�\n");

       if ( arg=="" || arg!="up"|| !arg) 
       return notify_fail("��Ҫ��ʲô��\n");

       if( me->query_temp("marks/��") < 1 )
       return notify_fail("�����ɸߵ�������������һ�����ӣ���ô��������\n");

       
       if( arg=="up")  {
       if( me->query_skill("dodge", 1) < 20 ) 
       {
       message_vision("$N�����������ͱ�������ȥ��ͻȻ$N����һ����ˤ��������\n", me);
       me->unconcious();
       return 1; 
       }
        if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 50) 
       {
       message_vision("$N�����������ͱ�������ȥ����Ϊ���ϸ��ع��࣬ͻȻ$N����һ����ˤ��������\n", me);
       me->unconcious();
       return 1; 
       }
       message_vision("$N�����������������\n", me);
       me->move(__DIR__"song");
       return 1;
       }
}
int valid_leave(object me,string dir)
{
       me->delete_temp("marks/��");
       return ::valid_leave(me, dir);  
}
