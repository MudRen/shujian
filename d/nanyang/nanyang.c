// Room: /d/nanyang/nanyang.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
����������������ġ��������������ס�ڸ�����¡�������ڡ���������
�粻�󣬷�Բ������ʮ�������Ϊ�ش��ϱ���Ҫ���ϣ��������������ĸ���
�������˺ܶࡣ������һ�Ҿ�¥�������˿����٣��������ⲻ�Ǻ�����������
�������ֱͨ���ݳǡ�
LONG
	);
	set("outdoors", "����");
	set("exits", ([
		"south" : __DIR__"yidao2",
		"north" : __DIR__"yidao3",
		"west" : __DIR__"jiulou1",
	]));
	set("objects",([
		__DIR__"npc/xiao-fan" : 1,
	]));
	setup();
}