// guolin3.c By River 98/09
#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIG"����"NOR);
       set("long",@LONG
ת��ɽ��������һ��Ƭ���֡������ߴ�ïʢ��֦Ҷ���ܣ������ʹ�������
���ˡ�����Ҷ��ɳɳ���죬������Ⱥ�������ҡ���裬����������㡣����
��������ž��������䡣
LONG );

       set("outdoors","��Ĺ");

       set("exits" ,([
             "east" : __FILE__,
             "south" : __DIR__"guolin4",
             "west" : __FILE__,
             "north" : __FILE__,
       ]));

       setup();
}
