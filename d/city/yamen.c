// Room: /d/city/yamen.c

inherit ROOM;

void create()
{
	set("short", "���Ŵ���");
	set("long", @LONG
���������Ŵ��ţ�������ľ���Ž����ر��š����ྲ�����رܡ������ӷ�
����ͷʯʨ�ӵ��Աߡ�ǰ����һ����ģ���Ȼ�ǹ�С����ԩ�õġ�����������
��ǰѲ�ߡ��׻�˵���¹��������ѻ���λ�����ε�֪�����˾������ſ�ǰ��
����һ�顰������ԩ�塱�������ճ���ԩ�顣
LONG
	);

	set("exits", ([
		"south" : __DIR__"guangchangbei",
		"north" : __DIR__"menlang",
	]));

	set("objects", ([
		__DIR__"npc/yayi" : 4,
	]));

	set("coor/x",100);
	set("incity",1);
	setup();
	call_other("/clone/board/towiz_b", "???");
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("ya yi", environment(me))) && dir == "north"){
		if( me->query_condition("killer"))
			return notify_fail("���ۺȵ���������˭������뿪�����\n");
		if( !objectp(present("tiebu wenshu", me)) )
			return notify_fail("���ۺȵ������������䡭������\n");
	}
	return ::valid_leave(me, dir);
}
