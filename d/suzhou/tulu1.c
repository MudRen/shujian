// tulu1.c
// By Jpei

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long",@long
��������һ����·�ϣ����ϱ߲�Զ������������������ȥ���ݵĹٵ���
long);
	set("outdoors", "����");
	set("exits",([
		"north" : __DIR__"qsgdao5",
		"southwest" : "/d/group/entry/sztulu2",
	]));
	set("objects", ([
		CLASS_D("gaibang/lisheng") : 1,
        ]));

	setup();
}
