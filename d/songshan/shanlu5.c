// Room: /u/swl/songshan/shanlu5.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
�����ͨ��������ɽ·���Ѿ��������������Ŀ��أ�ʮ�־޴󣬶�
·������Ҳ�в�����ľ��ż������һЩ������һ��ׯ�ϵ����ɡ�
LONG);
 	set("exits", ([ 
            "southwest" : __DIR__"ctmen",
            "northup" : __DIR__"taishi-que",
        ]));
	set("outdoors", "��ɽ");
	set("jingli_cost/northup", 10);
	set("coor/x",40);
  set("coor/y",240);
   set("coor/z",100);
   setup();
}



