// Room: /d/xingxiu/xx1.c
// Update by caiji@SJ 8/24/2000
// Modify by Lklv 2001.10.16

inherit ROOM;

void create()
{
    set("short", "ɽǰ�ĵ�");
    set("long", @LONG
������һ��ʯɽǰ�Ļĵأ�ƽ���˼�������������ȥ���ǿ����ܲݣ�ʮ��
������һ��˷����ɱ�������ľ�������·���м������޵�����������ͬʱ�ڶ�
�����˵�һ��һ������û�»��ǿ��߰ɡ�
LONG);
	set("outdoors", "����");
	set("objects", ([
		__DIR__"npc/feitian" : 1,
		__DIR__"npc/xxdizi" : 1,
	]));
	set("exits", ([
		"northup" : __DIR__"ryd1",
		"northwest" : __DIR__"xx2",
		"south" : __DIR__"xxh2",
		"northeast" : __DIR__"rukou",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");

	if (dir =="northup" && present("feitian zi", environment(me))
	 && me->query("family/family_name") != "������"
	 && me->query("combat_exp") < 100000)
		return notify_fail("�����ӵ�ס�������������������а�ɵ��ӣ���ô����ȥ�ݼ���ʦ������\n");

	return ::valid_leave(me, dir);
}
