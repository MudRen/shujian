#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�յ�");
        set("long", @LONG
����һƬ����ǰ�Ŀյأ��Ա߷���Щ�����ܡ�ɳ���Լ�����ľ׮����
��������Ʈ�����Ҷ�͸ɲݡ��Ա���һ��ˮ����һ��ˮư����ˮ�峺��ɢ
�������������������Ǽ���䴢���ҡ�
LONG);
        set("resource/water", 1);
        set("exits", ([
              "southdown" : __DIR__"shanmen",
              "west" : __DIR__"chucang",
              "northup" : __DIR__"tangwu",
        ]));
        set("drink_msg", "$N��ˮưҨ��һ������ľ�ˮ�ȡ�\n");
        set("outdoors", "����ɽ");
        setup(); 
}

