// Modify By River 98/12 
inherit ROOM;
void create()
{
        set("short", "����");
	set("long", @LONG
�������������ڵ�һ�����ȣ�����һֱͨ�������ڣ��ȱߵ����˻��ߣ�͸
���ƿյĻ��ƣ�����Կ����������ľ���ݡ������������������ң���������
���������ȥ��һ��С��԰��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"lang3",
            "southeast" : __DIR__"lang7",
            "east" : __DIR__"shufang",
	    "west" : __DIR__"woshi1",
        ]));

	set("objects", ([
		__DIR__"npc/caodi-puren": 1,
	]) );
 
        set("coor/x",-310);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();
}
