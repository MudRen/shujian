// /d/hmy/dedao.c

inherit ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
�ص�һ·���£����Ե��ż�յ�͵ƣ�����綹��һƬ�������أ����ҵص�
������������ת����ͷ���ۻ���
LONG
	);
	set("exits", ([ 
		"down" : __DIR__"xhuayuan",
		"up" : __DIR__"shiwu",
	]));
	setup();
}
