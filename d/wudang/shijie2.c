// /d/wudang/shijie2.c ʯ��
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", CYN"ʯ��"NOR);
        set("long", @LONG
������һ����ʵ��ʯ���ϣ���ʱ�������˻����ʹ��������߹���һ��
�����£�һ�����ͱڣ�̧ͷ��Լ�ɼ�ɽ���Ƶ������壬ɽ����棬����������
�����Ŀ�����������ǰ����չ����ˡ�
LONG
        );
        set("exits", ([
                "southup" : __DIR__"zhanqi",
                "eastdown" :__DIR__"fuzhen",
        ]));

        set("objects",([
                __DIR__"npc/jxk" : random(2)+1,
        ]));

        set("outdoors","�䵱");        
        setup();
}
