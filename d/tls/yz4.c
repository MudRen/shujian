#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"����Ժ"NOR);
        set("long", @LONG
����һ����ֲ�����СԺ�ӣ�����һ��С·��ͨ������������
ʯ�����ɨ�÷ǳ��ɾ�����紵����ֻ������Ҷ���Ʈ��������ɳɳ
�����죬ȴ������һ˿�ҳ���
LONG);
        set("outdoors", "������");
        set("exits", ([                           
               "west" : __DIR__"men1",
               "east" : __DIR__"men3",
               "north" : __DIR__"ta2",
               "southwest"  : __DIR__"yaoshidian",
        ]));
        set("coor/x",-330);
  set("coor/y",-320);
   set("coor/z",30);
   setup();
}