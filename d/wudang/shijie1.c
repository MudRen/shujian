// /d/wudang/shijie1.c ʯ��
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", CYN"ʯ��"NOR);
        set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ�������˻����ʹ��������߹���һ��
�����£�һ�����ͱڣ�̧ͷ��Լ�ɼ�ɽ���Ƶ������壬ɽ����棬����������
�����Ŀ�������
LONG
        );
        set("exits", ([
                "southup" : __DIR__"gsdao1",
                "northdown" :__DIR__"xuanyue",
        ]));

        set("objects",([
               __DIR__"npc/daotong" : 1,
        ]));

        set("outdoors","�䵱");
        setup();
}
