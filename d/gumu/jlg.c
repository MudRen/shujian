// Room: /u/xdd/gumu/jlg.c
// Modify By River 98/08
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short",HIC"������"NOR);
        set("long", @LONG
��������ȫ���Ϊ������ʿ�ͽ������׼����ˮ����ʳ�ĵط����ɹ���ɽ
�����������˸��ڱ��γ��꣬���ڽ���ȫ��Ķ�ʢ���������һ�£���
��һ���߲ʽ�����׿Ȼ���ԡ�
LONG);

        set("outdoors","��Ĺ");

        set("exits", ([
                "northup" : __DIR__"ztm",
                "southup" : __DIR__"ryy",
        ]));
        set("no_fight",1);
        set("objects", ([
                __DIR__"qqll/mayu" : 1,
//                        __DIR__"npc/qiu" : 1,
        ]));
        set("coor/x",0);
        set("coor/y",-20);
        set("coor/z",30);
//        set("objects", ([
//                "/d/gumu/npc/mayu" : 1,
//        ]));
        setup();
}
