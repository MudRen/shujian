#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", YEL"ɽ·"NOR);
    set("long",@LONG
����һ��һխ�ֶ���ɽ·�������Ѽ���ѩ����ѩ����ɽ·�����ָ����ӵ�
�Ҳ�������������������е�����ĺ���ӿ����ͷ���ϱ��ǰ�ɽ����
LONG);
    set("exits",([
        "northdown"  :     __DIR__"gmd",
        "westup"   :     __DIR__"shanlu2",
    ]));
    set("coor/x",-320);
  set("coor/y",120);
   set("coor/z",70);
   set("coor/x",-320);
 set("coor/y",120);
   set("coor/z",70);
   setup();
    set("outdoors", "���̹�����");
}
int is_mirror() { return 1; }