// Write By Yanyang@SJ 2001.9.20
// Room: /d/changan/northjie1.c

inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
����һ����������ʯ�ֵ������ϱ���ͷ���졣�����Ǳ�����ͨ����⡣��
�����ǳ����ĵ���¥��������һ�������¥���Ŷ���������һ�����ң�����
����¥�����ֲ�������������������һ�����¥ͬ���Ŀ�ջ��
LONG
        );
	set("outdoors", "����");

	set("exits", ([
		"east"   : __DIR__"juhao",
		"south"  : __DIR__"zhonglou",
		"west"   : __DIR__"kezhan",
		"north"  : __DIR__"northjie2",
	]));
	set("objects", ([
		CLASS_D("gaibang/qigai") : 1,
	]));
	set("incity",1);
	setup();
}