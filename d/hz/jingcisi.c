// /u/beyond/hangzhou/jingcisi.c ������
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",HIW"������"NOR);
        set("long", @LONG
��������ǰ���У���������м�Ĵ��۱�����Ϊ׳�ۡ����۱����
�����㣬��ɫ�������ݶ����ر��Եľ�����ΰ�����ȵ������ڲ���ĺ���л�
�������ﶯ�������������ʮ��֮һ���������ӡ���������
LONG
);
set("objects",([
__DIR__"npc/you1" : 2,
]));
        set("exits", ([
"southeast" : __DIR__"yuhuang",
"northwest" : __DIR__"hubian1",
]));
        set("coor/x",110);
  set("coor/y",-360);
   set("coor/z",0);
   setup();
}
