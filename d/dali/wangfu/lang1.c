// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�������������ڵ�һ�����ȣ�����һֱͨ�������ڣ��ȱߵ����˻��ߣ�͸
���ƿյĻ��ƣ�����Կ����������ľ���ݡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	     "south" : __DIR__"lang3",
	     "east" : __DIR__"dating",
        ]));
	
	set("coor/x",-310);
  set("coor/y",-440);
   set("coor/z",-20);
   setup();
}
