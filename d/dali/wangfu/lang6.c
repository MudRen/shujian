// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "����");
	set("long", @LONG
�������������ڵ�һ�����ȣ�����һֱͨ�������ڣ��ȱߵ����˻��ߣ�͸
���ƿյĻ��ƣ�����Կ����������ľ���ݡ�������������֮�Ӷ��������ң� 
��������Ʒ�ҡ������ȥ��һ��С��԰��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
            "north" : __DIR__"lang4",
            "southwest" : __DIR__"lang8",
            "east" : __DIR__"wupinfang",
	    "west" : __DIR__"woshi2",
        ]));
	 
	set("coor/x",-270);
  set("coor/y",-460);
   set("coor/z",-20);
   setup();
}
