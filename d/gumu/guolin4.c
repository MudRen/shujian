// guolin4.c By River 98/09
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
             "west" : __FILE__,
             "east" : __DIR__"huacong",
             "north" : __FILE__,
             "south" : __FILE__,
       ]));

       setup();
}
