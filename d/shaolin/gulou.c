// Room: /d/shaolin/gulou.c
// Date: YZC 96/01/19
// by zqb

inherit ROOM;

void create()
{
	set("short", "��¥СԺ");
	set("long", @LONG
����һ��שľ�ṹ�ı����������߲㣬�������˽��Σ��������ᣬ�ܽ�
�Ϲ�����һ����Сͭ�壬��綣�����졣����ǽ���οյ�������������ǵ�
����һ������̬άФ��������������֮�֡�������ڴ�����һ�ȹ��ε�С
ľ�ţ����������ò���Ϳ�棬��������������ɽ�������ڷ𽲾�ʱ�����Ρ�
LONG
	);

	set("exits", ([
		"east" : __DIR__"celang-1",
		"enter" : __DIR__"gulou1",
	]));

	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));

	set("outdoors", "shaolin");
	set("coor/x",30);
  set("coor/y",230);
   set("coor/z",110);
   setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "enter" ) return 0;

	return ::valid_leave(me, dir);
}


