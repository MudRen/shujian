#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", GRN"����Ժ"NOR);
        set("long", @LONG
����һ����ֲ�����СԺ�ӣ�����һ��С·ͨ����ɽ�ϣ���ʯ��
���ɨ�÷ǳ��ɾ�����紵����ֻ������Ҷ���Ʈ��������ɳɳ����
�죬ȴ������һ˿�ҳ�����������һ��С����
LONG);
        set("outdoors", "������");
        set("exits", ([                           
               "south" : __DIR__"ta1",
               "northup" : __DIR__"road4",
               "west" : __DIR__"gmd",
               "east" : __DIR__"xmd",
        ]));
        set("coor/x",-350);
  set("coor/y",-290);
   set("coor/z",20);
   setup();
}