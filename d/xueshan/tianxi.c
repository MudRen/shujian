//  /d/xueshan/river.c ��Ϫ
// by hunthu
#include <ansi.h>

inherit ROOM;

#include <room.h>
void create()
{
        set("short","��Ϫ");
        set("long",@LONG 
һ��СϪ�������������Ÿ�����ѩ���������죬��Ϫˮ���Ѷ���
���ƽ��ߣ��������Ƕ��͵�ɽ�壬ɽ�ϰ�ѩ������
LONG);
        set("exits",([
  "south" : __DIR__"tianhu", 
        ]));
        setup();
 set("coor/x",-250);
set("coor/y",150);
   set("coor/z",0);
   setup();

}
