// Room: /d/emei/milin.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���Ǻ�ɭɭ��һƬ���֣��ľ���죬Ũ�����ա����ﶫ�¶����Ǳ����£�
�����ּ�������һ�����
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ 
	  "northeast" : __DIR__"baoguosi",
	  "west" : __DIR__"fuhusi",
]));

	set("coor/x",-200);
  set("coor/y",-130);
   set("coor/z",10);
   setup();
}
