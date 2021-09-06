// Room: /d/shaolin/zhonglou.c
// Date: YZC 96/01/19

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
		"west" : __DIR__"celang-3",
		"enter" : __DIR__"zhlou1",
	]));

	set("objects",([
		__DIR__"npc/seng-bing3" : 2,
	]));

	set("outdoors", "shaolin");
	set("coor/x",70);
  set("coor/y",230);
   set("coor/z",110);
   setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "seng bing" &&  dir == "enter" ) return 0;

	return ::valid_leave(me, dir);
}




