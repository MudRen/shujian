// /d/wudang/caihong.c �ʺ�(ʯ��)
// by ydh and shang

inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", HIM"���ʺ�"NOR);
        set("long", @LONG
������ɽ���У������ǾŶɽ�������������֮ˮ���ڴ˽��㣬Ȼ��ͻȻ��
к����ע��ɽ���γ�׳�۵��ٲ���һ����Ȼʯ�����������Զ���ۿ�����һ��
���ʺ硣�����Ͼ��Ƕ��͵�ʮ�����ˡ�
LONG
        );

        set("exits", ([
                "southup" : __DIR__"shibapan",
                "northup" : __DIR__"wangbei",
        ]));
        set("objects",([
               __DIR__"npc/youke" : 1,
        ]));

        set("no_clean_up", 0);

        set("outdoors", "�䵱");

        setup();
}
