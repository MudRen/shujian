// /d/hmy/houhuayen.c

inherit ROOM;

void create()
{
	set("short", "��԰");
	set("long", @LONG
�˴���������಻֪�����滨��ݣ��ھ���֮���������ľ�ɫ�������Ʈ
���ɾ��������ɻ����棬������һ��Сʯ�ݣ����ƺ�û���˾�ס��
LONG
	);
	set("outdoors", "��ľ��");
	set("exits", ([
		"north" : __DIR__"changlang5",
		"west" :__DIR__"shiwu",
	]));
/*
	set("objects", ([
		__DIR__"npc/zhang" : 1,
		__DIR__"npc/lan" : 1,
	]));
*/
	setup();
}
