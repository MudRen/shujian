// modify by Lklv 2001.12.31

inherit ROOM;

void create()
{
	set("short", "�͵�");
	set("long", @LONG
����һ�Ҽ�Ǯ�����Ŀ�ջ������ǳ���¡������οͶ�ѡ��������ţ�
�������������������صķ������顣��С����������æ������ת���Ӵ���
��ǻ�����Ŀ��ˡ��͵�����˴Ӳ�¶�棬��������˭���и��ָ����Ĳ²⡣
ǽ�Ϲ���һ������(paizi)��
LONG);
	set("valid_startroom", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"paizi" : "¥���ŷ���ÿҹ����������\n",
	]));
	set("objects", ([
		__DIR__"npc/xiaoer" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"beidajie1",
		"up" : __DIR__"kedian2",
	]));
	set("incity",1);
	setup();
	"/clone/board/kedian_b"->foo();
}

int valid_leave(object me, string dir)
{
	if ((string)me->query_temp("rent_paid")!="���ݿ�ջ" && dir == "up" )
		return notify_fail("��ô�ţ����ס����\n");
	if ((string)me->query_temp("rent_paid")=="���ݿ�ջ" && dir == "west" )
		return notify_fail("�͹��Ѿ��������ӣ���ô��ס��������أ����˻���ΪС���ź����أ�\n");
	return ::valid_leave(me, dir);
}
