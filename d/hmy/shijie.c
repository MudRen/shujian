// /d/hmy/shijie.c

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ɽ·ͻȻ���ͣ�����ɽ��������м�����һ��խխ��ʯ�ף��������˲���
���С�
LONG
	);
	set("exits", ([ 
	  "westup" : __DIR__"shijie2",
	  "eastdown" : __DIR__"baichi",
]));
	set("outdoors", "��ľ��");
	setup();
}
