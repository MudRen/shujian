// Room: /u/zqb/tiezhang/sslu-2.c

inherit ROOM;

void create()
{
	set("short", "��ʯ·");
	set("long", @LONG
������һ������ʯ�̳ɵ�С·�ϡ�����ɽ�Ƶͻ��������˴��̵�ë����
��΢�紵�������Ա�����һƬɳɳ����
LONG
	);

	set("exits", ([ 
  "eastup" : __DIR__"sslu-3.c",
  "westdown" : __DIR__"sslu-1",
]));
	set("no_clean_up", 0);
	set("outdoors", "tiezhang");

	set("coor/x",-310);
  set("coor/y",-200);
   set("coor/z",50);
   setup();
}
