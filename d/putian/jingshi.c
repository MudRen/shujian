// Room: /d/putian/jingshi.c ����
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
ССһ�侲�ң������·��������ʦ�����������ϣ���ǰ����С��������
С��¯��̴����������������������Ϲ���һ������ĺ�ɽʰ��ͼ�����Ȳ���
���ʣ�ȴ������λ��ɮ�������
LONG
        );

        set("exits", ([
                "north" : __DIR__"jcyuan",
        ]));

        set("objects",([
                CLASS_D("putian") + "/tian-hong" : 1,
        ]));

        setup();
}
