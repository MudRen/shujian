// Room: /d/putian/qiandian.c ǰ��
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"ǰ��"NOR);
        set("long", @LONG
�������е�ǰ���������ܴ�ܿ�������������һ����ɫ�ķ�ש������
�ط��ķ�ש��Щ��ƽ����ϸ���ܿ��������ӡ��״�İ��ݡ������Ǹߴ�Ĵ���
��������ļⶥ�����������Ź⡣�������еһ��ʯ��·ͨ���Ժ��
LONG
        );

        set("exits", ([
                "northup" : __DIR__"dxb-dian",
                "south" : __DIR__"zhongdian",

        ]));
        set("objects",([
        	__DIR__"npc/wuseng" : 1,
        ]));

        setup();
}
