// cailiao hang
// by augx@sj  3/21/2002

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"������"NOR);
	set("long", @LONG
���Ǽ�������¡�Ĳ����У��������˶������������췿�ݵĲ��ϡ����
�������а�������û�����������Ĳ�ͣ�İ������˵������ƹ�ܺܶ���
���ϴ��ϵ�������������������������Ҫ����Ǯ�����ʾͿ����ˡ�
LONG
	);
	set("indoors", "�ɶ���");

	set("exits", ([
		"south" : "/d/chengdu/ddajie1",
	]));
	set("objects", ([
		__DIR__"npc/wang-zhanggui" : 1,
	]));

	set("incity",1);
	setup();
}
