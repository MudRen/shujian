// Room: eroad3.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�������ϱ�ͨ���Ĵ����в������治Զ�����Ǵ�
������ĵط��ˡ�
LONG);
	set("outdoors", "�ɶ�");

	set("exits", ([
		"east" : "/d/group/entry/cderoad4",
		"southwest" : __DIR__"eroad2",
	]));

	setup(); 
}
