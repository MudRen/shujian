// /u/beyond/hz/fangheting.c �ź�ͤ
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�ź�ͤ"NOR);
        set("long", @LONG
�ź�ͤ�ڹ�ɽ���棬��˵��Ϊ�˼��������ʫ���ֺ;������������
ϲ�����ӣ�ƽ�ճ�����ʫ������,ϲ����÷���ף����С�÷�޺��ӡ�֮˵����
����ɽ԰С÷������Ӱ��бˮ��ǳ�����㸡���»ƻ衱�����������˿ڣ�
��ӽ���ǡ�
LONG
        );
set("objects",([
__DIR__"npc/you" : 2,
]));
        set("exits", ([
            "south" : __DIR__"gushan",
]));
        set("coor/x",70);
  set("coor/y",-340);
   set("coor/z",0);
   setup();
}
