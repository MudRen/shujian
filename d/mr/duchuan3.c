// /u/beyond/mr/duchuan3.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ����ʮ������������ֳֳ���ݣ�
���ڴ�β�����س��Ŵ���
LONG
	);
	set("exits",([
		"out"  :  __DIR__"xiaodao",
	]));
	set("outdoors", "Ľ��");
	set("no_fight",1);

	setup();
}

void init()
{
	object me;
	me=this_player();
	message_vision(YEL "\n���ڵ���С���ߣ������С�ۿ��ڰ��ߣ����´��ɡ�\n\n"NOR,me);
}
