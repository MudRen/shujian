// Room: /d/huashan/v-road-2.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
������Χ���ǹ�ľ�����ϵķ���Ͷ���ķ����ƺ����߹�ȥ��
LONG);
        set("exits", ([ /* sizeof() == 2 */
                "eastup"        : __DIR__"v-road-3",
                "southwest"     : __DIR__"v-road-1"
        ]));
        set("outdoors", "��ɽ");
        set("no_clean_up", 0);
        set("coor/x",50);
  set("coor/y",90);
   set("coor/z",-10);
   setup();
}