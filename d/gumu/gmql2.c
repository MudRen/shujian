// Room: /u/xdd/gumu/gmqianliu2.c
// Modify By River 98/09
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", HIR"Ǳ��"NOR);
	set("long", @LONG
��û��ˮ�У�ֻ��ˮ��������������޷����㡣�������쳣��ֻ��������
��Ǳ�У������ǽ���ά�ȡ�
LONG    
    );

	set("exits", ([
		"westup" : __DIR__"gmanhe2",
		"east" : __DIR__"gmql1",
	]));    

	setup();
}

void init()
{
	object me;
	me = this_player();
	if ( me->query_skill("yunu-xinjing", 1) < 115 ) {
		me->receive_damage("qi", 50 );
		me->receive_damage("jing", 50 ); 
		message_vision(HIB"$N������������ʧ������ʮ�����ѡ�\n"NOR, me);
		if ((int)me->query("qi") < 10 || (int)me->query("jing") < 10) {
			me->set_temp("last_damage_from","��Ǳ���б���");
		//	me->unconcious();
			me->die();   
			return ;
		}
	}
	message_vision(HIB"$N��ס�������ɹ���Ǳ����\n"NOR, me);
}
