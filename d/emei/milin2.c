// Room: /d/emei/milin2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����������Ǳ����£�����
�ּ�������һ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([
	  "eastdown" : __DIR__"fuhusi",
	  "westup" : __DIR__"jietuopo",
]));

	set("coor/x",-220);
  set("coor/y",-130);
   set("coor/z",20);
   setup();
}
