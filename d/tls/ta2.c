#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"���౦��"NOR);
        set("long",@LONG
��ʥ�������������࣬�߶�����ߣ��˽�ʮ�㣬��Ϊʵ�ģ�����
�ֱ����衢���������ȣ�����ׯ�ء��������뿪���裬���ð�ɫ
����ʯ����һ��
LONG);
        set("outdoors", "������");
        set("exits", ([
                "south" : __DIR__"yz4",
        ]));	
        set("coor/x",-330);
  set("coor/y",-310);
   set("coor/z",30);
   setup();
}
