// Room: eroad2.c ���
// By jpei

inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
����һ������ʯ�̳ɵĴ�������ϱ�ͨ���Ĵ����в����򶫱��߿���ȥ��
������
LONG);
	set("outdoors", "�ɶ�");

	set("exits", ([
		"northeast" : __DIR__"eroad3",
		"southwest" : __DIR__"eroad1",
	]));

	setup(); 
}
