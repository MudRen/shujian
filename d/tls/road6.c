#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"��ʯ��"NOR);
        set("long", @LONG
��������ɽ������һ��ʯ��·�����õ��ɽ���еİ�ʯ���ɣ�
·�ܶ����ա�����������£�һ���紵�����㲻�ɵĻ��˼��Σ�
�ų�һ���亹��
LONG);
        set("outdoors", "������");
        set("exits", ([             
               "southdown" : __DIR__"dmg",               
        ]));
        set("coor/x",-360);
  set("coor/y",-270);
   set("coor/z",30);
   setup();
}