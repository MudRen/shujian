// Room: /d/chengdu/dongdajie2.c
// By Jpei

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
���ǳɶ��Ķ���֡�����ͨ�򶫳��ţ������Եúܷ�æ���ϱ���һ����լ
ۡ����֪���ĸ����ҹ������ӡ�
LONG
	);
        set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : __DIR__"dongdajie3",
		"west" : __DIR__"dongdajie1",
		"south" : __DIR__"zijuefumen",
	]));

	setup();
}

