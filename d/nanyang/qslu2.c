// Room: /d/nanyang/qslu2.c
// Lklv Modify 2001.10.11

inherit ROOM;
void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
������Ҽ��ϵ�һ����ʯ·��·��������һ��ϸ���ʯ�ӣ�·�ϵ����˲�
�ࡣ��������Ҽ����м���
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"north" : __DIR__"xujiaji",
	]));
	setup();
}
