// /area/jiangbei/wudang/mozhen.c ĥ�뾮
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"ĥ�뾮"NOR);
        set("long", @LONG
�����Ӹ����£�ÿ��̫���������������Ƚ��ɵ���һ�����������ֳơ���
���������ഫ�����Ǿ��ֹ�̫�ӣ�ʮ�������䵱ɽ�޵�������ɽ���������˼�
ʮ����δ�ɣ��Ļ����䣬�����������ף��ߵ��������Ů������Ԫ������
��̫��������ĥ��㻯����ʹ�����������ĥ���룬������Ȼ�ɡ��ĵ�����
�ַ�����ɽ������
LONG
        );

        set("exits", ([
                "southup" : __DIR__"wangbei",
                "eastup" : __DIR__"yuxuyan",
                "northdown" : __DIR__"yuxu",
        ]));
        set("objects",([
               __DIR__"npc/youke" : 1,
        ]));

        set("no_clean_up", 0);

        set("outdoors", "�䵱");

        setup();
}
