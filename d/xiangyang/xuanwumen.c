// /d/xiangyang/xuanwumen.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
        set("short", YEL"������"NOR);
        set("long", @LONG
�����Ǿ������������ǵı��ţ���ʱ���ж�����׵�ʿ��������ȥ����
���Խ������������Ͼ��ڣ�����ȥ�ι��������䵱ɽ�����ŵ�ǽ��������һֽ
��ʾ(gaoshi)��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("objects", ([
                CLASS_D("gaibang/guojing") : 1,
                NPC_D("guanfu/wujiang") : 1,
//                "d/xiangyang/npc/yangguo" : 1,
                NPC_D("guanfu/bing") : 2,
	]));
        set("exits", ([
                "north" : __DIR__"outnroad1",
                "south" : __DIR__"nroad1",
        ]));

	set("incity",1);
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n��������ʹ\n���ĵ�\n";
}

