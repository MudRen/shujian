#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ס����"NOR);
        set("long",@LONG
��ʥ������������ס���߶�����ߣ��˽�ʮ�㣬��Ϊʵ�ģ�����
�ֱ����衢���������ȣ�����ׯ�ء��������뿪���裬���ð�ɫ
����ʯ����һ��
LONG);
        set("outdoors", "������");
        set("exits", ([
                "south" : __DIR__"yz5",
        ]));	
        set("coor/x",-370);
  set("coor/y",-310);
   set("coor/z",20);
   setup();
}
