// Room: /d/emei/huazangan.c ������ ������

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short",HIY "������" NOR);
	set("long", @LONG
�������ǽ𶥵���Ҫ��������ģ������������������������
�����ֺ���Ƕù�̨���Ա��������֡�
LONG
	);

	set("exits", ([
		"northdown" : __DIR__"jinding",
		"south" : __DIR__"duguangtai",
		"enter" : __DIR__"huazanganzd",
	]));

	setup();
}
