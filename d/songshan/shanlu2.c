// Room: /u/swl/songshan/shanlu2.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
��·�ƺ�Խ��Խ���ˣ����ŵ�·����ɽ·�����˲��������·����
ȥ����һ��·��(sign)ָ����ķ���һ�����Ϯ�����������󡣶���
����·������ƽ̹�ˡ�
LONG);
	set("item_desc", ([ 
            "sign" : "
       ��������ɽ����
       ���ϣ���ɽ������\n\n",
       ]));
	set("exits", ([ 
            "east" : __DIR__"shanlu1",
            "northwest" : __DIR__"gsfxia",
        ]));
        set("objects", ([ 
            NPC_D("youke") : 2,
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",70);
  set("coor/y",150);
   set("coor/z",60);
   setup();
}
