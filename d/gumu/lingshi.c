// lingshi.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
      set("short", HIC"����"NOR);
      set("long", @LONG
ֻ���տտ�����һ�������ϲ��з������ʯ�ס�����ϸ����������ʯ�׹�
�������ܸ�����ԭ���ǹ�Ĺ����ʦ�ֳ�Ӣ��С��Ůʦ���İ���֮�����������
�Ĺ׸�(guangai)ȴֻ����һ�룬Ҳ��֪��������ʬ�塣
LONG
        );

      set("exits", ([ 
	   "out" : __DIR__"ss5",
      ]));     

        set("objects", ([
            __DIR__"obj/fire" : 1,
        ]));
      setup();
}

void init()
{
      add_action("do_tui", "tui");      
      add_action("do_tang","tang");
}

int do_tui(string arg)
{
      object me=this_player();
      if (me->is_busy() || me->is_fighting())
            return notify_fail("����æ���ģ�\n");
      if( arg =="guangai"){
         message_vision(YEL"$Nʹ���ƿ��˹׸ǡ�\n"NOR,me);
         me->set_temp("marks/ʯ��", 1);
         return 1;
      }
      return notify_fail("��Ҫ��ʲô��\n");
}

int do_tang(string arg)
{
      object me=this_player();       
      if (!me->query_temp("marks/ʯ��")) return 0;
      if (me->is_busy() || me->is_fighting())
            return notify_fail("����æ���ģ�\n");
      if ( arg =="guan"){        
         me->delete_temp("marks/ʯ��");
         tell_room(environment(me), me->name() +"�򿪹׸Ǻ����˽�ȥ��\n", ({ me }));
         me->move(__DIR__"shiguan");
         message_vision(HIY"$N�ɽ���ʯ�ף���������ת���ŵء�\n"NOR,me);
         return 1;
      }
      return notify_fail("�����������\n");
}
