// Room: /city/nandajie2.c
// YZC 1995/12/04 
// CLEANSWORD 1996/2/2
inherit ROOM;
void create()
{
	set("short", "�ǳ�");
	set("long", @LONG
	ɽ���صĳǳأ��ܳ�Լ4�����һ��С�ǣ������ǳ��볤����������
��Ϊ�ء��Ǹ�14�ף���7�ס�ȫ����������Ҫ���ţ����ж��ֹŴ��ķ�����������
һ��������ϵ�Ƚ������ĳǹء�
LONG
	);
        set("outdoors", "city");
	set("exits", ([
		"east" : __DIR__"lichunyuan",
		"south" : __DIR__"nanmen",
		"west" : __DIR__"chaguan",
		"north" : __DIR__"nandajie1",
	]));

	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "east" && (int)me->query("age") < 18 && !wizardp(me))
		return notify_fail("С���Ѳ�Ҫ�����ֵط�ȥ����\n");
	return 1;
}
//�Ǿ���
int is_mirror() { return 1; }
