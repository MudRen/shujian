// /u/beyond/hz/tianwangdian.c ������
#include <ansi.h>
 
inherit ROOM;
void create()
{
        set("short",HIY"������"NOR);
        set("long", @LONG
���������ƻֺ꣬�����Ϸ��������ʡ��������¡��͡����շ���������
���ҡ����������Ǵ�����շ�ϲӭ������͡����ձ�����Դ��۱����
��Τ������������������ƷǷ����Ĵ�������Τ�Ժ��Ĵ��������ǽ�ħ����
�Ļ�����
LONG
        );
        set("exits", ([
"east" : __DIR__"lingyinsi",
            "north" : __DIR__"dxbdian",
                        
]));
        setup();
}
