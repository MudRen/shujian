#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",CYN"����ƺ"NOR);
       set("long", @LONG
�����������������Σ��һƬ��������һ���·���죬�����Ǿ����޵ء�
ֻ����һƬƽ�ء����¿�ȥȥ�վ��Ѽ���������Ԯ���ұڼ������̦���们��
�ͣ�������·���ϡ�
LONG
     );
        set("exits", ([
              "south"  : __DIR__"xctang",
        ]));
       set("coor/x",60);
  set("coor/y",430);
   set("coor/z",130);
   setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
        add_action("do_da", ({ "da", "gou" }));
        add_action("do_shuai", ({ "shuai" }));
} 

int do_da(string arg)
{
	object me=this_player();

	if( !present("nao gou",me) )
		return 0;
	if( arg!="naogou" && arg!="gou" && arg!="nao gou" )
		return notify_fail("��Ҫ��ʲô��\n");
	message_vision("$N�����е��ӹ���ס��һ��ͻ������ʯ��\n",me);
	me->set_temp("duanya/gou",1);
	return 1;
}

int do_shuai(string arg)
{
	object me=this_player();

	if( !present("tao suo",me) )
		return 0;
	if( arg!="taosuo" && arg!="suo" && arg!="tao suo" )
		return notify_fail("��Ҫ˦ʲô��\n");
	message_vision("$N���������е�����˦��ȥ����ס��һ��С������\n",me);
	me->set_temp("duanya/suo",1);
	return 1;
}

int do_pa(string arg)
{
       object me;
       me = this_player(); 

       if ( !arg ) return 0;
       if (arg != "ya" && arg!="up") 
          return notify_fail("��Ҫ����������\n");
	   if(!me->query_temp("duanya/gou"))
		   return notify_fail("�㷢����ʯ�⻬������������ȥ������Ҫ�����ӹ�֮��Ĺ��߲��С�\n");
	   if(!me->query_temp("duanya/suo"))
		   return notify_fail("�㷢����ʯ̫�ߣ�����������ȥ������Ҫ��������֮��Ĺ��߲��С�\n");

       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 20
		   || me->query("wxz/quest")<4 
		   || me->query("family/family_name")!="������" ) {
                message_vision("$N�������꣬�е��޷�����ȥ��ˤ��������\n", me);
                me->unconcious();
                return 1;
        } 

        message_vision("$N�������е��ӹ�������ʩչ�Ṧ������ȥ��\n", me);
        me->move(__DIR__"yading");
        tell_room(environment(me), me->name() + "����������������\n", ({ me }));
		me->delete_temp("duanya");
        return 1;
}
