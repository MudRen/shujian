//  /d/xueshan/shanlu.c

inherit ROOM;
void create()
{
	set("short", "����ɽ����");
	set("long", @LONG
����һ�����������С·���Ĵ��Թž��Ǹ���֮�أ��ų��츮֮��������
��ȥ�����ܵ������������ࡣԶ��������ɽ����Ŀ��ȥ�����������棬Ī�Ǿ�
�������Ķ���ɽ��
LONG);
	set("outdoors", "����");

	set("exits", ([
		"northeast" : "/d/group/entry/cdtulu2",
		"west" : "/d/emei/qingshijie",
	]));
	setup();
}
