#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", YEL"�ɹ�Ӫ��"NOR);
                set("long", @LONG
�����ɹŹ�����������ʱ��Ӫ��Ӫ���м��������ſ��׵Ľ���������ȥ��
�ں�һ��������������ıʿ���˴�����̸�ۡ���ִ��ʲô��Ӫ�����м���ʿ��
��Ѳ�ߡ�
LONG
        );

        set("no_save", 1);
        set("outdoors", "����");
        

        set("objects", ([
           //     NPC_D("guanfu/wujiang") : 1,
            //    NPC_D("guanfu/bing") : 2,
        ]));
       
        set("incity",1);
        setup();
}
