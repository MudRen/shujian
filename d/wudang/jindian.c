// /area/jiangbei/wudang/jindian.c ���
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"���"NOR);
        set("long", @LONG
���������嶥�ˣ����䵱ɽ��������Ҳ���䵱�����ڻ��ҷ���������
��ʢ�Ľ����ͭ���̽�Ľ��Ϊ�����е�ʽ��ľ�ṹ���������̽�ͺĻƽ�ǧ
�������䵱ɽ�ȼ���ߵĹŽ������������������Ϊ���䣬�����ϵ����Ŷ
�ʼ������������������Ƕ��ţ����Ƿɾ٣����������������������
���������� 
LONG
        );

        set("exits", ([
                "east" : __DIR__"taihe",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/jxk" : 1,
        ]));

        setup();
}
