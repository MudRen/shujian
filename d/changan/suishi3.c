// Write By actiong@SJ 2009.1.6
// Room: /d/changan/suishi3.c
inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
һ����ʯС·�����¹��꣬·�濴���������ɾ��ģ�һЩ����������
�Լ��ֵ��߲˵������������˲��Ǻܶ࣬ߺ����������Զ��·������һ��
����ؤ���������޼ҿɹ�������Ĵ��ε�����������Կ�����������һ
�档·�����߶��ǵ��ص�һЩ��լ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
  		"northwest" : __DIR__"eastroad1",
  		"south" : __DIR__"suishi2",
	]));

	set("coor/x", -120);
	set("coor/y", -30);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
