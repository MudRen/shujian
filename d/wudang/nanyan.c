// /area/jiangbei/wudang/nanyan.c ��ʥ���ҹ�
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"��ʥ���ҹ�"NOR);
        set("long", @LONG
���ң������������ҡ������������Ϸ����ʳ������ҡ�����ȫ���Ǵ�ʥ��
�ҹ����ݼ��أ����Ƴ�������֮һ�������������������޵������ﻹ��������
��һ��ʫ��ʷ��ʢ�������ǡ����е�ͥ������Ϧ�ƣ�ɽ�����𡱡��������ϣ�
����ĵƻ���˱����ɫ�ľ��ۡ�        
LONG
        );

        set("exits", ([
                "south" : __DIR__"gchang",
                "northdown" : __DIR__"zixia",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                CLASS_D("wudang")+ "/chenyun" : 1,
               __DIR__"npc/daotong" : 2,
        ]));

        set("outdoors", "�䵱");

        setup();
}
