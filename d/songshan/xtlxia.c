// Room: /u/swl/songshan/xtlxia.c

inherit ROOM;

void create()
{
	set("short", "С����Ͽ");
	set("long", @LONG
��������κʹ�����Ͽ���ƣ�������·������խ��һ��ɽ��Ϯ����
���ƺ���Ҫ������ǧ����Ԩ�����˲���������
LONG);
	set("exits", ([ 
            "southdown" : __DIR__"dtlxia",
            "northwest" : __DIR__"shanlu4",
        ]));
        set("jingli_cost/northwest", 20);
	set("outdoors", "��ɽ");
	set("coor/x",50);
  set("coor/y",210);
   set("coor/z",100);
   setup();
}


