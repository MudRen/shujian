// Room: /d/taishan/.c

inherit ROOM;

void create()
{
	set("short", "��ĸ��");
	set("long", @LONG
����һ��ɽ·������һ�㶼����������Ϊ��Ϣ������ĵ����Ѿ���̩ɽ��
��������ɽΪ�ߣ��������������߱���ʯ������
LONG
	);

	set("exits", ([
		"eastup" : __DIR__"shijin",
		"southdown" : __DIR__"yitian",
	]));

	set("objects",([
		__DIR__"npc/jian-ke1" : 1,
	]));

	set("outdoors", "̩ɽ");
	setup();
}
