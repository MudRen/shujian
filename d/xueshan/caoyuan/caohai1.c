// Room: caohai1.c

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
		"south" : "/d/hj/caoyuan2", 
		"west" : __DIR__"caohai2",
		"east" : __DIR__"caohai"+(random(6)+1),   
	]));
	set("outdoor","���ԭ");
	setup();
}
