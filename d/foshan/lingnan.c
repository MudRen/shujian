// Room: /d/fuoshan/lingnan.c 
 
inherit ROOM; 
 
void create() 
{ 
	set("short", "����");
	set("long", @LONG
���������ϵ�һ��ɽ�ڡ�������Ƿ�ɽ�ˣ������Ǻ�ب���Ϲ�
�������롣����������ȣ����������쳤������ҲԶ����ԭ�ˡ�
LONG
	);
        set("outdoors","��ɽ");
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"beimen",
  "north" : __DIR__"xiaolu1",
]));
	set("no_clean_up", 0);

	set("coor/x",0);
  set("coor/y",-500);
   set("coor/z",0);
   setup();
}
