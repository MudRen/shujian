// /d/xiangyang/zhuquemen.c

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
        set("short", YEL"��ȸ��"NOR);
        set("long", @LONG
�����Ǿ������������ǵ����ţ���Ϊ�����ս����Զ�������Ե÷�������
�öࡣ���ϳ��ǿ���ȥ���ϡ����ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("exits", ([
                "north" : __DIR__"zqmnj",
                "south" : __DIR__"outsroad1",
        ]));

        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
	]));

	set("incity",1);
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n��������ʹ\n���ĵ�\n";
}
