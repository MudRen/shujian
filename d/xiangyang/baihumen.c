// /d/xiangyang/baihumen.c �׻���
// Lklv Modify 2001.9.22

#include <ansi.h>
inherit ROOM;
string look_gaoshi();

void create()
{
	set("short", YEL"�׻���"NOR);
        set("long", @LONG
�����Ǿ������������ǵ����ţ��ɴ����������Ĵ����ƹ󡣲�ʱ���ж���
��׵�ʿ��������ȥ���������������ս������������ʧ��������˴�Ƭ�Ļ�
�أ�����ϡ�١����ŵ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
        );
        set("outdoors", "����");
        set("xyjob", 1);
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
        set("exits", ([
                "west" : __DIR__"outwroad1",
                "east" : __DIR__"bhmnj",
        ]));
        set("incity",1);
	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n��������ʹ\n���ĵ�\n";
}
