// Room: /d/putian/dmyuan.c ��ĦԺ
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"��ĦԺ"NOR);
        set("long", @LONG
�����Ǵ�ĦԺ��������԰����˹�������¯�����š���Ϊ�������صأ���
��ƽ��������������˿��Խ��룬��ĦԺ����ɮƽ��Ҳ����㣬ͬʱ���Ǹ�
��Ѳ�ߡ��������и���Ҫ�ص����Ρ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"mf-dian",
        ]));

        set("objects",([
                CLASS_D("putian") + "/tian-jing" : 1,
                __DIR__"npc/wuseng" : 4,
        ]));

        setup();
}
