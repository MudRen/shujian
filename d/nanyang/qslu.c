// Room: /d/nanyang/qslu.c
// Lklv Modify 2001.10.11

inherit ROOM;
void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
������Ҽ��ϵ�һ����ʯ·��·��������һ��ϸ���ʯ�ӣ�·�ϵ����˲�
�ࡣ��������Ҽ����м���������һ��С·ͨ������ׯ��
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"east" : __DIR__"xiaolu3",
		"west" : __DIR__"xiaolu",
		"south" : __DIR__"xujiaji",
	]));
	setup();
}
