// /area/jiangbei/wudang/taihe.c ����̫�͹�
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"����̫�͹�"NOR);
        set("long", @LONG
����̫�͹������ڷ幰�С�ֱ���������䵱��߷塪��������ľ����ϡ�
�䵱ɽ����ĵ�ò�γɵ��ڷ幰�С��˷����ݵľ���Ҳ�������Ⱦ����Ȩ����
�����ϡ�����̫�͹����䵱ɽ�����ʤ���������ǵ�����ʿ������������ˣ�
ֻ�е��϶��壬�߽�̫�͹����������������ϵĵ����䵱ɽ��
LONG
        );

        set("exits", ([
                "west" : __DIR__"jindian",
                "northdown" : __DIR__"hldong",
        ]));

        set("no_clean_up", 0);

        set("objects",([
               __DIR__"npc/daotong" : 1,
        ]));

        set("outdoors", "�䵱");

        setup();
}
