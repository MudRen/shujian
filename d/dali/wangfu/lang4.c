// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�������������ڵ�һ�����ȣ�����һֱͨ�������ڣ��ȱߵ����˻��ߣ�͸
���ƿյĻ��ƣ�����Կ����������ľ���ݡ��������ʷ��������ǳ�����
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"lang2",
	    "south" : __DIR__"lang6",
	    "west" : __DIR__"zhangfang",
            "east" : __DIR__"chufang",
        ]));
	 
	set("coor/x",-270);
  set("coor/y",-450);
   set("coor/z",-20);
   setup();
}
