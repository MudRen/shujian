// Room: tulu3.c ��·
// By jpei

inherit ROOM;

void create()
{
	set("short", "��·");
	set("long", @LONG
����һ�����������С·����Ϊ�Ĵ��Թž��Ǹ���֮�أ����Է�����ȥ��
���ܵ��������������ࡣ�����Ǵ��У�����ʮ���ﴦ�����������񶼳ɶ��ˡ�
LONG);
	set("outdoors", "����");

	set("exits", ([
		"northeast" : __DIR__"sroad1",
		"southwest" : "/d/group/entry/cdtulu2",
	]));

	setup(); 
}
