// By River 2002.6.3

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", "ʯ������");
	set("long", @LONG
����С���ϵ���һ¯̴�㣬������������һ��ɮ�ˡ�ֻ�������ֲ�ɮ�ۣ�
���������İ�ü���۽Ǵ�����������Ŀ���飬ü����������࣬��һ��Ӻ�ݸ�
������ɫ��ȴ��һ����֪��
LONG
	);
	set("exits", ([
		"east" : __DIR__"xiangfang",
		"south" : __DIR__"zhulin",
	]));

	set("objects", ([
		__DIR__"npc/yideng" : 1,
	]));

	setup();
}
