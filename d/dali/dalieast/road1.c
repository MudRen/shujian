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
               "southwest" : __DIR__"shanlu7",
               "eastup" : __DIR__"road2",   
               ]));

        set("coor/x",-260);
  set("coor/y",-410);
   set("coor/z",-20);
   setup();
}
