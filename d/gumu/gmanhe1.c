// Room: /u/xdd/gumu/gmanhe1.c
// Modify By River 98/09
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"����"NOR);
	set("long", @LONG
ԭ��������һ�����°��ӣ��˴�ˮ�����Ǻ�䣬���Ƽ�Ϊ���ˡ������һ
��̤�գ�����ˮ��ֱ���ʺ���Ǳ����֪���Ժδ�������֪ͨ���η���
LONG 
       );

	set("exits", ([
		"northup" :  __DIR__"sshi1",
		"westdown" : __DIR__"gmql1",
	]));

	setup();
}

void init()
{
	object me;
	me = this_player();
        if ( me->query_skill("yunu-xinjing", 1) < 110 ) {
		me->receive_damage("qi", 50 );
		me->receive_damage("jing", 50 ); 
		message_vision(HIB"$N������������ʧ������ʮ�����ѡ�\n"NOR, me);
		if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10) {
			me->set_temp("last_damage_from","�ڰ����б���");
		//	me->unconcious();
			me->die();   
			return ;
		}
	}
	message_vision(HIB"$N��ס�������ɹ��˰��ӡ�\n"NOR, me);
}
