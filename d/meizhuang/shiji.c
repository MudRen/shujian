// /d/meizhuang/shiji.c ʯ��
// By Lklv

inherit ROOM;

void create()
{
	set("short", "ʯ��");
	set("long", @LONG
����ɽ�ߵ�ʯ���������ۣ���֪���˶��ٸ��䡣�ߵ�ʯ����ͷ�����Կ���
��������С·�������ϱߡ�Զ���Ǵ�Ƭ��÷�֡�
LONG
);
/*	set("objects",([
		__DIR__"npc/you" : 2,
	]));*/
	set("outdoors","����");
	set("exits", ([
		"east" : __DIR__"road1",
		"west" : __DIR__"hubian",
	]));
	setup();
}
