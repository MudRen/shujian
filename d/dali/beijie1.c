// Room: �����/dali/beijie1.c
// bbb 1997/06/11
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���Ǵ�����֣����߲�ݵ�����ӭ���������Ʈ��һЩ���������ߺ�
�裬�������졣�����Ǵ������Ҫ���õ�ǰ�����������˽����������������
���ˡ��������ֵ�������ͣ�Ĵ��˹������쵽��������Ĺ㳡�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
		"east" : __DIR__"beijie2",
		"west" : __DIR__"chaguan",
		"south" : __DIR__"xijie1",
		"north" : __DIR__"yamen",
	]));
	set("objects", ([ 
		__DIR__"npc/biaotou" : 1, 
	]));

	set("outdoors", "����");
	setup();
}
