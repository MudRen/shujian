// /area/jiangbei/wudang/yuanhe.c Ԫ�͹�
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"Ԫ�͹�"NOR);
        set("long", @LONG
Ԫ�͹����䵱ɽ�������Ź�����ϵĵ�һ�����ۡ��ݵ��ؼ��أ������ϵ�
�����õ������ƹܡ�Ԫ��ǨУ����������������ȡ����Ԫ�͹ۡ������Ǩ��
�Ƿ������˼��У����ָ�������̾ߡ���ʵ�ϣ�Ԫ�͹����䵱�ɴ���Υ�����
���ɵ��䵱���ӵĻ�����
LONG
        );

        set("exits", ([
                "southup" : __DIR__"gsdao2",
                "northdown" : __DIR__"gsdao1",
                "east" : __DIR__"yuanhe1",
        ]));

        set("objects",([
                __DIR__"npc/daotong" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "�䵱");

        setup();
}
