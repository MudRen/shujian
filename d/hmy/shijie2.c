// /d/hmy/shijie2.c ʯ��

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
Խ���ϣ�ɽ��Խ���ͣ��м��ʯ��Խխ������һ�����ߣ���������������
��Լ����һ��ʯ�š�
LONG
	);
	set("exits", ([ 
	  "westup" : __DIR__"shimen",
	  "eastdown" : __DIR__"shijie",
]));
	set("outdoors", "��ľ��");
	setup();
}
