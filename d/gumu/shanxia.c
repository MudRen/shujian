// shanxia.c By River 98/09

inherit ROOM;
#include <ansi.h>
int get_object(object ob);
void create()
{
        set("short", HIG"����ɽ��"NOR);
        set("long", @LONG
����������ɽ�£�����һƬ��ţ�ֻ��Ȫ����������˼���������ɽʯ
��ᾣ���ľï�ܣ�����֮�����ࡣ�ڲ�Զ���Ĺ�ľ���У�����ԼԼ�ĺ����и�
Сɽ��(dong)��
LONG
        );

        set("item_desc", ([
           "dong" : HIB"һ���ں�����С������֪��ͨ�����\n"NOR,
        ]));

        set("outdoors","��Ĺ");

        set("exits", ([
                "northwest" : __DIR__"xiaolu3",
                "northup" : "/d/quanzhen/shijie1",
                "enter" : __DIR__"dongkou",
        ]));
    
        set("coor/x",0);
  set("coor/y",10);
   set("coor/z",0);
   setup();
}
