// Room: /dali/jiulou.c
// bbb 1997/06/11
// Modify By River 98/12/
inherit ROOM;
//inherit F_DEALER;

void create()
{
	set("short", "��ѩ¥");
	set("long", @LONG
�����Ǵ����������ľ�¥��������Դ�ڵ��ɽ����ѩ��Ϫ��ۣ�ƽʱ����
����������һ�����ո���Ҫ��ǰ�������ż䡣����������ǰ����ﵱ�ɾۻ��
��������ʱ�н������ͽ���������
LONG
	);

	set("item_desc", ([
		"paizi" : "������ۿ�Ѽ���ϵȻ���ơ�\n",
	]));

	set("objects", ([
		__DIR__"npc/xian" : 1,
	]));

	set("exits", ([
                "north" : __DIR__"beijie4",
                "west" : __DIR__"dalics",
                "east" : __DIR__"dongjie1",
                "south" : __DIR__"doufufang",
	]));

	set("coor/x",-300);
  set("coor/y",-390);
   set("coor/z",-20);
   set("coor/x",-300);
  set("coor/y",-390);
   set("coor/z",-20);
   setup();
}
