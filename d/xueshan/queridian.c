// Room: queridian.c

inherit ROOM;

void create()
{
	set("short", "ȴ�յ�");
	set("long", @LONG
��������ż䣬������䣬���������������ڸ�̨�ϡ����ڲ�����������
��������Լ���ס����ܺ��ڲ۶������вʻ����ı��бڻ�������ʮ�𣬰�������
ʮ���޺��ȵȣ�������棬����������
LONG
	);

	set("exits", ([
		"north" : __DIR__"zhudubadian",
		"eastdown" : __DIR__"huilang6",
		"westdown" : __DIR__"huilang5",
		"south" : __DIR__"dadian",
	]));
        set("objects", ([CLASS_D("xueshan") + "/mohebasi" : 1,
	]));
	setup();
}
