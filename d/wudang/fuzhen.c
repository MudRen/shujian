// /area/jiangbei/wudang/fuzhen.c �����
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"�����"NOR);
        set("long", @LONG
�����������̫���¡����ഫ�Ǿ��ֹ���̫�ӣ�Ҳ���Ǻ�����������ʮ
�������䵱ɽ����ʱ�����ס�ĵط�����������־�����ڷ��ؼҵ�;�У�����
��Ԫ���á�����ĥ�롱�㻯��������ɽ�����������������۵ġ�
LONG
        );

        set("exits", ([
                "west" : __DIR__"laojun",
                "westup" : __DIR__"shijie2",
                "northdown" : __DIR__"shibapan",
        ]));

        set("objects",([
               __DIR__"npc/daotong" : 2,
               CLASS_D("wudang") + "/guxu" : 1,
        ]));

        set("no_clean_up", 0);

        set("outdoors", "�䵱");

        setup();
}
