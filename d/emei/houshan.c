// houshan.c
// ��ɽ
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG "��ɽ" NOR);
        set("long", @long
�����Ƕ��Һ�ɽ�ϵ�һ��յأ�������һƬ�ɲĵ����֣���������һ����
����̿��̿Ҥ�����ڶ����ɵش����䣬������һЩ�׼ҵ�����������̿��
long);
        set("outdoors", "��üɽ");
        set("exits",([
             "southup":__DIR__"houshanxl2",
             "east":__DIR__"houshansl",
             "northeast":__DIR__"houshanty",
]));
        setup();
}
