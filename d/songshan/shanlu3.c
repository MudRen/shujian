// Room: /u/swl/songshan/shanlu3.c

inherit ROOM;

void create()
{
	set("short", "ɽ·");
	set("long", @LONG
���ﴦ��Ⱥɽ����֮�У���ʤ��������󣬶��ٲ����Բ����ڶ���
���û��������·��Ҳ��ʮ��������·��
LONG);
	set("exits", ([ /* sizeof() == 2 */
            "northup" : __DIR__"qgfeng",
            "southup" : __DIR__"guanshengfeng",
        ]));
        set("jingli_cost/northup", 10);
	set("outdoors", "��ɽ");
	set("coor/x",50);
  set("coor/y",170);
   set("coor/z",60);
   setup();
}



