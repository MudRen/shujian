// Modify By River 98/12
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"ɽ��С·"NOR);
        set("long", @LONG
������ɽ�ϵ�һ��С���ϣ�����ʮ�ֻ�Ƨ���㲻�ϵĲ�������·�ϵ��Ӳݣ�
������ż������һ�����Ұ�޽�����ͷ����һЩ��֪����С����������ȥ����
�ܴ����ܲ����ʻ��̲��������֡�
LONG);
        set("outdoors", "����");
        set("exits", ([             
               "westdown" : __DIR__"road1",   
               "eastup" : __DIR__"road3",   
               ]));

        set("coor/x",-250);
  set("coor/y",-410);
   set("coor/z",-10);
   setup();
}
