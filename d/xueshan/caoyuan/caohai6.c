// Room: caohai6.c

inherit ROOM;

void create()
{
	set("short", "�ݺ�");
	set("long", @LONG
֮���Գ�Ϊ�ݺ�������˵���ܶ���һ���޼ʵĲ�ԭ���������ĳ̶Ⱦͺ���
����һ�����ڲݺ��������Ǻ�������·�ģ���Ϊ���ܵ��涼���ݸ����ˣ�û��
·���Ա��ϣ�ֻ��ƾ�������ǳ�����򣬲ݺ��л��кܶ�Σ�յ�����ء�
LONG
	);

	set("exits", ([
		"north" : __DIR__"caohai"+(random(6)+1),
		"south" : __DIR__"caohai"+(random(6)+1),
		"west" : __DIR__"zhaoze"+(random(3)+1),
		"east" : __DIR__"yingmen",   
	]));
	set("outdoor","���ԭ");
	setup();
}
