// /d/hmy/shandao.c ɽ��

inherit ROOM;

void create()
{
	set("short", "ɽ��");
	set("long", @LONG
������һ����ɽ�����Ƽ�֮�վ���һ��խС���͵�ɽ��ͨ��ɽ�ϣ�����ɽ
����һƬ��̲��
LONG
	);
	set("outdoors", "��ľ��");
	set("exits", ([ 
		"west" : __DIR__"changtan",
		"westup" : __DIR__"shandao2",
	]));
	setup();
}
