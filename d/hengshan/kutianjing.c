// Room: /d/hengshan/kutianjing.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
����������½ǣ��ж�����಻�����ߣ���ˮ��һ��һ�𣬳�Ϊ���𾮡�
����ˮζ��䣸��𣬵��ҵ��ӷ�Ϊʥˮ�����˵��ˣ�ÿ�пڿ��������ˮ
ȷ����������֮�档
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "west"  : __DIR__"beiyuemiao",
        ]));
        set("resource/water", 1);
        set("outdoors", "��ɽ");
        setup();
}
