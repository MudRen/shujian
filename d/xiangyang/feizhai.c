// /d/xiangyang/feizhai.c ��լ
// Lklv 2001.9.26

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "��լ");
        set("long", @LONG
����һ���ķϵ�լԺ��Ժ���ﳤ������ݺͲ�֪���ĸ��ֵͰ���ľ�ԡ���
���Ļ���ǽ�ưܲ����������深�����ֵĽֵ��γ������ĶԱȡ�����ƽ��û��
ʲô���������˽л�������Ϣ�ĵط���
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("exits", ([
                "west" : __DIR__"dcx1",
        ]));
        set("objects", ([
		CLASS_D("gaibang/xuxiaowu") : 1,
		CLASS_D("gaibang/xiang") : 1,
        ]));
        set("incity",1);
	setup();
}
