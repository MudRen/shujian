// houshanxl.c
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
             "northeast":__DIR__"houshanxl2",
]));
        setup();
}
