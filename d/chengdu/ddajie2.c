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
		"east" : __DIR__"ddajie3",
		"west" : __DIR__"ddajie1",
                "south" : __DIR__"zjmen",
	]));

	set("incity",1);
	setup();
}
