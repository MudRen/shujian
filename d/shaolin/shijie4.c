// Room: /d/shaolin/shijie4.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "ʯ��");
	set("long", @LONG
ˮ��Խ��Խ��ɽ�������ŨŨ��ˮ����ʯ���ϣ����ѵ�ɽ϶�У�����
��һ����ϸϸ��Ȫˮ�����һ�ɳα̵�СϪ����ɽ��������ȥ����Χ���⵴
���������������������ɾ���
LONG
	);

	set("exits", ([
		"northup" : __DIR__"shijie5",
		"southdown" : __DIR__"shijie3",
	]));

	set("outdoors", "shaolin");
	set("coor/x",80);
  set("coor/y",130);
   set("coor/z",30);
   set("coor/x",80);
 set("coor/y",130);
   set("coor/z",30);
   setup();
}



