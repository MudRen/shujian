// /area/jiangbei/wudang/feisheng.c ������
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", CYN"������"NOR);
        set("long", @LONG
������һ��ͻ��������ڣ�ɽ������һ��С·ֱ����ۣ�Ծ����������
����ʮ���峯�󶥵�ʤ�������������ഫ������������ʱ���ڴ�����������
����ʮ�꣬����ž����������ɣ����������ͷ����������˿��������������
�������ڴ������ͷ����Ĵ�˵�����⽨���ˡ���ױ̨����
LONG
        );

        set("exits", ([
                "northeast" : __DIR__"zhenqing",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/youke" : random(2) + 1,
        ]));

        set("outdoors", "�䵱");

        setup();
}
