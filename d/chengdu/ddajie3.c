// Room: /d/chengdu/dongdajie3.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��Ķ���֡�����ͨ�򶫳��ţ������Եúܷ�æ���ϱ�������ʯ��
·��ͨ���ϲ��š�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"ddajie4",
		"west" : __DIR__"ddajie2",
		"south" : __DIR__"nancejie1",
	]));

	set("incity",1);
	setup();
}

