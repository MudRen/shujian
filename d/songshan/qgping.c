// Room: /u/swl/songshan/qgping.c

inherit ROOM;

void create()
{
	set("short", "���ƺ");
	set("long", @LONG
������һ��ܴ�Ŀյأ��ӵ�·����ȥ����һ��Ƭɽ�ȣ�������
���Ǵ�Ƭ���֣��������ɽ���Ը߸ߵص�ס�����ߡ�
LONG);
	set("exits", ([ 
            "southdown" : __DIR__"qgfeng",
            "northup" : __DIR__"dtlxia",
        ]));
        set("objects", ([ 
            NPC_D("youke") : 2,
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",50);
  set("coor/y",190);
   set("coor/z",80);
   setup();
}
