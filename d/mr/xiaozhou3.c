// /u/beyond/mr/xiaozhou3.c
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "�ɴ�");
	set("long", @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ���������ֳֳ���ݣ����ڴ�β
�����س��Ŵ���
LONG
	);
	set("outdoors", "Ľ��");

	set("exits",([
		"out"  :  __DIR__"mtl/anbian",
	]));
        set("no_fight",1);
	setup();
}

void init()
{
	object me;
	me=this_player();
	message_vision(YEL"\n���ڵ��˰��ߣ������С�ۿ��ڰ��ߣ����´��ɡ�\n\n"NOR,me);
}
