// Room: /dali/xijie2.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������������ϣ��ֵ��ϻ��ݺ���ľ�����дУ��������󣬽����������
��Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��
ʳ�����޲�������ԭ�������Ǽ��¿��������������������⻹����
LONG
	);
	set("outdoors", "����");

	set("exits", ([ /* sizeof() == 2 */
		"south" : __DIR__"nanjie1",
		"north" : __DIR__"xijie6",
		"west" : __DIR__"yanzhi",
	]));

	set("objects", ([
		__DIR__"npc/shusheng" : 1,
	]));
	set("incity", 1);
	setup();
}
