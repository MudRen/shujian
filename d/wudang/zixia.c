// /area/jiangbei/wudang/zixia.c ������
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"������"NOR);
        set("long", @LONG
��ģ������ư�������������������䵱ɽչ����¡�����Ⱥ��ɽ�뻷
�ƣ����ִ������������ţ��������ˣ���������Ϊ���������ء���������
��������������䡣�λ�����٥һ�����Σ��μ��ˡ����񡱣���һ��ʿΪ��Բ
�Σ�˵Ҫ��ˮ���Ϸ�ѹ�򣬲������ǡ�����ѡ������ʮ������֮һ���䵱ɽ��
��չ�����Ϊˮ�����佨��������������Ͷ����Ԫʥ������ 
LONG
        );

        set("exits", ([
                "out" : __DIR__"zxgdamen",
                "southup" : __DIR__"nanyan",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                CLASS_D("wudang")+ "/wanqing" : 1,
                __DIR__"npc/daotong" :2,
        ]));

        set("outdoors", "�䵱");

        setup();
}
