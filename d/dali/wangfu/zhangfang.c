// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short","�ʷ�");
	set("long", @LONG
�����������������ʷ����ܼһ�������������������Ĳ鿴�ʲ�����ʱ��
��˼��ʲô.�����ĵ��߽�����������Ӱ���������˼����
LONG
	);
	set("exits", ([ 
	    "east" : __DIR__"lang4",
        ]));
	set("objects", ([
            __DIR__"npc/huo" : 1
        ]));

	set("coor/x",-280);
  set("coor/y",-450);
   set("coor/z",-20);
   setup();
}
