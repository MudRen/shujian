// Room: tianyunmc.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������һ��Ƭ�����Ĳ�ԭ������ެ���ҵľ��������۹�ȥ����ԭ�Ϲ�����
������Ⱥֻ������ǧƥ֮�࣬ƥƥ�����׳���񿥷ǳ������������ǽ�ֹ��ͨ��
�շ����ģ����Գ�����ƥ���������ʲô����
LONG
	);

	set("exits", ([
		"south" : __DIR__"jushuimen",
		"east" : __DIR__"caishichang",
	]));
        set("outdoors", "ѩɽ");
	set("coor/x",-220);
  set("coor/y",150);
   set("coor/z",0);
   setup();

}
