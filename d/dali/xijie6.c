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
ʳ�����޲�������ԭ�������Ǹ�ϷԺ�������ֵ������ź�Ϸ��
LONG
	);
	set("outdoors", "����");
	set("exits", ([ /* sizeof() == 2 */
		"west" : __DIR__"xiyuan",
		"north" : __DIR__"xijie5",
		"south" : __DIR__"xijie7",
	]));
	set("incity", 1);
	setup();
}
