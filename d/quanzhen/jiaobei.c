// jiaobei.c �̱�
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�̱�");
        set("long", @LONG
������ȫ��̵Ḻ̌����ڵأ�·������һ���(bei)���������߾���������
���ĵ�����������--ȫ��̵Ĵ����ˡ�������һ��ʯ�ף���֪��ͨ���������
����ɽ��·��
LONG );
        set("outdoors", "quanzhen");
        set("exits", ([
                "south"   : "/d/quanzhen/dajiaochang",
                "northup" : "/d/quanzhen/shijie6",
                "eastup" : "/d/quanzhen/damen",
                "west" : "/d/quanzhen/shijianyan",
        ]));
        set("item_desc", ([
        "bei": CYN"
        ����������
������������������
������������ȫ����
������������������
�������������桡��
������������������
�������������š���
������������������
�������������̡���
������������������
������������������
\n"NOR
        ]) );
        set("objects",([
               CLASS_D("quanzhen") + "/zhou" : 1,
        ]));

        setup();
        replace_program(ROOM);
}


