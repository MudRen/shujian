// /area/jiangbei/wudang/langmei.c ��÷��
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIG"��÷��"NOR);
        set("long", @LONG
��÷��λ��ͨ���𶥵�·�ϣ��䵱��÷�����������ʿ��������÷������
��ͥ���õ��˻ʵ��ʹ͡��ʵ���Ϊ����÷����Ǹ������ס����������۶���
�ǻ���λ������������������ʱ��������һ��÷֦���������ϣ�˵��������
���ɣ����������������������Ȼ�õ��ɹ���÷֦��������Ҳ���Գɻ
LONG
        );

        set("exits", ([
                "westup" : __DIR__"qtguan",
                "northwest" : __DIR__"yxyan",
                "east" : __DIR__"shanlu2",
                "northdown" : __DIR__"gsdao5",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/youke" : 1,
        ]));

        set("outdoors", "�䵱");

        setup();
}
