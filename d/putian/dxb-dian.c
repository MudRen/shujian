// Room: /d/putian/dxb-dian.c
// Lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIY"���۱���"NOR);
        set("long", @LONG
�����Ǵ��۱�����м乩�������������Ľ����������Ҹ������⡢��
����λ������������ܵ�ǽ���ϻ������𾭵�ʵıڻ�����ͼ��ΰ��ɫ��Ѥ
��������һ���ļ���𲻶ϣ�һȺɮ�����Է����о���
LONG
        );

        set("exits", ([
                "northdown" : __DIR__"guangchang",
                "southdown" : __DIR__"qiandian",
        ]));
        set("objects",([
                __DIR__"npc/shami" : 2,
                CLASS_D("putian") + "/da-ku": 1,
        ]));
        setup();
}
