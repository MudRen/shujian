// /area/jiangbei/wudang/zhenqing.c �������칬
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"�������칬"NOR);
        set("long", @LONG
�����ң��ʢ���Ľ�����һ��ʯ��С��������칬������˵�������
����������������ϵ�ס���ͽС��������칬������Ȼ������ʯ�������ͽ
�����˼�Ϊ�����۶�����ġ����칬��ʯ���ϻ���һ���ŵ������ν�����
�˳������١�  
LONG
        );

        set("exits", ([
                "southup" : __DIR__"gsdao4",
                "enter" : __DIR__"sanqing",
                "southwest" : __DIR__"feisheng",
                "north" : __DIR__"gchang",
        ]));

        set("no_clean_up", 0);

        set("objects",([
              CLASS_D("wudang")+"/moshenggu" : 1,
              __DIR__"npc/daotong" :2,
        ]));

        set("outdoors", "�䵱");

        setup();
}
