// dezj.c �ڶ�ָ��

inherit ROOM;

void create()
{
	set("short", "�ڶ�ָ��");
	set("long", @LONG
�����ѵ�����ָ��İ�ɽ���ˣ���������ɽ���е�����ָһ����ÿ��ɽ��
�ַ����أ�������ָ��ָ��һ�㣬�����������λ�ڵڶ�ָ�ڵ�λ�á�������
�嶥�ѽ���͸���������������ѿ��Կ���ɽ·�ľ�ͷ�ˡ���ǰ����ʮ���ɴ���
�����������һ����Ѩ(dong)������������ʯ���޽��ü���������
LONG);
	set("outdoors", "����");
	set("exits", ([
		"south" : __DIR__"sslin-5",
		"northup" : __DIR__"shanlu-8",
		"enter" : __DIR__"dong-1",
	]));
	set("cant_hubiao", 1);
	set("objects", ([
		__DIR__"npc/mayi2" : 1,
		__DIR__"npc/mayi3" : 1,
	]));
	set("item_desc", ([
		"dong" : "һ���������ɽ�����ڰ���ż���м����׹������������ˣ�����\n",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir == "enter"
	 && (present("huang lingtian", environment(me)) || present("ling zhentian", environment(me))))
		return notify_fail("���³��Ϻȵ����������ư���أ��κ��˲������ڣ�����������������\n");

        return ::valid_leave(me, dir);
}