// Modify By River 98/12 
inherit ROOM;

void create()
{
        set("short", "��԰");
	set("long", @LONG
�������������ں�԰��԰�Ӳ������˲�������Ĳ軨��԰�������и�
Сͤ�ӡ�ƽʱ�������ͼҳ������������¹ۻ���
LONG
	);
	set("exits", ([ 
	    "west" : __DIR__"lang7",
	    "east" : __DIR__"lang8",
	   ]));
	set("objects", ([
               __DIR__"npc/gdcheng" : 1,
        ]));
	set("coor/x",-290);
  set("coor/y",-470);
   set("coor/z",-20);
   setup();
}
