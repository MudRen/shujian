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
		"east" : __DIR__"ddajie2",
		"west" : __DIR__"center",
		"north" : "/d/group/cailiao-hang",
	]));

	set("incity",1);
	setup();
}
