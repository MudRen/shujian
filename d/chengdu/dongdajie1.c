// Room: /d/chengdu/dongdajie1.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��Ķ���֡�����ͨ�򶫳��ţ������ǳ����ġ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"west" : __DIR__"center",
	]));

	setup();
}

