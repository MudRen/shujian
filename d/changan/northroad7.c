// Write By Yanyang@SJ 2001.10.13
// Room: /d/changan/northroad7.c

inherit ROOM;

void create()
{
        set("short", "��·");
        set("long", @LONG
����һ�����������·������̫��·�ϼ���û�����ˣ�����һ����į��
�о���·������ɢɢ�ķֲ��ż�ƬС��أ�żȻҲ�ܿ��ü�һЩ���̡�����һ
Ƭ�Ļļš�
LONG
	);
	set("outdoors", "����");

        set("exits", ([
		"northeast"  : __DIR__"northroad8",
		"southup"  : "/d/group/entry/canroad6",
	]));

	set("objects",([
		__DIR__"npc/keshang" : 1,
	]));

	setup();
}
