// Room: �����/dali/beijie2.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�����֣���������������������С������Ҳ�������������ϵ�
��Ҫ���С�������������¥����ʱ���������˹��������������ű���֣���
�����ֵ�������ͣ�Ĵ��˹������쵽��������Ĺ㳡�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"beijie3",
		"west" : __DIR__"beijie1",
		"south" : __DIR__"fengwei",
	]));
	set("outdoors", "����");

	setup();
}
