// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�������������ڵ�һ�����ȣ�����һֱͨ�������ڣ��ȱߵ����˻��ߣ�͸
���ƿյĻ��ƣ�����Կ����������ľ���ݡ������ǹ�ȥ��һ��С��԰��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */            
            "northwest" : __DIR__"lang5",            
	    "east" : __DIR__"huayuan",
        ]));
	 
	set("coor/x",-300);
  set("coor/y",-470);
   set("coor/z",-20);
   setup();
}
