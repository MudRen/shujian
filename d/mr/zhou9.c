// /u/beyond/mr/zhou9.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "С��");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳֳ���ݣ�
���ڴ�β�����س��Ŵ���
LONG
	);
	set("outdoors", "Ľ��");

	set("exits",([
		"out"  :  __DIR__"xiaodao",
	]));
        set("no_fight",1);

	setup();
}

void init()
{
	object me;
	me=this_player();
	message_vision(YEL "\n�����С�ۿ��ڰ��ߣ����´��ɡ�\n\n"NOR,me);
}
