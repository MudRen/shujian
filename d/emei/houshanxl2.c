// houshanxl2.c
// ��ɽС·
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIG "��ɽС·" NOR);
        set("long", @long
�����Ƕ��Һ�ɽ�ϵ�ɽ��С·���������һ����ɫ�������Ѿ��������ɸ�
ɽ֮�ۣ������ǱȽϺ���ġ�
long);
        set("outdoors", "��üɽ");
        set("exits",([
             "southwest":__DIR__"houshanxl",
             "northdown":__DIR__"houshan",
]));
        setup();
}
