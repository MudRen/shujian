// /d/xingxiu/silk10.c

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�������������˿���̵�����ɳ������һƬ��������������е��˳�û��
����ͨ��һƬ�����ɽ�����������ͨ����ԭ��·��·����һ��ʯ��(shibei)��
LONG );
       set("outdoors", "yili");

        set("exits", ([
                "southeast" : __DIR__"silk8",
                "west" : __DIR__"shamo1",
                "northwest" : __DIR__"shanjiao",
        ]));

        set("item_desc", ([
                "shibei" : "�������򣬶�����ԭ�����б��Ǹ߲��ˡ�\n",
        ]));

        set("coor/x",-300);
  set("coor/y",120);
   set("coor/z",0);
   set("coor/x",-300);
  set("coor/y",120);
   set("coor/z",0);
   set("coor/x",-300);
 set("coor/y",120);
   set("coor/z",0);
   setup();
}
#include "/d/xingxiu/job2.h";