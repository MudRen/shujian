// Room: /d/putian/lhtang.c �޺���
// lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�޺���");
        set("long", @LONG
�������޺��ã���ǰ��һ���ܴ��Ժ�䣬��Χ�ø�ǽΧס��Ժ���Ҷ���д
�š��޺��á��������֡����������ֵ�����ϰ���Ż����书�����ڡ��кܶ���
���ɮ�˽���������Ժ�ڴ����������������������
LONG
        );

        set("exits", ([
                "east" : __DIR__"dc-dian",
        ]));

        set("objects",([
                __DIR__"npc/wuseng" : 2,
                CLASS_D("putian") + "/yuantong" : 1,
        ]));

        setup();
}
