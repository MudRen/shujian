// Room: /u/xdd/gumu/shanlu3.c
// Modify By River 98/08
#include <ansi.h>

inherit ROOM;

void create()
{
     set("short", YEL"ɽ·"NOR);
     set("long", @LONG
�������У��˴���ɽ·�Ե����ж��ͣ�·����������һ��ʯ��(shibei)��
Զ����ȥ���ɼ�������������������ȫ������֮�������𴦻��ив����Ϳ���
��ʾ䡣
LONG        );

     set("outdoors","��Ĺ");

     set("exits", ([
         "eastup" : __DIR__"ztm",
         "northdown" : __DIR__"shanlu2",
     ]));

     set("item_desc", ([
             "shibei" : HIW"\n\t\t��Բ�������������Ϊ��������ࣿ \n"+
                           "\t\t������ҹ����٣�������������� \n"+
                           "\t\t�������첻Ӧ��һ��ϸ�������Ρ� \n"+
                           "\t\t���ô�ǧ�����磬������������顣 \n"NOR,
     ]));

     set("coor/x",-10);
  set("coor/y",-10);
   set("coor/z",30);
   setup();
}
