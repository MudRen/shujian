#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"Ӧ�ַ���"NOR);
        set("long", @LONG
������ǵ��ɽ��߷�Ӧ�ַ壬ɽ��ֱ����ϼ����ΰ׳�����������
������ɽ���������겻���Ļ�ѩ��ԶԶ��ȥ�������ɫ��ڣ����������
�ġ���ɽѩ������
LONG);
        set("outdoors", "dali");

        set("exits", ([             
             "northup" : __DIR__"ylf",
                "south": __DIR__"dc1",
        ]));

        set("coor/x",-350);
  set("coor/y",-400);
   set("coor/z",20);
   setup();
}
void init()
{
            object me = this_player();
     if(me->query_temp("xuncheng"))
     {
       me->set_temp("dali_xc/ylf1",1);
      }
}


