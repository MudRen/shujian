#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"����Ժ"NOR);
        set("long", @LONG
����һ����ֲ�����СԺ�ӣ�����һ��С·ͨ��ǧѰ��������ʯ
�����ɨ�÷ǳ��ɾ�����紵����ֻ������Ҷ���Ʈ��������ɳɳ��
���죬ȴ������һ˿�ҳ�����������һ��С����
LONG);
        set("outdoors", "������");
        set("exits", ([                           
               "southup" : __DIR__"gfd",
               "north" : __DIR__"ta1",
               "east" : __DIR__"ytd",
               "west" : __DIR__"sjt",
        ]));
        set("coor/x",-350);
  set("coor/y",-310);
   set("coor/z",20);
   setup();
}