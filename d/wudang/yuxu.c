// /area/jiangbei/wudang/yuxu.c ���鹬
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"���鹬"NOR);
        set("long", @LONG
�䵱ɽ����Ĺ�ģ���Ļʼ���ۣ������鹬������������Ⱥ��������
����鹬�ǳ����׳ǣ��������ǣ������ֳǣ����ֳǺ��Ͻ�ǡ����Ƕ�����
��ǽ�����Χ���γɵȼ���������ģ���Ĺ��ǡ����������鹬�ֵõ��˴��
ģ��������������ȥ���ɽ����̣������Իͣ����ޱ߼ʡ�
LONG
        );

        set("exits", ([
                "southup" : __DIR__"mozhen",
                "eastdown" : __DIR__"shanlu1",
        ]));

        set("objects",([
                __DIR__"npc/daotong" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "�䵱");

        setup();
}
