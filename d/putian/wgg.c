// Room: /d/putian/wgg.c �书��
// lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�书��");
        set("long", @LONG
�������书������ط��ܴ󣬵��������Ŵ�����ʯ��ש���ĽǸ���һ
�������ӣ����߷��ű����ܣ����ϰ����˸��ֱ�����������Ŀ����׳����ɮ
�������䡣
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"dc-dian",
        ]));

        set("objects",([
                __DIR__"npc/wuseng" : 2,
                CLASS_D("putian") + "/yuanbei" : 1,
        ]));
        setup();
}
